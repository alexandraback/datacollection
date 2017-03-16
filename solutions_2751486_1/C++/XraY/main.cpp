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

#define TASKNAME "text"
#define pb push_back
#define mp make_pair
#define EPS (1e-9)
#define INF ((int)1e9)
#define sqr(x) ((x) * (x))         
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())

const int maxn = (int)1e6 + 1;
char s[maxn];
int go[maxn];

inline bool isVowel(char ch) {
	return (ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u');
}

void solve(int &testCase) {
	int k;	
  scanf("%s%d", s, &k);
	int n = strlen(s);

	int lastd = 0;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int cur = !isVowel(s[i]);
		go[i] = cur ? (i ? go[i - 1] : i - 1) : i;
		if (i - go[i] >= k)
			lastd = i - k + 2;
		ans += lastd;
		//eprintf("lastd = %d\n", lastd);
	}

	printf("Case #%d: %I64d\n", ++testCase, ans);
}

int main() {
	srand(rdtsc());
#ifdef DEBUG
	freopen(TASKNAME".in", "r", stdin);
	freopen(TASKNAME".out", "w", stdout);
#endif
	
	int testCase = 0;
	int maxt;
	while (scanf("%d", &maxt) >= 1) {
		for (int iter = 0; iter < maxt; iter++)
			solve(testCase);
		//break;
	}
	return 0;
}
