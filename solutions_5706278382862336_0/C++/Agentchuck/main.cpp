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
    string inFrac;
    inFile >> inFrac;
    size_t slash = inFrac.find("/");
    uint64_t num;
    istringstream(inFrac.substr(0, slash)) >> num;
    uint64_t den;
    istringstream(inFrac.substr(slash+1)) >> den;

    //cerr << num << "/" << den << endl;
    bool possible = true;
    int bits = 0;
    uint64_t dencpy = den;
    int bitpos = 0, loc = 0;
    do {
      if (dencpy & 0x01) {
        bits++;
        loc = bitpos;
      }
      dencpy = dencpy >> 1;
      bitpos++;
    } while (dencpy);

    if (bits > 1) {
      possible = false;
    } else {
      //cerr << loc << endl;
      int gen = 0;
      do {
        if (num & den) {
          ans = gen;
          break;
        }
        den = den >> 1;
        gen++;
      } while (true);
    }
    if (possible) {
      cout << "Case #" << c + 1 << ": " << ans << endl;
    } else {
      cout << "Case #" << c + 1 << ": impossible" << endl;
    }
  }

  outFile.close();
  return 0;
}
