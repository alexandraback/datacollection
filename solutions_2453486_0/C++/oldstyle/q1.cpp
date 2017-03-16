//Joe Snider
//4/13
//
//Solve question qual-1 from CodeJam 2013

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool comp(char& x, char& y) {
   if(x=='.' || y=='.') {
      return false;
   }
   return x==y || x=='T' || y=='T';
}

char testBoard(vector<vector<char> >& b) {
   //4 rows
   for(int i = 0; i < 4; ++i) {
      char test = b[0][i];
      if(test == 'T') {
         test = b[1][i];
      }
      if(comp(test, b[0][i]) && comp(test, b[1][i]) && comp(test, b[2][i]) && comp(test, b[3][i])) {
         return test;
      }
   }
   //4 clms
   for(int i = 0; i < 4; ++i) {
      char test = b[i][0];
      if(test == 'T') {
         test = b[i][0];
      }
      if(comp(test, b[i][0]) && comp(test, b[i][1]) && comp(test, b[i][2]) && comp(test, b[i][3])) {
         return test;
      }
   }
   //2 diags
   char test = b[0][0];
   if(test == 'T') {
      test = b[1][1];
   }
   if(comp(test, b[0][0]) && comp(test, b[1][1]) && comp(test, b[2][2]) && comp(test, b[3][3])) {
      return test;
   }
   test = b[0][3];
   if(test == 'T') {
      test = b[1][2];
   }
   if(comp(test, b[0][3]) && comp(test, b[1][2]) && comp(test, b[2][1]) && comp(test, b[3][0])) {
      return test;
   }
   return 'q';
}

int main() {
   vector<char> blnk(4);
   vector<vector<char> > board(4, blnk);
   
   //read and dump status at the same time
   ifstream dat("input.txt");
   char m;
   int cases;
   dat >> cases;
   for(int i = 0; i < cases; ++i) {
      bool hasDot = false;
      for(int j = 0; j < 4; ++j) {
         for(int k = 0; k < 4; ++k) {
            dat >> m;
            board[j][k] = m;
            if(m=='.') {
               hasDot = true;
            }
         }
      }
      char t = testBoard(board);
      if(t == 'X' || t == 'O') {
         cout << "Case #" << i+1 << ": " << t << " won\n";
      } else {
         if(hasDot) {
            cout << "Case #" << i+1 << ": Game has not completed\n";
         } else {
            cout << "Case #" << i+1 << ": Draw\n";
         }
      }
      //cout << testBoard(board) << "\n";
   }

   return 0;
}


