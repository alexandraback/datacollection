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
double ans;

uint32_t my32;
uint64_t modArr[3][3];

double EV[100][100];
int Kn[26];
double Kp[26];
int K, L, S;
string Ks, Ls;

double getEv(int at, int let)
{
  if (EV[at][let] >= 0.0) return EV[at][let];

  double exp;
  // If not enough left, return 0.
  if (Ls.length() - let + at > S) {
    exp = 0.0;
  } else {
    // Prob correct = Kp[L[let] - 'A'];
    double PC = Kp[Ls[let] - 'A'];
    if (let == L - 1) {
      exp = PC;
    } else {
      exp = PC * getEv(at + 1, let + 1);
    }
    //exp += (1.0 - PC) * getEv(at + 1, 0);
    if (let > 0) {
      exp += (1.0 - PC) * getEv(at, 0);
    } else {
      exp += getEv(at + 1, 0);
    }
  }

  EV[at][let] = exp;

  return exp;
}

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

    for0n(i, 100) for0n(j, 100) EV[i][j] = -1.0;
    for0n(i, 26) Kn[i] = 0;

    inFile >> K >> L >> S;
    inFile >> Ks >> Ls;

    for0n(i, Ks.length() ) {
      Kn[Ks[i] - 'A']++;
    }
    for0n(i, 26) {
      Kp[i] = double(Kn[i]) / double(Ks.length());
      //cerr << char('A' + i) << " " << Kp[i] << endl;
    }

    //cerr << Ks << ", " << Ls << endl;

    // What's the max? Need to make overlaps. 
    int fnd = 0;
    for(i = 1; i < Ls.length(); i++) {
      bool poss = true;
      for(j = 0; j < Ls.length() - i; j++) {
        if (Ls[i + j] != Ls[j]) {
          poss = false;
          break;
        }
      }
      if (poss) {
        fnd = i;
        break;
      }
    }
    int maxBan = (S - Ls.length());
    if (fnd) {maxBan /= fnd;} else {maxBan /= Ls.length();}
    maxBan++;
    //cerr << "fnd: " << fnd << endl;
    //cerr << "maxBan: " << maxBan << endl;

    bool poss = true;
    for0n(i, L) {
      if (Kn[Ls[i] - 'A'] == 0) {
        poss = false;
        break;
      }
    }
    if (!poss ) {
      //cerr << "not possible" << endl;
      ans = 0.0;
    } else {
      ans = double (maxBan) - getEv(0,0);
    }
    cout << "Case #" << c + 1 << ": ";
    cout.precision(6);
    cout.setf(ios::fixed, ios::floatfield);

    cout << ans << endl;
  }

  outFile.close();
  return 0;
}
