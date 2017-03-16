#include <vector>
#include <numeric>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <limits>
#include <iomanip>

using namespace std;

#define FOR(i,a,b)		for(int i=(a),_b=(b);i<(_b);++i)
#define FORD(i,a,b)		for(int i=(a),_b=(b);i>(_b);--i)
#define pb			push_back
#define mp			make_pair
#define	all(c)			(c).begin(),(c).end()
#define	tr(c,i)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define	present(c,x)		((c).find(x) != (c).end())
#define	cpresent(c,x)		(find(all(c),x) != (c).end())

typedef long long			ll;
typedef unsigned long long	ull;
typedef unsigned char	 	byte;
typedef vector<int>			vi;
typedef pair<int, int>		pii;
typedef pair<ll, ll>		pll;
typedef vector<pii>			vpii;

const int MX = 101;

int a[MX];

map<pii,int> dp;

int solve(int A, int k, int n)
{
	if (k == n) return 0;
	if (present(dp,pii(A,k))) return dp[pii(A,k)];
	if (A > a[k]) return dp[pii(A,k)] = solve(A+a[k],k+1,n);
	else {
		int cnt = 0, s = A;
		if (s-1 <= 0) return dp[pii(A,k)] = n-k;
		while (s <= a[k]) {
			s += s-1;
			++cnt;
		}
		return dp[pii(A,k)] = min(cnt+solve(s,k,n), solve(A,k+1,n)+1);
	}
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen(argv[1],"r",stdin);
#endif
#ifndef ONLINE_JUDGE
	ifstream cin(argv[1]);
#endif
#if 1
	ofstream cout(argv[2]);
#endif
	int T;
	cin >> T;
	int A,n;
	FOR(t,1,T+1) {
		cin >> A >> n;
		FOR(i,0,n) cin >> a[i];
		sort(a,a+n);
		dp.clear();
		cout << "Case #" << t << ": " << solve(A,0,n) << endl;
	}
	return 0;
}
