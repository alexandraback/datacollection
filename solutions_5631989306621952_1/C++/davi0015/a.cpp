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
    string s;
    cin >> s;

    string output = "";
    forn(j, s.length()) {
      if (j == 0) {
        output += s[j];
      } else if(s[j] >= output[0]) {
        output = s[j] + output;
      } else {
        output += s[j];
      }
    }
    cout << "Case #" << i + 1 << ": " << output << endl;
  }
}
