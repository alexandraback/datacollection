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

vector<string> strings;


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
    int N;
    inFile >> N;
    strings.clear();
    strings.resize(N);
    ans = 0;
    for0n(i, N) {
      inFile >> strings[i];
    }

    bool possible = true;

    char ca;
    vector<string::iterator> sits(N);
    for0n(i, N) {
      sits[i] = strings[i].begin();
    }

    bool done = false;
    do {
      if(sits[0] == strings[0].end()) {
        for0n(i, N) {
          if (sits[i] != strings[i].end()) {
            possible = false;
            break;
          }
        }
        done = true;
        break;
      }
      ca = *sits[0];
      for(i = 1; i < N; i++) {
        if(*sits[i] != ca) {
          possible = false;
          break;
        }
      }
      if (!possible) break;
      vector<int> lengths(N);
      int avg = 0;
      int minLen = MAX;
      int maxLen = 0;
      for0n(i, N) {
        lengths[i] = 0;
        while (*sits[i] == ca) {
          lengths[i]++;
          sits[i]++;
        }
        //cerr << "str " << i << " sublen " << lengths[i] << endl;

        avg+=lengths[i];
        minLen = min(minLen, lengths[i]);
        maxLen = max(maxLen, lengths[i]);
      }
      int minCost = MAX;
      //cerr << minLen << ":" << maxLen << endl;
      for (i = minLen ; i <= maxLen ; ++i) {
        int cost = 0;
        for0n(j, N) {
          cost += (abs (i - lengths[j]));
          //cerr << "Cost for " << i << " now " << cost << endl;
        }
        minCost = min(minCost, cost);
      }
      ans += minCost;
      //cerr << "ans now: " << ans << endl;
    } while ((possible) &&(!done));

    cout << "Case #" << c + 1 << ": " ;
    if (!possible) {
      cout << "Fegla Won" << endl;
    } else {
      cout << ans << endl;
    }
  }

  outFile.close();
  return 0;
}
