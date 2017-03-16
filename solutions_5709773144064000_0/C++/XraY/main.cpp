#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cassert>
#include <ctime>


using namespace std;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

typedef long double ld;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll rdtsc() {
    ll tmp;
    asm("rdtsc" : "=A"(tmp));
    return tmp;
}

inline int myrand() {
	return abs((rand() << 15) ^ rand());
}

inline int rnd(int x) {
	return myrand() % x;
}

#define TASKNAME "text"
#define pb push_back
#define mp make_pair
#define EPS (1e-9)
#define INF ((int)1e9)
#define sqr(x) ((x) * (x))         
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())

const int maxt = 6;
const int tens[maxt] = {1, 10, 100, 1000, 10000, 100000};
long long shift = (int)1e5;
char s[100];

int getValue(char *s, int len) {
	int res = 0;
	for (int i = 0; i < len; ++i)
		res = res * 10 + s[i] - '0';
	return res;
}

bool readLong(long long &res) {
    if (scanf("%s", s) < 1)
    	return 0;
    int len = strlen(s);
    int pos = find(s, s + len, '.') - s;
    assert(pos < len);
   	assert(len - pos - 1 < maxt);
   	res = (long long)getValue(s, pos) * tens[len - pos - 1] + getValue(s + pos + 1, len - pos - 1);
    res *= shift / tens[len - pos - 1];
    return 1;
}

bool solve(int testCase) {
	printf("Case #%d: ", testCase);
	long long c, f, x;
	assert(readLong(c) && readLong(f) && readLong(x));
	long long v = shift * 2;
	double res = 0;
	while (1) {
		if (f * (x - c) > c * v) {
			res += (double)c / v;
			v += f;
			continue;
		}
		res += (double)x / v;
		break;	
	}

	printf("%.18lf\n", res);
	return 1;
}

int main() {
	srand(rdtsc());
#ifdef DEBUG
	freopen(TASKNAME".in", "r", stdin);
	freopen(TASKNAME".out", "w", stdout);
#endif
	
	int maxt;
	while (scanf("%d", &maxt) == 1) {
		for (int t = 0; t < maxt; ++t)
			assert(solve(t + 1));
		
		#ifdef DEBUG
			eprintf("%.18lf\n", (double)clock() / CLOCKS_PER_SEC);
		#endif
	}
	return 0;
}
