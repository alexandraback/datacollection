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
    int K, C, S;
    cin >> K >> C >> S;


    int ct = 0;
    vector<ll> seq;
    while (ct < K) {
      ll base = 1;
      ll num = 0;
      ll index;
      forn(j, C) {
        index = (ct + C - j - 1) % K;
        num += base * index;
        base *= K;
      }
      seq.pb(num + 1);
      ct += C;
    }
    if (seq.size() > S) {
      cout << "Case #" << i + 1 << ": " << "IMPOSSIBLE" << endl;
    } else {
      cout << "Case #" << i + 1 << ": ";
      forn(j, seq.size()) {
        cout << seq[j] << " ";
      }
      cout << endl;
    }
  }
}
