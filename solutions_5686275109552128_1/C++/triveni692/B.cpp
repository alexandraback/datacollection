/*
 	Beautiful Codes are MUCH better than 'Shorter' ones !
user  : triveni
date  : 11/04/2015
time  : 05:07:50
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
	int T, x;
	cin >> T;
	for(int tc = 1; tc <= T; ++tc){
		int D;
		cin >> D;
		vector<int> v(D);
		rep(i, D) {
			cin >> v[i];
			assert(1 <= v[i] and v[i] <= 1000);
		}
		int ans = *max_element(v.begin(), v.end());
		for(int h = 1; h <= 1000; ++h){
			int ct = 0, mx = 0;
			rep(i, D){
				ct += v[i] / h - (int)(v[i] % h == 0);
				if(v[i] >= h) mx = h; //Not needed though
				else mx = max(mx, v[i]);

			}
			ans = min(ans, ct + mx);
		}
		printf("Case #%d: %d\n",tc, ans);
	}
	return 0;
}
