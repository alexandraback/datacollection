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

    vector<int> count(2501);
    int temp;
    forn(j, N * (2 * N - 1)) {
      cin >> temp;
      count[temp]++;
    }

    vector<int> missing;
    forn(j, 2501) {
      if(count[j] % 2 == 1) {
        missing.pb(j);
      }
    }

    cout << "Case #" << i + 1 << ": ";
    forn(j, missing.size()) {
      cout << missing[j] << " ";
    }
    cout << endl;
  }
}
