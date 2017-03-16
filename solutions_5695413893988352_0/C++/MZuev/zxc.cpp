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



#include <cassert>

/** Begin fast allocation */
const int MAX_MEM = 6e7;
int mpos = 0;
char mem[MAX_MEM];
inline void * operator new ( size_t n ) {
  char *res = mem + mpos;
  mpos += n;
  assert(mpos <= MAX_MEM);
  return (void *)res;
}
inline void operator delete ( void * ) { }
/** End fast allocation */

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
struct res{
	ll del;
	string a, b;
	res(){}
	res(ll a) {
		del = a;
	}
	res(ll del, string &a, string &b) : del(del), a(a), b(b) {}
};
res ar[310];
inline string merge1(string &s, int a) {
	return s + (char)('0' + a);
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
//	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
//	freopen("sociology.in", "r", stdin);freopen("sociology.out", "w", stdout);
	int qqq;
	cin >> qqq;
	for (int test = 1; test <= qqq; ++ test) {
		string a, b;
		cin >> a >> b;
		res q(0), w(0), nul(1);
		int n = (int)a.size();
		for (int i = 0; i < n; ++i) {
			q.del *= 10;
			w.del *= 10;
			for (int z = 0; z < 10; ++z) {
				int num1 = z;
				if (a[i] != '?')
					num1 = a[i] - '0';
				for (int x = 0; x < 10; ++x ){
					int num2 = x;
					if (b[i] != '?')
						num2 = b[i] - '0';
					ll t = num1 - num2;
					int pos = (z * 10 + x) * 3;
					ar[pos] = ar[pos + 1] = ar[pos + 2] = infl;
					if (q.del) {
						ar[pos] = res(q.del + t,merge1(q.a, num1), merge1(q.b, num2));
					}
					if (w.del) {
						ar[pos + 1] = res(w.del + t, merge1(w.a, num1), merge1(w.b, num2));
					}
					if (nul.del) {
						ar[pos + 2] = res(t, merge1(nul.a, num1), merge1(nul.b, num2));
					}
				}
			}
			int ans = -1;
			for (int j = 0; j < 300; ++j) {
				if (ar[j].del == 0) {
					if (ans == -1) {
						ans = j;
						continue;
					}
					if (ar[ans].a > ar[j].a || ar[ans].a == ar[j].a && ar[ans].b > ar[j].b) {
						ans = j;
					}
				}
			}
			if (ans == -1) {
				nul = res(0);
			}
			else{
				nul = ar[ans];
				nul.del = 1;
			}
			ans = -1;
			for (int j = 0; j < 300; ++j) {
				if (ar[j].del > 0) {
					if (ans == -1) {
						ans = j;
						continue;
					}
					if (ar[j].del < ar[ans].del) {
						ans = j;
						continue;
					}
					if (ar[j].del > ar[ans].del)
						continue;
					if (ar[ans].a > ar[j].a || ar[ans].a == ar[j].a && ar[ans].b > ar[j].b) {
						ans = j;
					}
				}
			}
			if (ans == -1) {
				q = res(0);
			}
			else {
				q = ar[ans];
			}
			ans = -1;
			for (int j = 0; j < 300; ++j) {
				if (ar[j].del < 0) {
					if (ans == -1) {
						ans = j;
						continue;
					}
					if (ar[j].del > ar[ans].del) {
						ans = j;
						continue;
					}
					if (ar[j].del < ar[ans].del)
						continue;
					if (ar[ans].a > ar[j].a || ar[ans].a == ar[j].a && ar[ans].b > ar[j].b) {
						ans = j;
					}
				}
			}
			if (ans == -1) {
				w = res(0);
			}
			else {
				w = ar[ans];
			}
		}
		cout << "Case #" << test << ": ";
		if (nul.del) {
			cout << nul.a << ' ' << nul.b << '\n';
			continue;
		}
		if (q.del == -w.del) {
			if (q.a < w.a || q.a == w.a && q.b < w.b) {
				cout << q.a << ' ' << q.b << '\n';
			}
			else {
				cout << w.a << ' ' << w.b << '\n';
			}
			continue;
		}
		if (!w.del || q.del && q.del < -w.del) {
			cout << q.a << ' ' << q.b << '\n';
		}
		else {
			cout << w.a << ' ' << w.b << '\n';
		}
	}

	//flush();
	return 0;
}