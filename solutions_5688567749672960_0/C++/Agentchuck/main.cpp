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

uint64_t flipcons(uint64_t cons) {
    vector<int> dig;
    int nd(0);
    uint64_t Nc(cons);
    while (Nc) {
      dig.push_back(Nc % 10);
      Nc /= 10;
      nd++;
    }
    uint64_t powr = 1;
    uint64_t retr = 0;
    while (nd > 0) {
      retr += dig.back() * powr;
      dig.pop_back();
      nd--;
      powr *= 10;
    }

    return retr;
}

int main (int argc, char **argv)
{
  if (argc < 2) {
    printf("Specify input file\n");
    return -1;
  }

  ifstream inFile(argv[1]);
  ofstream outFile("output.txt", fstream::trunc);

#if 0
  cerr << "rev 10: " << flipcons(10) << endl;
  cerr << "rev 109: " << flipcons(109) << endl;
  cerr << "rev 1099: " << flipcons(1099) << endl;
  cerr << "rev 101323: " << flipcons(101323) << endl;
#endif
  inFile >> nCases;
  cerr << nCases << " cases." << endl;
  for0n(c,nCases) {
    ans = 0;
    uint64_t N;
    inFile >> N;
    //N = c + 1;

    vector<int> dig;
    int nd(0);
    uint64_t Nc(N);
    while (Nc) {
      dig.push_back(Nc % 10);
      Nc /= 10;
      nd++;
    }

    //cerr << "nd: " << nd << endl;
    // First build up the number of digits
    int ansdig = 1;
    uint64_t cons = 0;
    uint64_t g2 = 10;
    while (ansdig != nd) {
      //cerr << cons << " " << g2 << endl;
      ans += g2 - cons;
      cons = g2;
      g2 *= 10;
      ansdig++;
      //cerr << cons << " " << g2 << endl;
      if (ansdig != nd) {
        ans += pow(10,ansdig/2) - 1;
        ans ++; // flip
        cons += pow(10,ansdig/2) - 1;
        //cerr << cons << " " << g2 << endl;
        cons = flipcons(cons);
        //cerr << cons << " " << g2 << endl;
      }
    }

    //cerr << cons << " " << N << endl;

    // Next work out additional flip
    // Deconstruct the top half MSD
    if (cons != N) {
      uint64_t flipamt = 0;
      vector<int> digT(dig);
      uint64_t powr = 1;
      //cerr << nd/2 << " " << N << endl;
      for0n(i, nd/2) {
        flipamt  += dig[nd - nd/2 + i] * powr;
        powr *= 10;
      }
      //cerr << flipamt << endl;
      uint64_t flipd = flipcons(cons + flipcons(flipamt));
      if(flipd > N) {
      //if (N % 10 == 0) {
        flipamt -= 1;
      }
      //cerr << flipamt << endl;
      flipamt = flipcons(flipamt);
      //uint64_t flipcst(flipamt);
      flipd = flipcons(cons + flipamt);
      if (flipamt + 1 + (N - flipd) < N - cons) {
        ans += flipamt + 1;
        cons += flipamt;
        cons = flipcons(cons);
      }
    }
#if 0
    if (cons != N) {
      uint64_t flipamt = 0;
      vector<int> digT(dig);
      uint64_t powr = 1;
      //cerr << nd/2 << " " << N << endl;
      for0n(i, nd/2) {
        flipamt  += dig[nd - i - 1] * powr;
        powr *= 10;
      }
      uint64_t flipd = flipcons(cons + flipamt);
      if (flipamt + 1 + (N - flipd) < N - cons) {
        ans += flipamt + 1;
        cons += flipamt;
        cons = flipcons(cons);
      }
    }
#endif

    // Finally add remainder
    ans += N - cons;

    cout << "Case #" << c + 1 << ": " << ans << endl;
  }

  outFile.close();
  return 0;
}
