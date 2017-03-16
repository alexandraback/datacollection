/*
 	Beautiful Codes are MUCH better than 'Shorter' ones !
user  : triveni
date  : 11/04/2015
time  : 04:41:17
*/
#include <bits/stdc++.h>

using namespace std;

#define      pii               std::pair<int,int>
#define      vi                std::vector<int>
#define      mp(a,b)           std::make_pair(a,b)
#define      pb(a)             std::push_back(a)
#define      each(it,s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      rep(i, n)         for(int i = 0; i < (n); ++i)
#define      fill(a)           memset(a, 0, sizeof (a))
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.begin(), v.end(), greater<auto>())
#define      X                 first
#define      Y                 second

typedef long long LL;
LL MOD = 1000000007;

int main()
{
	int T;
	cin >> T;
	for(int tc = 1; tc <= T; ++tc){
		int n;
		string s;
		cin >> n >> s;
		vector<int> v(n+1, 0);
		v[0] = s[0] - '0';
		rep(i, n) v[i+1] = v[i] + s[i+1] - '0';
		int add = 0;
		for(int i = 1; i <= n; ++i){
			if(v[i-1] + add >= i) continue;
			else add += i - (v[i-1] + add);
		}
		printf("Case #%d: %d\n",tc, add);
	}
	return 0;
}
