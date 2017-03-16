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

uint64_t make64E(uint64_t *digArr) {
  uint64_t ret = 0;
  int place = 0;
  if (digArr[0]) {
    ret = (digArr[0] * 10000001) +
          (digArr[1] *  1000010) +
          (digArr[2] *   100100) +
          (digArr[3] *    11000);
  } else if (digArr[1]) {
    ret = (digArr[1] * 100001) +
          (digArr[2] *  10010) +
          (digArr[3] *   1100);
  } else if (digArr[2]) {
    ret = (digArr[2] * 1001) +
          (digArr[3] *  110);
  } else {
    ret = digArr[3] * 11;
  }
  return ret;
}

uint64_t make64O(uint64_t *digArr) {
  uint64_t ret = 0;
  int place = 0;
  if (digArr[0]) {
    ret = (digArr[0] * 1000001) +
          (digArr[1] *  100010) +
          (digArr[2] *   10100) +
          (digArr[3] *    1000);
  } else if (digArr[1]) {
    ret = (digArr[1] * 10001) +
          (digArr[2] *  1010) +
          (digArr[3] *   100);
  } else if (digArr[2]) {
    ret = (digArr[2] * 101) +
          (digArr[3] *  10);
  } else {
    ret = digArr[3];
  }
  return ret;
}

bool isPal(uint64_t num) {
  uint64_t digits[20];
  uint64_t power = 0;
  while (num) {
    digits[power] = num % 10;
    power++;
    num /= 10;
  }
  power--;

  //cout << "- " <<  power << endl;
  for(int cnt = 0; cnt < power / 2; cnt++) {
    //cout << "-- " <<  cnt << " : " << digits[cnt] << " : " << digits[power - cnt] << endl;
    if (digits[cnt] != digits[power - cnt]) {
      return false;
    }
  }
  return true;
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
  cout << nCases << " cases." << endl;

  // Build the set
  set<uint64_t> nice;

  uint64_t digits[4] = {0, 0, 0, 0};
  do {
    uint64_t e = make64E(digits);
    e *= e;
    if (isPal(e)) {
      nice.insert(e);
      //cout << e << endl;
    }
    uint64_t o = make64O(digits);
    o *= o;
    if (isPal(o)) {
      nice.insert(o);
      //cout << o << endl;
    }
    for0n(i, 4) {
      digits[i]++;
      if (digits[i] < 4) {
        break;
      }
      if (i == 3) break;
      digits[i] = 0;
    }
  } while (digits[3] < 4);

  for(set<uint64_t>::iterator sit = nice.begin();
      sit != nice.end();
      sit++) {
    //cout << *sit << endl;
  }

  for0n(c,nCases) {
    ans = 0;

    uint64_t A, B;
    inFile >> A >> B;

    set<uint64_t>::iterator sit = nice.lower_bound(A);
    while(sit != nice.end()) {
      if (*sit <= B) {
        ans++;
      }
      sit++;
    }
#if 0
    if (B >= 484) {
      ans = 5;
    } else if (B >= 121) {
      ans = 4;
    } else if (B >= 9) {
      ans = 3;
    } else if (B >= 4) {
      ans = 2;
    } else {
      ans = 1;
    }
    if (A > 484) {
      ans -= 5;
    } else if (A > 121) {
      ans -= 4;
    } else if (A > 9) {
      ans -= 3;
    } else if (A > 4) {
      ans -= 2;
    } else if (A > 1) {
      ans -= 1;
    }
#endif

    cout << "Case #" << c + 1 << ": " << ans << endl;
    outFile << "Case #" << c + 1 << ": " << ans << endl;
  }

  outFile.close();
  return 0;
}
