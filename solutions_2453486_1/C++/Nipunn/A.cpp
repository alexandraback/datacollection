#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

bool won(char arr[5][5], char who) {
   for (int i=0; i<4; i++) {
      bool won1 = true;
      bool won2 = true;
      for (int j=0; j<4; j++) {
         if (arr[i][j] !=  who && arr[i][j] != 'T')
            won1 = false;
         if (arr[j][i] !=  who && arr[j][i] != 'T')
            won2 = false;
      }
      if (won1 || won2)
         return true;
   }

   bool won1 = true;
   bool won2 = true;
   for (int i=0; i<4; i++) {
      if (arr[i][i] !=  who && arr[i][i] != 'T')
         won1 = false;
      if (arr[i][3-i] !=  who && arr[i][3-i] != 'T')
         won2 = false;
   }
   return (won1 || won2);
}

void go() {
   char arr[5][5];
   for (int i=0; i<4; i++)
      cin >> arr[i];

   if (won(arr, 'X'))
      cout << "X won\n";
   else if (won(arr, 'O'))
      cout << "O won\n";
   else {
      bool draw = true;
      for (int i=0; i<4; i++)
         for (int j=0; j<4; j++)
            if (arr[i][j] == '.')
               draw = false;
      if (draw) {
         cout << "Draw\n";
      } else {
         cout << "Game has not completed\n";
      }
   }
}

int main() {
   int T;
   cin >> T;
   for (int i=1; i<=T; i++) {
      cout << "Case #" << i << ": ";
      go();
   }
}
