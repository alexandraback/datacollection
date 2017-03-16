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

void out(int ans, int test) {
	writeWord("Case #");
	writeInt(test);
	writeWord(": ");
	if (ans == -1) {
		writeWord("INSOMNIA\n");
	}
	else {
		writeInt(ans);
		writeChar('\n');
	}
	return;
}
int used[10];
int dp[1000500];

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
//	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
//	freopen("tdsum.in", "r", stdin);freopen("tdsum.out", "w", stdout);
	int t = readInt();
	for (int q = 0; q < t; ++q) {
		int n = readInt();
		if (n == 0) {
			out(-1, q + 1);
			continue;
		}
		if (dp[n]) {
			out(dp[n], q + 1);
			continue;
		}
		for (int i = 0 ; i < 10; ++i)
			used[i] = 0;
		int w = 0;
		int e = n;
		while (1) {
			int a = e;
			while (a) {
				int b = a % 10;
				if (!used[b])
					used[b] = 1, ++w;
				a /= 10;
			}
			if (w == 10)
				break;
			e += n;
		}
		dp[n] = e;
		out(e, q + 1);
	}

	flush();
	return 0;
}