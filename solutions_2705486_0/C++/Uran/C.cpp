#ifdef SHTRIX 
#include "/Users/roman/Dev/SharedCpp/DebugOutput.h"
#endif
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <stack>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <memory>
using namespace std;
#define pb push_back
#define INF 1000000000
#define L(s) (int)((s).end()-(s).begin())
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define C(a) memset((a),0,sizeof(a))
#define ll long long
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define VI vector<int>
#define ppb pop_back
#define mp make_pair
#define pii pair<int,int>
#define pdd pair<double,double>
//#define x first
//#define y second
#define sqr(a) (a)*(a)
#define D(a,b) sqrt(((a).x-(b).x)*((a).x-(b).x)+((a).y-(b).y)*((a).y-(b).y))
#define pi 3.1415926535897932384626433832795028841971
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())

vector<string> vs;

int dp[55];

inline int nomatch(const string &a, const string &b) {
	int ans = 0, l = min(L(a), L(b));
	rept(i, l)
		if (b[i] != a[i]) ans++;
	return ans;
}

inline void solve(int case_id) {
	cerr << case_id << endl;
	string s;
	cin >> s;
	rept(len, L(s) + 1) {
		if (len == 0) {
			dp[len] = 0;
			continue;
		}
		dp[len] = INF;
		string left = s.substr(L(s) - len);
		rept(i, L(vs)) {
			if (L(vs[i]) > len) continue;
			dp[len] = min(dp[len], nomatch(left, vs[i]) + dp[len - L(vs[i])]);
		}
	}
    printf("Case #%d: %d\n", case_id, dp[L(s)]);
}

char buf[1111];

int main()
{
	freopen("garbled_email_dictionary.txt", "rt", stdin);
	while (gets(buf)) {
		vs.pb(string(buf));
	}
	cerr << "DONE: " << L(vs) << endl;
    #ifdef SHTRIX 
    freopen("input.txt","rt",stdin); 
    //freopen("output.txt","wt",stdout); 
    #endif
	
	int TC;
    scanf("%d", &TC);
    rep(tc, TC) solve(tc);
    return 0;
}
