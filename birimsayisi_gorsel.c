#include "raylib.h"
#include <stdio.h>

#define GRID_SIZE  10    // Kare sayısı (10x10)
#define CELL_SIZE  70    // Her bir karenin boyutu

int main(void)
{
    // Pencereyi başlat
    InitWindow(GRID_SIZE * CELL_SIZE, GRID_SIZE * CELL_SIZE, "10x10 Grid Üzerinde Görseller");

    // Görselleri yükle
    Texture2D textures[10];
    const char *imagePaths[10] = {
        "C:\\Users\\ungor\\OneDrive\\Resimler\\Saved Pictures\\yeni_piyade.png",
        "C:\\Users\\ungor\\OneDrive\\Resimler\\Saved Pictures\\yeni_okcu.png",
        "C:\\Users\\ungor\\OneDrive\\Resimler\\Saved Pictures\\yeni_suvari.png",
        "C:\\Users\\ungor\\OneDrive\\Resimler\\Saved Pictures\\yeni_kusatma.png",
        "C:\\Users\\ungor\\OneDrive\\Resimler\\Saved Pictures\\yeni_ork.png",
        "C:\\Users\\ungor\\OneDrive\\Resimler\\Saved Pictures\\yeni_mizrak.png",
        "C:\\Users\\ungor\\OneDrive\\Resimler\\Saved Pictures\\yeni_varg.png",
        "C:\\Users\\ungor\\OneDrive\\Resimler\\Saved Pictures\\yeni_troll.png",
        "C:\\Users\\ungor\\OneDrive\\Resimler\\Saved Pictures\\yeni_canavar.png",
        "C:\\Users\\ungor\\OneDrive\\Resimler\\Saved Pictures\\yeni_kahraman.png"
    };

    // Görselleri yükle
    for (int i = 0; i < 10; i++) {
        textures[i] = LoadTexture(imagePaths[i]);
        // Görselin başarılı bir şekilde yüklenip yüklenmediğini kontrol et
        if (textures[i].id == 0) {
            printf("Görsel yüklenemedi: %s\n", imagePaths[i]);
            CloseWindow(); // Pencereyi kapat
            return 1; // Hata durumu
        }
    }

    SetTargetFPS(60);  // FPS ayarla

    while (!WindowShouldClose())  // Pencere kapatılmadığı sürece
    {
        BeginDrawing();
        
        ClearBackground(RAYWHITE); // Arka planı temizle

        // 10x10 grid çizimi
        for (int row = 0; row < GRID_SIZE; row++)
        {
            for (int col = 0; col < GRID_SIZE; col++)
            {
                int x = col * CELL_SIZE;
                int y = row * CELL_SIZE;

                DrawRectangle(x, y, CELL_SIZE, CELL_SIZE, LIGHTGRAY); // Grid hücrelerini çiz
                DrawRectangleLines(x, y, CELL_SIZE, CELL_SIZE, DARKGRAY); // Çizgi ekle
            }
        }

        // insan imparatorlugu 
        DrawTextureEx(textures[0], (Vector2){2 * CELL_SIZE, 2 * CELL_SIZE}, 0.0f, 1.0f, WHITE); 
        DrawText("100", 2 * CELL_SIZE + CELL_SIZE / 4, 2 * CELL_SIZE + CELL_SIZE - 20, 20, BLACK);
        DrawTextureEx(textures[1], (Vector2){2 * CELL_SIZE, 3 * CELL_SIZE}, 0.0f, 1.0f, WHITE); 
        DrawTextureEx(textures[2], (Vector2){2 * CELL_SIZE, 4 * CELL_SIZE}, 0.0f, 1.0f, WHITE); 
        DrawTextureEx(textures[3], (Vector2){2 * CELL_SIZE, 5 * CELL_SIZE}, 0.0f, 1.0f, WHITE); 
        DrawTextureEx(textures[9], (Vector2){1 * CELL_SIZE, 2 * CELL_SIZE}, 0.0f, 1.0f, WHITE); 
        DrawTextureEx(textures[8], (Vector2){1 * CELL_SIZE, 3 * CELL_SIZE}, 0.0f, 1.0f, WHITE);

        //orklar
        DrawTextureEx(textures[4], (Vector2){5 * CELL_SIZE, 2 * CELL_SIZE}, 0.0f, 1.0f, WHITE);
        DrawTextureEx(textures[5], (Vector2){5 * CELL_SIZE, 3 * CELL_SIZE}, 0.0f, 1.0f, WHITE);
        DrawTextureEx(textures[6], (Vector2){5 * CELL_SIZE, 4 * CELL_SIZE}, 0.0f, 1.0f, WHITE);
        DrawTextureEx(textures[7], (Vector2){5 * CELL_SIZE, 5 * CELL_SIZE}, 0.0f, 1.0f, WHITE);
        DrawTextureEx(textures[9], (Vector2){6 * CELL_SIZE, 2 * CELL_SIZE}, 0.0f, 1.0f, WHITE);
        DrawTextureEx(textures[8], (Vector2){6 * CELL_SIZE, 3 * CELL_SIZE}, 0.0f, 1.0f, WHITE);

        EndDrawing();
    }

    // Kaynakları serbest bırak
    for (int i = 0; i < 10; i++) {
        UnloadTexture(textures[i]); // Yüklenen görselleri serbest bırak
    }
    CloseWindow(); // Pencereyi kapat

    return 0;
}
