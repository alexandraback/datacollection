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

uint64_t wallHeight[500];
static const int mid = 250;
struct TribeInfo {
  int d;
  int n;
  int w;
  int e;
  int s;
  int d_d;
  int d_p;
  int d_s;
};

TribeInfo tribes[1000];

struct Attack {
  int w;
  int e;
  int s;
};

map < int, list < Attack > > attDays;

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
    attDays.clear();
    for0n(i, 500) {
      wallHeight[i] = 0;
    }
    ans = 0;
    int N;
    inFile >> N;
    for0n(i, N) {
      inFile >> tribes[i].d;
      inFile >> tribes[i].n;
      inFile >> tribes[i].w;
      inFile >> tribes[i].e;
      inFile >> tribes[i].s;
      inFile >> tribes[i].d_d;
      inFile >> tribes[i].d_p;
      inFile >> tribes[i].d_s;

      for0n(j, tribes[i].n) {
        Attack newAttack;
        newAttack.w = tribes[i].w + (j * tribes[i].d_p);
        newAttack.e = tribes[i].e + (j * tribes[i].d_p);
        newAttack.s = tribes[i].s + (j * tribes[i].d_s);
        int onDay = tribes[i].d + (j * tribes[i].d_d);
        //cout << "Tribe " << i << " attack on " << onDay << endl;
        attDays[onDay].push_back(newAttack);
      }
    }

    map < int, list < Attack > >::iterator mit;
    list < Attack >::iterator lit;
    for(mit = attDays.begin();
        mit != attDays.end();
        mit++) {
      cout << "Attack on day: " << mit->first << endl;
      for(lit = mit->second.begin();
          lit != mit->second.end();
          lit++) {
        cout << "w: " << lit->w << " e: " << lit->e << " s: " << lit->s << endl;
        int check;
        bool attackSucc = false;
        for (check = lit->w;
             check < lit->e;
             check++) {
          if (wallHeight[check + mid] < lit->s) {
            cout << "- successful" << endl;
            attackSucc = true;
            break;
          }
        }
        if (attackSucc) {
          ans ++;
        }
      }
      for(lit = mit->second.begin();
          lit != mit->second.end();
          lit++) {
        int check;
        for (check = lit->w;
             check < lit->e;
             check++) {
          if (wallHeight[check + mid] < lit->s) {
            wallHeight[check + mid] = lit->s;
          }
        }
      }
    }

    cout << "Case #" << c + 1 << ": " << ans << endl;
    outFile << "Case #" << c + 1 << ": " << ans << endl;
  }

  outFile.close();
  return 0;
}
