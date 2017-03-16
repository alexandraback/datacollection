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
    bool can = true;
    cout << "Case #" << c + 1 << ": " ;
    outFile << "Case #" << c + 1 << ": " ;
  
    size_t N, M;
    inFile >> N >> M;

    int grass[100][100];
    int maxX[100];
    int maxY[100];
    for0n(i,100) {
      maxX[i] = maxY[i] = -1;
    }
    for0n(i, N) {
      for0n(j, M) {
        int gH;
        inFile >> gH;
        grass[i][j] = gH;
        if(gH > maxX[i]) {
          maxX[i] = gH;
          cout << "MaxX " << i << "= " << gH << endl;
        }
        if(gH > maxY[j]) {
          maxY[j] = gH;
          cout << "MaxY " << j << "= " << gH << endl;
        }
      }
    }

    for0n(i, N) {
      for0n(j, M) {
        int gH = grass[i][j];
        if ((gH < maxX[i]) && (gH < maxY[j])) {
          cout << "Can't: " << i << " " << j << " " << gH << " " << maxX[i] << " " << maxY[j] << endl;
          can = false;
          i = inf;
          j = inf;
        }
      }
    }

    cout << (can ? "YES" : "NO") << endl;
    outFile << (can ? "YES" : "NO") << endl;
  }

  outFile.close();
  return 0;
}
