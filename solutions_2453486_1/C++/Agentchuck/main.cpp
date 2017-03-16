#include <string.h>
#include <stdint.h>
#include <cstdio>
#include <cstdlib>
#include <ctype.h>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())

#define for0n(i,n) for(i=0;i<n;i++)
#define for1n(i,n) for(i=1;i<=n;i++)
#define forn(i,j,n) for(i=j;i<n;i++)
#define ZERO(arr) for(int CNT=0;CNT<sizeof(arr);CNT++){arr[CNT]=0;}

const int MAX = 1000000;
const int inf = 2100000000;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;

int move[4][2] = { {0, 1} , {1, 0} , {0, -1} , {-1, 0} };

//ofstream debug("debug.txt", fstream::trunc);

//
// Add variables here.
//
int nCases;
int c, i, j, k, l;
int ans;

uint32_t my32;
uint64_t modArr[3][3];



int main (int argc, char **argv)
{
  if (argc < 2) {
    printf("Specify input file\n");
    return -1;
  }

  ifstream inFile(argv[1]);
  ofstream outFile("output.txt", fstream::trunc);

  inFile >> nCases;
  cout << nCases << " cases." << endl;
  for0n(c,nCases) {
    char board[4][4];
    bool full = true;
    for0n(i, 4) {
      for0n(j, 4) {
        inFile >> board[i][j];
        if (board[i][j] == '.') {
          full = false;
        }
      }
    }

    // Assuming that they don't give us an invalid board, we quit when we find something.
    cout << "Case #" << c + 1 << ": ";
    outFile << "Case #" << c + 1 << ": ";

    int xD1 = 0;
    int xD2 = 0;
    int oD1 = 0;
    int oD2 = 0;
    ans = -1;
    for0n(i, 4) {
      // Check horiz/vert
      int xV = 0;
      int xH = 0;
      int oV = 0;
      int oH = 0;
      for0n(j, 4) {
        char atC = board[i][j];
        if (atC == 'T') {
          xH++;
          oH++;
        } else if (atC == 'X') {
          xH++;
        } else if (atC == 'O') {
          oH++;
        }
        atC = board[j][i];
        if (atC == 'T') {
          xV++;
          oV++;
        } else if (atC == 'X') {
          xV++;
        } else if (atC == 'O') {
          oV++;
        }
      }
      if ((xV == 4) || (xH == 4)) {
        ans = 0;
        break;
      }
      if ((oV == 4) || (oH == 4)) {
        ans = 1;
        break;
      }

      // Check diags.
      char atC = board[i][i];
      if (atC == 'T') {
        xD1++;
        oD1++;
      } else if (atC == 'X') {
        xD1++;
      } else if (atC == 'O') {
        oD1++;
      }
      atC = board[i][3 - i];
      if (atC == 'T') {
        xD2++;
        oD2++;
      } else if (atC == 'X') {
        xD2++;
      } else if (atC == 'O') {
        oD2++;
      }
    }
    if ((xD1 == 4) || (xD2 == 4)) {
      ans = 0;
    }
    if ((oD1 == 4) || (oD2 == 4)) {
      ans = 1;
    }


    if (ans == -1) {
      if (full) {
        cout << "Draw" << endl;
        outFile << "Draw" << endl;
      } else {
        cout << "Game has not completed" << endl;
        outFile << "Game has not completed" << endl;
      }
    } else {
      if (ans == 0) {
        cout << "X won" << endl;
        outFile << "X won" << endl;
      } else {
        cout << "O won" << endl;
        outFile << "O won" << endl;
      }
    }
    // X won
    // O won
    // Draw
    // Game has not completed
  }

  outFile.close();
  return 0;
}
