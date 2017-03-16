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

int ind[] = {0, 2, 6, 8, 4, 5, 7, 3, 1, 9};
string name[] = {"ZERO", "TWO", "SIX", "EIGHT",  "FOUR", "FIVE", "SEVEN", "THREE", "ONE", "NINE"};

int main() {
  int T;
  cin >> T;

  forn(i, T) {
    string s;
    cin >> s;

    vector<int> count(26);
    forn(j, s.length()) {
      count[s[j] - 'A']++;
    }

    vector<int> num;
    forn(j, 10) {
      while(count[name[j][0] - 'A'] > 0 && count[name[j][1] - 'A'] > 0 && count[name[j][2] - 'A'] > 0) {
        num.pb(ind[j]);
        forn(k, name[j].length()) {
          count[name[j][k] - 'A']--;
        }
      }
    }

    sort(num.begin(), num.end());
    cout << "Case #" << i + 1 << ": ";
    forn(j, num.size()) {
      cout << num[j];
    }
    cout << endl;
  }
}
