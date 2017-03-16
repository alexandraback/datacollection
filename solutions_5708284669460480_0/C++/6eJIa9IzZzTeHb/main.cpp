#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <vector>
#include <ctime>
#include <cstring>
#include <sstream>

//#include <unordered_map>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, pii> ppii;
typedef vector<int> vi;


#define SI(n) scanf("%d", &n)
#define SII(x, y) scanf("%d%d", &x, &y)
#define SIII(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define SD(n) scanf("%lf", &n)
#define SPII(n) scanf("%d%d", &n.first, &n.second)
#define FI(n) for (int i=0; i<n; i++)
#define FJ(n) for (int j=0; j<n; j++)
#define WS(n) while(SI(n) != EOF && n)
#define DB(n) cout<<#n<<" = "<<n<<" ";
#define DBN(n) cout<<#n<<" = "<<n<<"\n";
#define FIX(n) cout.precision(2), cout.setf(cout.fixed)
#define PI(n) printf("%d", n)
#define SPACE() putchar(' ')
#define ENDL() putchar('\n')
#define in_count(a, n, x) (upper_bound(a, a+n, x) - lower_bound(a, a+n, x) + 1)


#define x first
#define y second

const int N = 200010;


typedef pair < ll, char > plc;


char keys[101];
char need[101];
char curstr[101];


bool equal(int start, int L, int S) {
	if (start + L > S)
		return false;
	for (int i = 0; i < L; i++)
		if (need[i] != curstr[i + start])
			return false;
	return true;
}

int mx = 0;
double m = 0;
void dfs(int st, double p, int K, int L, int S) {
	if (st == 0) {
		int count = 0;
		for (int i = 0; i < S; i++)
			count += equal(i, L, S);
		m += count * p;

		mx = max(mx, count);
		return;
	}

	for (int i = 0; i < K; i++) {
		curstr[S - st] = keys[i];
		dfs(st - 1, p*1.0 / K, K, L, S);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	SI(t);
	for (int i=1; i<=t; i++) {
		int K, L, S;
		SIII(K, L, S);
		scanf("%s", &keys);
		scanf("%s", &need);
		m = 0;
		mx = 0;
		dfs(S, 1.0, K, L, S);
		cout.precision(7);
		cout.setf(cout.fixed);
		printf("Case #%d: ", i);
		cout << mx - m << endl;
	}


	cin.get(); cin.get();
	return 0;
}