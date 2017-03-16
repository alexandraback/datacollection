#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <climits>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <cctype>
#include <bitset>
#include <ctime>
#include <cassert>
#include <fstream>
#include <complex>
#include <iomanip>
using namespace std;

#define MIN(x,y) (((x)<(y))?(x):(y))
#define MAX(x,y) (((x)>(y))?(x):(y))
#define ABS(x) (((x)<0)?(-(x)):(x))
#define ff first
#define ss second
#define ei else if
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
const ld EPS = 1e-7;
const ld PI  = 3.141592653589793;

int R, C, M, N;
char mines[55][55], used[55][55];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool valid(pii p) {
  return 1 <= p.ff && p.ff <= R &&
         1 <= p.ss && p.ss <= C &&
         mines[p.ff][p.ss] == '*';
}

bool okay(pii p) {
  return 1 <= p.ff && p.ff <= R &&
    1 <= p.ss && p.ss <= C &&
    mines[p.ff][p.ss] != '*' &&
    used[p.ff][p.ss] == 0;
}

bool check(int mask) {
  memset(mines, 0, sizeof(mines));
  memset(used, 0, sizeof(used));

  int idx;
  for(int i = 1; i <= R; ++i)
    for(int j = 1; j <= C; ++j) {
      idx = (i-1)*C + j - 1;
      if(mask & (1 << idx))
	mines[i][j] = '*';
    }

  pii cell;
  for(int i = 1; i <= R; ++i)
    for(int j = 1; j <= C; ++j) {
      if(mines[i][j] == '*') continue;
      for(int k = 0; k < 8; ++k) {
	cell = mp(i+dy[k], j+dx[k]);
	if(valid(cell))
	  mines[i][j]++;
      }
    }

  /*
  if(mask == 7) {
    for(int i = 1; i <= R; ++i) {
      for(int j = 1; j <= C; ++j)
	if(mines[i][j] != '*') cout << char(mines[i][j]+'0');
	else cout << mines[i][j];
      cout << '\n';
    }

    exit(0);
  }
  */

  int c1 = 0;
  for(int i = 1; i <= R; ++i)
    for(int j = 1; j <= C; ++j)
      if(mines[i][j] != '*')
	c1++;

  bool ok = false;
  int c2 = 0;
  pii place;
  for(int i = 1; i <= R; ++i)
    if(!ok)
    for(int j = 1; j <= C; ++j)
      if(mines[i][j] == 0) {
	queue<pii> Q;
	Q.push(mp(i, j));
	c2++;
	place = mp(i, j);
	used[i][j] = 1;
	while(!Q.empty()) {
	  pii v = Q.front(); Q.pop();
	  for(int k = 0; k < 8; ++k) {
	    cell = mp(v.ff+dy[k], v.ss+dx[k]);
	    if(!okay(cell)) continue;
	    c2++;
	    if(mines[cell.ff][cell.ss] == 0)
	      Q.push(cell);
	    used[cell.ff][cell.ss] = 1;
	  }
	}

	ok = true;
	break;
      }

  if(c1 == c2) {
    mines[place.ff][place.ss] = 'c';
    return true;
  }
  return false;
}

void print_res() {
  for(int i = 1; i <= R; ++i) {
    for(int j = 1; j <= C; ++j)
      if(mines[i][j] != '*' && mines[i][j] != 'c') cout << '.';
      else cout << mines[i][j];
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);

  int T; cin >> T;
  for(int tests = 1; tests <= T; ++tests) {
    cout << "Case #" << tests << ":\n";

    cin >> R >> C >> M;
    N = R*C;

    if(N == M+1) {
      cout << 'c';
      for(int i = 2; i <= C; ++i) cout << '*';
      cout << '\n';
      for(int i = 2; i <= R; ++i) {
	for(int j = 1; j <= C; ++j)
	  cout << '*';
	cout << '\n';
      }
      continue;
    }

    bool ok = false;
    for(int mask = 0; mask < (1<<N); ++mask) {
      if(__builtin_popcount(mask) != M)
	continue;

      bool res = check(mask);
      if(res) {
	print_res();
	ok = true;
	break;
      }
    }
    if(!ok) cout << "Impossible\n";
  }
  
  return 0;
}
