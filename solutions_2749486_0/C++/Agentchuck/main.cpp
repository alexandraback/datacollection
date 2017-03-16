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
    ans = 0;
    int X, Y;
    inFile >> X >> Y;
    pii at(0, 0);
    uint32_t move = 1;

    // For the small case do something dumb.

    cout << "Case #" << c + 1 << ": " ;
    outFile << "Case #" << c + 1 << ": " ;

    while (at.first != X) {
      if (at.first < X) {
        cout << "WE" ;
        outFile << "WE" ;
        at.first+=1;
      } else {
        cout << "EW" ;
        outFile << "EW" ;
        at.first-=1;
      }
    }
    while (at.second != Y) {
      if (at.second < Y) {
        cout << "SN" ;
        outFile << "SN" ;
        at.second+=1;
      } else {
        cout << "NS" ;
        outFile << "NS" ;
        at.second-=1;
      }
    }
    cout << endl;
    outFile << endl;
  }

  outFile.close();
  return 0;
}
