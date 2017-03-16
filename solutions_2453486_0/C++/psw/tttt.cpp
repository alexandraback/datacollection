#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<set>
#include<vector>

using namespace std;

int main() {
  int T, n, i, j, cn;
  char A[5][5];
  int B[5][5], C[5][5], D[5][5];
  char res;
  cin >> T;
  for(cn=0; cn<T; cn++){
    string s;
    cin >> s;
    A[0][0] = s[0];
    A[0][1] = s[1];
    A[0][2] = s[2];
    A[0][3] = s[3];
    cin >> s;
    A[1][0] = s[0];
    A[1][1] = s[1];
    A[1][2] = s[2];
    A[1][3] = s[3];
    cin >> s;
    A[2][0] = s[0];
    A[2][1] = s[1];
    A[2][2] = s[2];
    A[2][3] = s[3];
    cin >> s;
    A[3][0] = s[0];
    A[3][1] = s[1];
    A[3][2] = s[2];
    A[3][3] = s[3];
    for(i=0;i<4;i++) for(j=0; j<4; j++) {
      if ((A[i][j] == 'T') || (A[i][j] == 'O')) B[i][j] = 1; else B[i][j] = 0;
      if ((A[i][j] == 'T') || (A[i][j] == 'X')) C[i][j] = 1; else C[i][j] = 0;
      if (A[i][j] == '.') D[i][j] = 1; else D[i][j] = 0;
    }
         if (B[0][0] + B[0][1] + B[0][2] + B[0][3] == 4) res = 'O';
    else if (B[1][0] + B[1][1] + B[1][2] + B[1][3] == 4) res = 'O';
    else if (B[2][0] + B[2][1] + B[2][2] + B[2][3] == 4) res = 'O';
    else if (B[3][0] + B[3][1] + B[3][2] + B[3][3] == 4) res = 'O';
    else if (B[0][0] + B[1][0] + B[2][0] + B[3][0] == 4) res = 'O';
    else if (B[0][1] + B[1][1] + B[2][1] + B[3][1] == 4) res = 'O';
    else if (B[0][2] + B[1][2] + B[2][2] + B[3][2] == 4) res = 'O';
    else if (B[0][3] + B[1][3] + B[2][3] + B[3][3] == 4) res = 'O';
    else if (B[0][0] + B[1][1] + B[2][2] + B[3][3] == 4) res = 'O';
    else if (B[0][3] + B[1][2] + B[2][1] + B[3][0] == 4) res = 'O';
    else if (C[0][0] + C[0][1] + C[0][2] + C[0][3] == 4) res = 'X';
    else if (C[1][0] + C[1][1] + C[1][2] + C[1][3] == 4) res = 'X';
    else if (C[2][0] + C[2][1] + C[2][2] + C[2][3] == 4) res = 'X';
    else if (C[3][0] + C[3][1] + C[3][2] + C[3][3] == 4) res = 'X';
    else if (C[0][0] + C[1][0] + C[2][0] + C[3][0] == 4) res = 'X';
    else if (C[0][1] + C[1][1] + C[2][1] + C[3][1] == 4) res = 'X';
    else if (C[0][2] + C[1][2] + C[2][2] + C[3][2] == 4) res = 'X';
    else if (C[0][3] + C[1][3] + C[2][3] + C[3][3] == 4) res = 'X';
    else if (C[0][0] + C[1][1] + C[2][2] + C[3][3] == 4) res = 'X';
    else if (C[0][3] + C[1][2] + C[2][1] + C[3][0] == 4) res = 'X';
    else if (D[0][0] + D[0][1] + D[0][2] + D[0][3] + D[1][0] + D[1][1] + D[1][2] + D[1][3] + D[2][0] + D[2][1] + D[2][2] + D[2][3] + D[3][0] + D[3][1] + D[3][2] + D[3][3] == 0) res = 'D';
    else res = 'U';
    
    if (res == 'O') cout << "Case #" << cn+1 << ": O won\n";
    else if (res == 'X') cout << "Case #" << cn+1 << ": X won\n";
    else if (res == 'D') cout << "Case #" << cn+1 << ": Draw\n";
    else cout << "Case #" << cn+1 << ": Game has not completed\n";
  }
  return 0;
}