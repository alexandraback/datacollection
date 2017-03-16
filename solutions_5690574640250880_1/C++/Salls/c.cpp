#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>
#include <iomanip>

using namespace std;

void solve() {
int R,C,M;
cin >> R >> C >> M;
if(R==1) {
   cout << "c";
   for(int i = 1; i < C-M; i++)
      cout << ".";
   for(int i = C-M; i < C; i++)
      cout << "*";
   cout << endl;
   return;
}
if(C==1) {
   cout << "c" << endl;
   for(int i = 1; i < R-M; i++)
      cout << "." << endl;
   for(int i = R-M; i < R; i++)
      cout << "*" << endl;
   return;
}

int free = R*C-M;
if(free == 1) {
   for(int i = 0; i < R; i++){
      for(int j = 0; j < C; j++){
         if(i==0 && j ==0)
            cout <<"c";
         else
            cout <<"*";
      }
      cout << endl;
   }
return;
}
if(M == 0) {
   for(int i = 0; i < R; i++){
      for(int j = 0; j < C; j++){
         if(i==0 && j ==0)
            cout <<"c";
         else
            cout <<".";
      }
      cout << endl;
   }
return;
}

if(free < 4 || free == 5 || free == 7){
   cout << "Impossible" << endl;
   return;
}
if((R == 2 || C == 2) && free%2 == 1){
   cout << "Impossible" << endl;
   return;
}
else if(R == 2){
   int len = free/2;
   for(int i = 0; i < R; i++) {
      for(int j = 0; j < C; j++) {
         if(i==0 && j ==0)
            cout << 'c';
         else if(j < len)
            cout << '.';
         else
            cout << '*';
      }
      cout << endl;
   }
   return;
}



int rowlen = min((free-2)/2, C);
if(rowlen == 1)
   rowlen = 2;

int numRows = free/rowlen;

if(numRows > R || (numRows==R && free%rowlen != 0) || numRows == 1 || rowlen == 1 || (numRows == 2 && free%rowlen == 1)){
   cout <<"ERROR" << endl;
   cout << R << " " << C << " " << M << endl;
   cout << rowlen << " " << free << endl;
   exit(0);
}

for(int i = 0; i < numRows - 1; i++) {
   for(int j = 0; j < C; j++) {
      if(i==0 && j ==0)
         cout << 'c';
      else if(j < rowlen)
         cout << '.';
      else
         cout << '*';
   }
   cout << endl;
}

int remainder = free%rowlen;
if(remainder == 1) {
   rowlen--;
   remainder++;
}

for(int i = numRows-1; i < numRows; i++) {
   for(int j = 0; j < C; j++) {
      if(i==0 && j ==0)
         cout << 'c';
      else if(j < rowlen)
         cout << '.';
      else
         cout << '*';
   }
   cout << endl;
}
if(remainder > 0){
   numRows++;
   for(int j = 0; j < C; j++) {
      if(j < remainder)
         cout << '.';
      else
         cout << '*';
   }
   cout << endl;
}
for(int i = numRows; i < R; i++) {
   for(int j = 0; j < C; j++) {
      cout << '*';
   }
   cout << endl;
}

}

int main() {

int t;
cin >> t;
for (int i = 0; i < t; i++) {
   cout << "Case #" << i+1 << ":" << endl;
   solve();
}


return 0;
}
