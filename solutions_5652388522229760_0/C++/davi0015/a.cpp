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
    ll N;
    cin >> N;

    vector<bool> present(10);
    ll out = -1;

    forab(j, 1, 10000) {
      ll t = N * j;
      while(t > 0) {
        present[t % 10] = true;
        t /= 10;
      }

      bool isComplete = true;
      forn(k, 10) {
        if (!present[k]) {
          isComplete = false;
          break;
        }
      }
      if (isComplete) {
        out = N * j;
        break;
      }
    }

    if (out > 0) {
      cout << "Case #" << i + 1 << ": " << out << endl;
    } else {
      cout << "Case #" << i + 1 << ": INSOMNIA" << endl;
    }
  }
}
