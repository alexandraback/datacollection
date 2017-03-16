#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
#include <iterator>

using namespace std;

#define FOR(i,n) for (int i=0; i<n; ++i)
#define FORE(i,n) for (int i=0; i<=n; ++i)
#define REP(i,a,b) for (int i=a; i<b; ++i)
#define REPE(i,a,b) for (int i=a; i<=b; ++i)
#define mp make_pair
#define pb push_back

typedef long double dbl;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long int LL;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<VI> VVI;
const dbl pi = 3.14159265358979323846;
const int inf = (int) 1e9;
const dbl eps = 1e-9;

const int N = (int)1e6 + 5;

int dp[N];

int get(int v) {
	char c[10];
	itoa(v, c, 10);
	string x = c;
	reverse(x.begin(), x.end());
	return atoi(x.c_str());
}


void pre() {
	REP(i,1,N) {
		dp[i] = inf;
	}
	dp[1] = 1;
	REP(i,1,N - 1) {
		dp[i + 1] = min(dp[i + 1], dp[i] + 1);
		int x = get(i);
		if (x >= N) {
			continue;
		}
		/*if (dp[x] < dp[i] + 1 && x > i) {
			int z = 1;
		}*/
		dp[x] = min(dp[x], dp[i] + 1);
	}
}

int main()
{
#ifdef _DEBUG
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    //freopen("rotate-this.in","r",stdin);
    //freopen("rotate-this.out","w",stdout);
#endif
	int T;
	cin >> T;
	pre();
	FOR(TT,T) {
		int n;
		cin >> n;
		cout << "Case #" << TT + 1 << ": " << dp[n] << "\n";
	}
	return 0;
}