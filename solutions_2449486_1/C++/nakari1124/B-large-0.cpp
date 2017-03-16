#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <set>

using namespace std;

typedef long long i64;
typedef int int_t;
typedef vector<int_t> vi;
typedef vector<vi> vvi;

typedef pair<int_t, int_t> pi;

#define tr(c, i) for(typeof((c).begin()) i = (c).begin(); i < (c).end(); i++)
#define pb push_back
#define sz(a) int((a).size)
#define all(c) (c).begin(), (c).end()
#define REP(s, e, i) for(i=(s); i < (e); ++i)

const int O = 1;
const int X = 2;
const int T = 3;

bool check_O(int v) {
  return v == O || v == T;
}
bool check_X(int v) {
  return v == X || v == T;
}

bool check4(int v1, int v2, int v3, int v4) {
  if(check_O(v1) && check_O(v2) && check_O(v3) && check_O(v4)) {
    cout << "O won";
    return true;
  }
  else if(check_X(v1) && check_X(v2) && check_X(v3) && check_X(v4)) {
    cout << "X won";
    return true;
  }
  return false;
}

int main(int argc, char *argv[]) {

  i64 C;
  cin >> C;
  i64 n;
  i64 i, j;

  REP(0, C, n) {
    cout << "Case #" << n + 1 << ": ";

    i64 N, M;
    cin >> N >> M;
    vvi pattern(N, vi(M, 0));
    REP(0, N, i) {
      REP(0, M, j) {
	cin >> pattern[i][j];
      }
    }

    vi h_max(N, 0), v_max(M, 0);
    REP(0, N, i) {
      REP(0, M, j) {
	h_max[i] = max(h_max[i], pattern[i][j]);
	v_max[j] = max(v_max[j], pattern[i][j]);
      }
    }

    bool flag = true;
    vi h_flag(N, 1), v_flag(M, 1);
    for(int h = 100; h >= 1; --h) {
      REP(0, N, i) {
	h_flag[i] = (h_max[i] <= h ? 1 : 0);
      }
      REP(0, M, j) {
	v_flag[j] = (v_max[j] <= h ? 1 : 0);
      }

      REP(0, N, i) {
	REP(0, M, j) {
	  if(pattern[i][j] <= h && (h_flag[i] == 0 && v_flag[j] == 0)) {
	    flag = false;
	    break;
	  }
	}
	if(!flag)
	  break;
      }
      if(!flag)
	break;
    }

    if(flag)
      cout << "YES";
    else
      cout << "NO";

    cout << endl;
  }

  return 0;
}
