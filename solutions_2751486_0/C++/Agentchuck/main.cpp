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
uint64_t ans;

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
    string name;
    inFile >> name;
    int n;
    inFile >> n;
    ans = 0;
    //cout << n << endl << name << endl;
    int L = name.length();
    // cout << "L: " << L << endl;
    for(i = 0; i <= L - n; i++) {
      // cout << "i: " << i << endl;
      int consec = 0;
      for(j = i; j < L; j++) {
        char let = name[j];
        // cout << "- j: " << j << " " << let << endl;
        if ((let == 'a') ||
            (let == 'e') ||
            (let == 'i') ||
            (let == 'o') ||
            (let == 'u')) {
          consec = 0;
          continue;
        }
        consec++;
        if (consec >= n) {
          // cout << "hit " <<   endl;
          ans+=((j - i - n + 2) * (L - j));
          i = (j - n + 1);
          break;
        }
      }
    }

    cout << "Case #" << c + 1 << ": " << ans << endl;
    outFile << "Case #" << c + 1 << ": " << ans << endl;
  }

  outFile.close();
  return 0;
}
