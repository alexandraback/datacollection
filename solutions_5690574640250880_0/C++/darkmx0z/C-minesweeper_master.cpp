#include <iostream>

char tablero[100][100];

bool con_vecino(int i, int j, char c)
{
   for (int x = -1; x <= 1; ++x) {
      for (int y = -1; y <= 1; ++y) {
         if (tablero[i + x][j + y] == c) {
            return true;     
         }
      }
   }
   
   return false;
}

bool tiene_solucion(int r, int c)
{
   int numerados = 0;
   
   for (int i = 1; i <= r; ++i) {
      for (int j = 1; j <= c; ++j) {
         if (tablero[i][j] == '.' && con_vecino(i, j, '*')) {
            numerados += 1;
            tablero[i][j] = '#';
         }
      }
   }

   int propagados = 0;

   for (int i = 1; i <= r; ++i) {
      for (int j = 1; j <= c; ++j) {
         if (tablero[i][j] == '#' && con_vecino(i, j, '.')) {
            propagados += 1;
         }
      }
   }
   
   for (int i = 1; i <= r; ++i) {
      for (int j = 1; j <= c; ++j) {
         if (tablero[i][j] == '#') {
            tablero[i][j] = '.';
         }
      }
   }
   
   return (numerados <= 1 || propagados == numerados);
}

bool resuelve(int i, int tope, int m, int r, int c)
{
   if (m == 0) {
      return tiene_solucion(r, c);     
   }
   
   if (i > r) {
      return false;
   }
   
   for (int j = 1; j <= std::min(tope, m); ++j) {
      tablero[i][j] = '*';
      
      if (resuelve(i + 1, j, m - j, r, c)) {
         return true;     
      }
   }
   
   for (int j = 1; j <= tope; ++j) {
      tablero[i][j] = '.';
   }
   
   return false;
}

int main( )
{
   int t;
   std::cin >> t;
   
   for (int ti = 0; ti < t; ++ti) {
      int r, c, m;
      std::cin >> r >> c >> m;
      
      for (int i = 0; i < r + 2; ++i) {
         for (int j = 0; j < c + 2; ++j) {
            tablero[i][j] = (1 <= i && i <= r && 1 <= j && j <= c ? '.' : '-');   
         }
      }

      std::cout << "Case #" << ti + 1 << ":\n";

      if (resuelve(1, c, m, r, c)) {
         tablero[r][c] = 'c';

         for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
               std::cout << tablero[i][j];
            }
            
            std::cout << '\n';
         }
      }
      else {
         std::cout << "Impossible\n";     
      }
   }
}
