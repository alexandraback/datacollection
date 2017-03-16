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

vector<ll> solve(ll curC, ll curJ, string strC, string strJ) {
  ll tempC, tempJ;
  vector<ll> nextC, nextJ;
  if (curC == curJ) {
    if (strC[0] == '?') {
      if (strJ[0] == '?') {
        nextC.pb(0);
        nextJ.pb(0);

        nextC.pb(0);
        nextJ.pb(1);

        nextC.pb(1);
        nextJ.pb(0);
      } else {
        if (strJ[0] > '0') {
          nextC.pb(strJ[0] - '0' - 1);
          nextJ.pb(strJ[0] - '0');
        }

        nextC.pb(strJ[0] - '0');
        nextJ.pb(strJ[0] - '0');

        if (strJ[0] < '9') {
          nextC.pb(strJ[0] - '0' + 1);
          nextJ.pb(strJ[0] - '0');
        }
      }
    } else {
      if (strJ[0] == '?') {
        if (strC[0] > '0') {
          nextC.pb(strC[0] - '0');
          nextJ.pb(strC[0] - '0' - 1);
        }

        nextC.pb(strC[0] - '0');
        nextJ.pb(strC[0] - '0');

        if (strC[0] < '9') {
        nextC.pb(strC[0] - '0');
        nextJ.pb(strC[0] - '0' + 1);
        }
      } else {
        nextC.pb(strC[0] - '0');
        nextJ.pb(strJ[0] - '0');
      }
    }
  } else if (curC < curJ) {
    if (strC[0] == '?') {
      nextC.pb(9);
    } else {
      nextC.pb(strC[0] - '0');
    }

    if (strJ[0] == '?') {
      nextJ.pb(0);
    } else {
      nextJ.pb(strJ[0] - '0');
    }
  } else {
    if (strC[0] == '?') {
      nextC.pb(0);
    } else {
      nextC.pb(strC[0] - '0');
    }

    if (strJ[0] == '?') {
      nextJ.pb(9);
    } else {
      nextJ.pb(strJ[0] - '0');
    }
  }

  vector<ll> sol;
  sol.pb(-1);
  sol.pb(-1);

  forn(i, nextC.size()) {
    ll tempC = curC * 10 + nextC[i];
    ll tempJ = curJ * 10 + nextJ[i];
    vector<ll> tempSol;
    tempSol.pb(tempC);
    tempSol.pb(tempJ);
    if (strC.length() > 1) {
      tempSol = solve(tempC, tempJ, strC.substr(1), strJ.substr(1));
    }

    if (sol[0] == -1 ||
        abs(tempSol[0] - tempSol[1]) < abs(sol[0] - sol[1]) ||
        (abs(tempSol[0] - tempSol[1]) == abs(sol[0] - sol[1]) && tempSol[0] < sol[0]) ||
        (abs(tempSol[0] - tempSol[1]) == abs(sol[0] - sol[1]) && tempSol[0] == sol[0] && tempSol[1] < sol[1])
      ) {
      sol = tempSol;
    }
  }
  return sol;
}

string formatStr(ll n, int length) {
  string s = "";
  forn (i, length) {
    s = (char) (n % 10 + '0') + s;
    n /= 10;
  }
  return s;
}

int main() {
  int T;
  cin >> T;

  forn (i, T) {
    string C, J;
    cin >> C >> J;

    vector<ll> ans;
    ans = solve(0, 0, C, J);

    cout << "Case #" << i + 1 << ": " << formatStr(ans[0], C.length()) << " " << formatStr(ans[1], J.length()) << endl;
  }
}
