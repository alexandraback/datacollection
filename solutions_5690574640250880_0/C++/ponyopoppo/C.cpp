#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define repi(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) repi(i, 0, a)
#define repd(i, a, b) for(int i = (a); i >= (b); i--)
#define repit(i, v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define reprit(i, v) for(__typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define UNIQUE(v) (v).erase(unique(all(v)), (v).end())
#define pb push_back
#define mp make_pair
#define PI acos(-1.0)
#define to_str(v) #v
using namespace std;
typedef long long ll;

template<class X>
ostream& operator<<(ostream& os, const vector<X> &v) {
  repit(itr, v) cout << *itr << " ";
  cout << " size : " << v.size();;
  return os;
}

char ans[55][55];
bool able;
const char c = 'c';
void solve(int R, int C, int M) {
  able = true;
  rep(i, R) rep(j, C) ans[i][j] = '.';
  if(M == 0) {

  } else if(M == R*C-1) {
    rep(i, R) rep(j, C) ans[i][j] = '*';
    ans[R-1][C-1] = c;
  } else if(R >= 3) {
    if(M <= (R-2) * (C-2)) {
      int cnt = M;
      rep(i, R-2) rep(j, C-2) if(cnt) {
	ans[i][j] = '*';
	cnt--;
      }
    } else {
      int TM = M - (R-2) * (C-2);
      if(TM % 2 == 0) {
	if(M <= R*C - 4) {
	  rep(i, R-2) rep(j, C-2) ans[i][j] = '*';
	  int cnt = TM;
	  rep(j, C-2) repi(i, R-2, R) if(cnt) {
	    ans[i][j] = '*';
	    cnt--;
	  }
	  rep(i, R-2) repi(j, C-2, C) if(cnt) {
	    ans[i][j] = '*';
	    cnt--;
	  }
	} else {
	  able = false;
	}
      } else {
	if(M <= R*C - 9) {
	  rep(i, R-2) rep(j, C-2) ans[i][j] = '*';
	  ans[R-3][C-3] = '.';
	  int cnt = TM+1;
	  rep(j, C-3) repi(i, R-2, R) if(cnt) {
	    ans[i][j] = '*';
	    cnt--;
	  }
	  rep(i, R-3) repi(j, C-2, C) if(cnt) {
	    ans[i][j] = '*';
	    cnt--;
	  }
	} else {
	  able = false;
	}
      }
    }
  } else if(R == 2) {
    if(M % 2 == 0) {
      if(M == 2*C-2) {
	able = false;
      } else {
	int cnt = M;
	rep(j, C) rep(i, 2) if(cnt) {
	  ans[i][j] = '*';
	  cnt--;
	}
      }
    } else {
      able = false;
    }
  } else if(R == 1) {
    rep(i, C) ans[0][i] = '.';
    rep(i, M) ans[0][i] = '*';
  }
  ans[R-1][C-1] = c;
}

int main() {
  int T;
  cin >> T;
  rep(i, T) {
    cout << "Case #" << i+1 << ":" << endl;
    int R, C, M;
    cin >> R >> C >> M;
    bool rev = false;
    if(R > C) {
      rev = true;
      swap(R, C);
    }
    solve(R, C, M);
    if(!able) {
      cout << "Impossible" << endl;
      continue;
    }
    if(rev) {
      rep(i, C) {
	rep(j, R) cout << ans[j][i];
	cout << endl;
      }
    } else {
      rep(i, R) {
	rep(j, C) cout << ans[i][j];
	cout << endl;
      }
    }
  }

  return 0;
}
