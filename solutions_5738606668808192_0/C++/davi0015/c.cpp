#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <ctime>
#include <cmath>

using namespace std;

#define forn(I,N) for (int I=0; I<N; I++)
#define fornd(I,N) for (int I=N-1; I>=0; I--)
#define forab(I,A,B) for (int I=A; I<=B; I++)
#define forabd(I,A,B) for (int I=B; I>=A; I--)
#define FOREACH(I,A) for (__typeof__(A)::iterator I=A.begin(); I<A.end(); I++)
#define pb push_back
#define mp make_pair

typedef long long int ll;

int main() {
  int T;
  cin >> T;

  forn(i, T) {
    int N, J;
    cin >> N >> J;

    int hN = 1 << (N / 2 - 1);

    cout << "Case #" << i + 1 << ":" << endl;

    forn (j, J) {
      int n = hN + j;
      string s = "";

      while (n > 0) {
        if (n % 2 == 0) {
          s += "0";
        } else {
          s += "1";
        }
        n >>= 1;
      }

      string buf = "";
      forn(k, s.length()) {
        buf += s[s.length() - 1 - k];
      }
      s = buf + s;
      
      cout << s << " 3 4 5 6 7 8 9 10 11" << endl;
    }
  }
}
