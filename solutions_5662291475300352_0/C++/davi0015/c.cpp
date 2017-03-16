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
    int N;
    cin >> N;

    vector<int> D(N), H(N), M(N);
    int hikers = 0;
    forn(j, N) {
      cin >> D[j] >> H[j] >> M[j];
      hikers += H[j];
    }

    int encounter = 0;
    if(hikers == 2) {
      int d1, m1;
      int d2, m2;
      d1 = D[0];
      m1 = M[0];
      if(H[0] == 2) {
        d2 = d1;
        m2 = m1 + 1;
      }
      else {
        d2 = D[1];
        m2 = M[1];
      }

      double t11, t12, t21, t22;
      t11 = (double) (360 - d1) / 360 * m1;
      t12 = (double) (720 - d1) / 360 * m1;
      t21 = (double) (360 - d2) / 360 * m2;
      t22 = (double) (720 - d2) / 360 * m2;

      if((t11 <= t21 && t12 <= t21) || (t21 <= t11 && t22 <= t11)) {
        encounter = 1;
      }
    }

    cout << "Case #" << i + 1 << ": " << encounter << endl;
  }

  return 0;
}
