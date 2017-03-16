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
    int D;
    cin >> D;

    vector<int> people(D);
    forn(j, D) {
      cin >> people[j];
    }
    sort(people.begin(), people.end());

    int best = 2000;
    int interrupt = 0;

    forab(j, 1, 1000) {
      interrupt = 0;
      forn(k, D) {
        interrupt += (people[k] - 1) / j;
        if(interrupt + j > best) {
          break;
        }
      }

      if(interrupt + j < best) {
        best = interrupt + j;
      }
    }

    cout << "Case #" << i+1 << ": " << best << endl;
  }

  return 0;
}
