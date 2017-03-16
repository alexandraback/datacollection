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


const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
inline void * operator new ( size_t n ) {
  char *res = mem + mpos;
  mpos += n;
  assert(mpos <= MAX_MEM);
  return (void *)res;
}
inline void operator delete ( void * ) { }

inline void * operator new [] ( size_t ) { assert(0); }
inline void operator delete [] ( void * ) { assert(0); }


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


inline ll bin_pow(ll a, ll p, ll mod) {
	ll ans = 1;
	while (p) {
		if (p  & 1) {
			ans *= a;
			ans %= mod;
		}
		a *= a;
		a %= mod;
		p >>= 1;
	}
	return ans;
}
inline int check(ll a) {
	if (a & 1LL) {
		ll q = bin_pow(2, a - 1, a);
		if (q != 1)
			return 0;
		for (ll i = 3; i * i * i <= a; ++i) {
			if (a % i == 0)
				return 0;
		}
		return 1;
	}
	else {
		if (a == 2)
			return 1;
		return 0;
	}
	return 1;
}
inline ll check2(ll a) {
	if (check(a))
		return 0;
	for (ll i = 2; i * i <= a; ++i) {
		if (a % i == 0)
			return i;
	}
}
inline ll get_num(string &s, ll osn) {
	ll ans = 0;
	for (int i = 0; i < (int)s.size(); ++i) {
		ans *= osn;
		if (s[i] == '1')
			++ans;
	}
	return ans;
}
inline int next_str(string &s) {
	int i = (int)s.size() - 1;
	for (; i >= 0; --i) {
		if (s[i] == '0')
			break;
	}
	if (i == -1)
		return 0;
	s[i] = '1';
	for (++i; i < (int)s.size(); ++i) {
		s[i] = '0';
	}
	s.back() = '1';
	return 1;
}
inline int prev_str(string &s) {
	int i = (int)s.size() - 2;
	for (; i > 0; --i) {
		if (s[i] == '1')
			break;
	}
	if (i == -1)
		return 0;
	s[i] = '0';
	for (++i; i < (int)s.size(); ++i) {
		s[i] = '1';
	}
	return 1;
}
inline int rnd_str(string &s) {
	for (int i = 0; i < (int)s.size(); ++i) {
		if (rand() & 1)
			s[i] = '1';
	}
	s[0] = s.back() = '1';
	return 1;
}
int mod[5][100][100];
int dp[100][100];
int prime[] = {2, 3, 5, 7, 11};
int sum[5];
ll ans[11];
inline void cout_mask(int mask, int n) {
	for (int i = n - 1; i >= 0; --i) {
		if (mask & (1 << i))
			cout << 1;
		else
			cout << 0;
	}
	cout << ' ';
	return;
}
inline void clear1() {
	for (int i = 0; i < 100; ++i) {
		memset(dp[i], 0, sizeof(dp[i]));
	}
	return;
}
inline void solve_small(int n, int count, int test) {
	cout << "Case #" << test << ":\n";
	string s;
	s.resize(n, '0');
	s[0] = s[n - 1] = '1';
	int	a = 1;
	while (a && count) {
		int flag = 1;
		for (int j = 2; j <= 10 && flag; ++j) {
			ll a = check2(get_num(s, j));
			if (!a) {
				flag = 0;
			}
			else {
				ans[j] = a;
			}
		}
		if (flag) {
			--count;
			cout << s << ' ';
			for (int i = 2; i <= 10; ++i) {
				cout << ans[i] << ' ';
			}
			cout << '\n';
		}
		a = next_str(s);
	}
	return;
}
inline void solve_big(int n, int count, int test) {
	cout << "Case #" << test << ":\n";
	for (int mask = 1 << (n - 1); count && mask != (1 << n); ++mask) {
		if (mask & 1) {
			int flag = 1;
			for (int i = 2; i <= 10 && flag; ++i) {
				for (int j = 0; j < 5; ++j) {
					sum[j] = 0;
				}
				for (int j = 0; j < n; ++j) {
					if (mask & (1 << j)) {
						for (int k = 0; k < 5; ++k) 
							sum[k] += mod[k][i][j];
					}
				}
				for (int j = 0; j < 5; ++j)
					sum[j] %= prime[j];
				int w = 0;
				for (int j = 4; j >= 0; --j)
					if (!sum[j])
						w = prime[j];
				if (!w)
					flag = 0;
				else
					ans[i] = w;
			}
			if (flag) {
				--count;
				cout_mask(mask, n);
				for (int i = 2; i < 11; ++i) {
					cout << ans[i] << ' ';
				}
				cout << '\n';
			}
		}
	}
	return;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
//	freopen("tdsum.in", "r", stdin);freopen("tdsum.out", "w", stdout);
	/*for (int i = 1; i <= 32; ++i) {
		cout << i << ' ' << 500 << '\n';
	}
	return 0;*/
	const int pr = 17;
	for (int q = 0; q < 5; ++q) {
		for (int i = 2; i <= 10; ++i) {
			int a = 1;
			for (int j = 0; j < 32; ++j) {
				mod[q][i][j] = a;
				a *= i;
				a %= prime[q];
			}
		}
	}
	int test;
	cin >> test;
	for (int q = 1; q <= test; ++q) {
		int n, count;
		cin >> n >> count;
		if (n < 14) {
			solve_small(n, count, q);
		}
		else {
			solve_big(n, count, q);
		}
	}
	//flush();
	return 0;
}