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

const int debug = 0;
// 1 = 1
// 2 = i
// 3 = j
// 4 = k
int multArray[4][4] =
{ { 1, 2, 3, 4},
  { 2,-1, 4,-3},
  { 3,-4,-1, 2},
  { 4, 3,-2,-1}
};
int mult(int A, int B) {
  int result = multArray[abs(A) - 1][abs(B) - 1];
  if (A * B < 0) result *= -1;
  return result;
}
int conv(char inChar) {
  switch (inChar) {
    case 'i': return 2;
    case 'j': return 3;
    default : return 4;
  }
}

int findGuy(int findVal, int from, int to, string const& searchString) {
  if (findVal == 4) {
    // For k, do the remainder of the string.
    int runTot = 1;
    for (int pos = from; pos < to; pos++) {
      runTot = mult(runTot, conv(searchString[pos]));
      //cerr << "mult " << searchString[pos] << " runTot now: " << runTot << endl;
    }
    if (runTot == findVal) {
      //cerr << "found " << findVal << endl;
      return to;
    } else {
      //cerr << "not found " << endl;
      return -1;
    }
  } else {
    // Find the first instance of findVal
    int runTot = 1;
    for (int pos = from; pos < to; pos++) {
      runTot = mult(runTot, conv(searchString[pos]));
      //cerr << "mult " << searchString[pos] << " runTot now: " << runTot << endl;
      if (runTot == findVal) {
        //cerr << "found " << findVal << endl;
        return pos + 1;
      }
    }
  }
  return -1;
}

int main (int argc, char **argv)
{
  if (argc < 2) {
    printf("Specify input file\n");
    return -1;
  }

  ifstream inFile(argv[1]);
  ofstream outFile("output.txt", fstream::trunc);

  if (debug) {
    cerr << "ji = " << mult (3, 2) << endl;
    cerr << "ij = " << mult (2, 3) << endl;
    cerr << "-ij = " << mult (-2, 3) << endl;
    cerr << "i-j = " << mult (2, -3) << endl;
    cerr << "-i-j = " << mult (-2, -3) << endl;
    cerr << "ijk = " << mult(mult (2, 3), 4) << endl;
    cerr << "i-jk = " << mult(mult (2, -3), 4) << endl;
  }
  inFile >> nCases;
  cerr << nCases << " cases." << endl;
  for0n(c,nCases) {
    ans = 0;
    int L, X;
    std::string Xstr;
    inFile >> L >> Xstr;
#if 0
    if (Xstr.length() > 2) {
      X = 100 + atoi(Xstr.substr(Xstr.length() - 2).c_str());
    } else {
      X = atoi(Xstr.c_str());
    }
#endif
      X = atoi(Xstr.c_str());
    string inString, searchString;
    inFile >> inString;
    for0n(i, X) {
      searchString += inString;
    }
    //cerr << "String is: " << searchString << endl;
    int islen = inString.length();
    int sslen = X * islen;
#if 0
    int runTot = 1;
    for (int pos = 0; pos < sslen; pos++) {
      runTot = mult(runTot, conv(searchString[pos]));
    }
    ans = (runTot == -1 ? 1 : 0);
#endif

    int runTotI = 1;
    int runTotJ = 1;
    int runTotK = 1;
    int posI = 0;
    int posJ = 0;
    int posK = 0;
    // Find i
    int to(sslen);
    for (posI = 0; posI < to; posI++) {
      runTotI = mult(runTotI, conv(searchString[posI]));
      if (runTotI == 2) {
        // cerr << "Found 2 @ " << posI << endl;
        runTotJ = 1;
        for (posJ = posI + 1; posJ < to; posJ++) {
          runTotJ = mult(runTotJ, conv(searchString[posJ]));
          if (runTotJ == 3) {
            //cerr << "Found 3 @ " << posJ << endl;
            runTotK = 1;
            for (posK = posJ + 1; posK < to; posK++) {
              runTotK = mult(runTotK, conv(searchString[posK]));
            }
            if (runTotK == 4) {
              ans = 1;
            } else {
              ans = 0;
            }
            posI = posJ = posK = to + 1;
            break;
          }
        }
      }
    }
        
#if 0
    do {
      //cerr << "posI from " << posI << ", " << sslen << endl;
      posI = findGuy(2, posI, sslen, searchString);
      if (posI > 0) {
        //cerr << "posJ from " << posI << ", " << sslen << endl;
        posJ = findGuy(3, posI, sslen, searchString);
        if (posJ > 0) {
          //cerr << "posK from " << posJ << ", " << sslen << endl;
          posK = findGuy(4, posJ, sslen, searchString);
          if (posK > 0) {
            ans = 1;
            break;
          }
        }
      } else {
        break;
      }
    } while (1);
#endif
    

    cout << "Case #" << c + 1 << ": " << (ans ? "YES" : "NO") << endl;
  }

  outFile.close();
  return 0;
}
