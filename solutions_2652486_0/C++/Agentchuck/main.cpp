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

int answers[12];
int inNums[12];

map<int, vector<int> > combs;
map<int, vector<int> > combs2;

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

  for(i = 2; i <= 5; i++) {
    for(j = i; j <= 5; j++) {
      if (i*j != 4) {
        vector<int> comb2(2);
        comb2[0] = i; comb2[1] = j;
        pair<int, vector<int> > key2(i*j, comb2);
        combs2.insert(key2);
      }

      for(k = j; k<= 5; k++) {
        if (i*j*k == 16) continue;
        vector<int> comb(3);
        comb[0] = i; comb[1] = j; comb[2] = k;
        pair<int, vector<int> > key(i*j*k, comb);
        combs.insert(key);
        //cout << "Added " << i * j * k << " as " << comb[0] << ", " << comb[1] << ", " << comb[2] << endl;
      }
    }
  }

  for0n(c,nCases) {
    int R, N, M, K;
    inFile >> R >> N >> M >> K;
    int cases;
    cout << "Case #" << c + 1 << ": " <<endl;
    outFile << "Case #" << c + 1 << ": " << endl;
    for0n(cases, R) {
      int req[5] = {0};
      for0n(i, 5) {
        req[i] = 0;
      }
      for0n(i, N) {
        answers[i] = 2;
      }
      bool sure = false;
      for0n(i, K) {
        int prod;
        inFile >> prod;
        if (prod == 1) continue;
        if (!sure) {
          //inFile >> inNums[i];
          if(combs.find(prod) != combs.end()) {
            answers[0] = combs[prod][0];
            answers[1] = combs[prod][1];
            answers[2] = combs[prod][2];
            sure = true;
            continue;
          }
          if(combs2.find(prod) != combs2.end()) {
            if(combs2[prod][0] == combs2[prod][1]) {
              req[combs2[prod][0]] = 2;
            } else {
              req[combs2[prod][0]] = max(1, req[combs2[prod][0]]);
              req[combs2[prod][1]] = max(1, req[combs2[prod][1]]);
            }
            answers[1] = combs2[prod][0];
            answers[2] = combs2[prod][1];
            continue;
          }
          if ((prod == 2) ||
              (prod == 3) ||
              (prod == 5)) {
            req[prod] = max(1, req[prod]);

            answers[0] = prod;
          }
        }
      }
      if (!sure) {
        int ptr = 0;
        for (i = 2; i <=5; i++) {
          while (req[i] > 0) {
            if (ptr < 3) {
              answers[ptr] = i;
              ptr++;
            }
            req[i]--;
          }
        }
      }

      for0n(i, N) {
        cout << answers[i];
        outFile << answers[i];
      }
      cout << endl;
      outFile << endl;
    }
  }

  outFile.close();
  return 0;
}
