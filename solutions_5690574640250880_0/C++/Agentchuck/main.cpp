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

const int MAX = 50;
const int inf = 2100000000;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;

int moveDir[4][2] = { {0, -1} , {1, 0} , {0, 1} , {-1, 0} }; // N, E, S, W
char dirName[4] = { 'N', 'E', 'S', 'W' };

//ofstream debug("debug.txt", fstream::trunc);

//
// Add variables here.
//
int nCases;
int c, i, j, k, l;
int ans;

uint32_t my32;
uint64_t modArr[3][3];

char outputMap[50][50];


int main (int argc, char **argv)
{
  if (argc < 2) {
    printf("Specify input file\n");
    return -1;
  }

  ifstream inFile(argv[1]);
  ofstream outFile("output.txt", fstream::trunc);

  inFile >> nCases;
  cerr << nCases << " cases." << endl;
  for0n(c,nCases) {
    ans = 0;
    int R, C, M;
    inFile >> R >> C >> M;
    int minDim = min(R, C);
    int spaces = (R * C) - M;
    for0n(i, 50) {
      for0n(j, 50) {
        outputMap[i][j] = 0;
      }
    }
    outputMap[0][0] = 'c';
     cerr << spaces << " spaces " << endl;

    cout << "Case #" << c + 1 << ":" << endl;
    bool fail = true;
    if (minDim == 1) {
      //cerr << "minDim == 1" << endl;
      // Guaranteed win.
      fail = false;
      for(i = 1; i < spaces ; i++) {
        if (R == 1) {
          outputMap[0][i] = '.';
        } else {
          outputMap[i][0] = '.';
        }
      }
      for(i = spaces; i < spaces + M; i++ ) {
        if (R == 1) {
          outputMap[0][i] = '*';
        } else {
          outputMap[i][0] = '*';
        }
      }
    } else if (spaces == 1) {
        fail = false;
        // Start with all mines. Maybe should have done that in all cases...
        for0n(i, R) {
          for0n(j, C) {
            outputMap[i][j] = '*';
          }
        }
        // Hardcode these to make the start easier.
        outputMap[0][0] = 'c';
    } else if (minDim == 2) {
      // Win if spaces >= 4 and even.
      if ((spaces <= 3) || (spaces & 0x01)) {
        fail = true;
      } else {
        fail = false;

        // Like above, but 2 at a time.
        // Hardcode these to make the loop start easier.
        outputMap[0][1] = '.';
        outputMap[1][0] = '.';
        outputMap[1][1] = '.';

        for(i = 1; i < (spaces) / 2 ; i ++) {
          if (R == 2) {
            outputMap[0][i] = '.';
            outputMap[1][i] = '.';
          } else {
            outputMap[i][0] = '.';
            outputMap[i][1] = '.';
          }
        }
        for(i = spaces / 2; i < (spaces + M) / 2; i++ ) {
          if (R == 2) {
            outputMap[0][i] = '*';
            outputMap[1][i] = '*';
          } else {
            outputMap[i][0] = '*';
            outputMap[i][1] = '*';
          }
        }

      }
    } else {
      // Win if spaces == 4, 6, >=8
      if ((spaces <= 3) || (spaces == 5) || (spaces == 7)) {
        fail = true;
      } else {
        fail = false;
        // Start with all mines. Maybe should have done that in all cases...
        for0n(i, R) {
          for0n(j, C) {
            outputMap[i][j] = '*';
          }
        }
        // Hardcode these to make the start easier.
        outputMap[0][0] = 'c';
        outputMap[0][1] = '.';
        outputMap[1][0] = '.';
        outputMap[1][1] = '.';

        // First column is special case as it is 2 wide.
        i = 2; 
        int spacesLeft = spaces - 4;
        if (spacesLeft > 0) {
          do {
            outputMap[i][0] = '.';
            outputMap[i][1] = '.';
            spacesLeft -= 2;
            ++i;
          } while ((i < R) && (spacesLeft > 3));

          // General case for each remaining columns
          int column = 2;
          while (spacesLeft > 0) {
            int spacesToUse = min(R, spacesLeft);
            if (spacesLeft - spacesToUse == 1) {
              spacesToUse--;
            }
            for0n(i, spacesToUse) {
              outputMap[i][column] = '.';
            }

            spacesLeft -= spacesToUse;
            column++;
          };
        }
      }
    }
    if (fail) {
      cout << "Impossible" << endl;
    } else {
      for0n(i, R) {
        for0n(j, C) {
          cout << outputMap[i][j];
        }
        cout << endl;
      }
    }
  }

  outFile.close();
  return 0;
}
