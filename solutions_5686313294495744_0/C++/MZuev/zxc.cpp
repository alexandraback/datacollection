#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <memory.h>
#include <set>
#include <ctime>
#include <map>
#include <cstring>
#include <iterator>
#include <queue>
#include <assert.h>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;



#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define ull unsigned long long
#pragma comment(linker, "/STACK:64000000")

typedef long double ld;
typedef pair<ld, ld> pldld;
typedef long long ll;
typedef pair<ll, ll> pll;


typedef unsigned int ui;
typedef unsigned char uc;
const int infi = 1e9 + 7;
const ll infl = 1e18;
const double eps = 1e-7;




/** Interface */

inline int readChar();
inline void writeChar( int x ); 
inline void writeWord( const char *s );
inline void flush();

/** Read */

static const int buf_size = 4096;

inline int getChar() {
  static char buf[buf_size];
  static int len = 0, pos = 0;
  if (pos == len)
    pos = 0, len = fread(buf, 1, buf_size, stdin);
  if (pos == len)
    return -1;
  return buf[pos++];
}

inline int readChar() {
  int c = getChar();
  while (c >= 0 && c <= 32)
    c = getChar();
  return c;
}
char bf[10];
inline void readWord() {
	char *cur = bf;
	*cur = getChar();
  while (*cur <= 32)
    *cur = getChar();
  while (*cur > 32 && *cur != '(') {
	++cur;
	*cur = getChar();
  }
  return;
}

inline int readInt() {
  int s = 1, c = readChar();
  int x = 0;
  if (c == '-')
    s = -1, c = getChar();
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getChar();
  return s == 1 ? x : -x;
}

/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
  if (write_pos == buf_size)
    fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
  write_buf[write_pos++] = x;
} 

inline void flush() {
  if (write_pos)
    fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
}

inline void writeInt(ll x ) {
  if (x < 0)
    writeChar('-'), x = -x;

  char s[24];
  int n = 0;
  while (x || !n)
    s[n++] = '0' + x % 10, x /= 10;
  while (n--)
    writeChar(s[n]);
}

inline void writeWord( const char *s ) {
  while (*s)
    writeChar(*s++);
}

vector <vector <int> > g;
pair<string, string> ar[1010];
string q[1010], w[1010];
int p[2010];
int used[2010];
set<string> buf;
inline void init(int &n, int &n1, int &n2) {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> ar[i].first >> ar[i].second;
	}
	buf.clear();
	for (int i = 0; i < n; ++i) {
		buf.insert(ar[i].first);
	}
	n1 = 0;
	for (auto it = buf.begin(); it != buf.end(); ++it, ++n1) {
		q[n1] = *it;
	}
	buf.clear();
	for (int i = 0; i < n; ++i) {
		buf.insert(ar[i].second);
	}
	n2 = 0;
	for (auto it = buf.begin(); it != buf.end(); ++it, ++n2) {
		w[n2] = *it;
	}
	g.clear();
	g.resize(n1 + n2);
	for (int i = 0; i < n; ++i) {
		int u = lower_bound(q, q + n1, ar[i].first) - q;
		int v = lower_bound(w, w + n2, ar[i].second) - w;
		v += n1;
		g[u].push_back(v);
	}
	return;
}

int col = 1;
inline int dfs_kun2(int v) {
	used[v] = col;
	for (int i = 0; i < (int)g[v].size(); ++i) {
		int to = g[v][i];
		if (p[to] == -1) {
			p[to] = v, p[v] = to;
			return 1;
		}
	}
	for (int i = 0; i < (int)g[v].size(); ++i) {
		int to = g[v][i];
		if (used[p[to]] != col && dfs_kun2(p[to])) {
			p[to] = v, p[v] = to;
			return 1;
		}
	}
	return 0;
}


int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
//	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
//	freopen("sociology.in", "r", stdin);freopen("sociology.out", "w", stdout);
	int qqq;
	cin >> qqq;
	for (int test = 1; test <= qqq; ++ test) {
		int n, n1, n2;
		init(n, n1, n2);
		memset(p, -1, sizeof(p));
		memset(used, 0, sizeof(used));
		col = 1;
		int ans = 0;
		for (int i = 0; i < n1; ++i) {
			if (dfs_kun2(i)) {
				++ans;
				++col;
			}
		}
		cout << "Case #" << test << ": " << n - (n1 + n2 - ans) << '\n';
	}

	//flush();
	return 0;
}