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
    int K, N, M;
    inFile >> N >> M >> K;
    int minDim = min (N, M);

    if (minDim <= 2) {
      ans = K;
    } else if (K == (N*M)) {
      ans = (2*M) + (2*N) - 4;
    }else if (K < 5) {
      ans = K;
    } else if ((minDim == 3) || (K <= 9)) {
      if (K >= ((N * M) - 4)) {
        int diff = (N * M) - K;
        ans = (2*M) + (2*N) - 4 - diff;
      } else {
        // Basic block is 4 -> 5
        ans = 4;
        int covers = 5;
        bool solid = true;
        do {
          //cerr << ans << ":" << covers << endl;
          if (covers >= K) break;
          ans++;
          covers++;
          if (!solid) {
            covers ++;
          }
          solid = !solid;
        } while (covers < K);
      }
#if 0
      switch (K) {
        case 5:
          ans = 4;
          break;
        case 6:
          ans = 5;
          break;
        case 7:
        case 8:
          ans = 6;
          break;
        case 9:
          ans = 7;
          break;
        case 10:
        case 11:
          ans = 8;
          break;
        case 12:
          ans = 9;
          break;
        case 13:
        case 14:
          ans = 10;
          break;
      }
#endif
    } else { // minDim == 4
      if (K >= ((N * M) - 4)) {
        int diff = (N * M) - K;
        ans = (2*M) + (2*N) - 4 - diff;
      } else if (K == 10) {
        ans = 7;
      } else {
        // Basic block is 8 -> 12
        ans = 8;
        int covers = 12;
        do {
          //cerr << ans << ":" << covers << endl;
          if (covers >= K) break;
          ans++;
          covers += 2;
        } while (covers < K);
      }
    }

    cout << "Case #" << c + 1 << ": " << ans << endl;
  }

  outFile.close();
  return 0;
}
