/*
  Beautiful Codes are MUCH better than 'Shorter' ones !
user  : triveni
date  : 16/04/2016
time  : 07:31:20
*/
#include <bits/stdc++.h>

using namespace std;

#define      pii               std::pair<int,int>
#define      vi                std::vector<int>
#define      mp(a,b)           make_pair(a,b)
#define      pb(a)             push_back(a)
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
	scanf("%d", &T);
	for(int tc = 1; tc <= T; ++tc) {
		int n;
		cin >> n;
		vector<int> cnt(2501, 0);
		rep(i, 2*n-1) {
			rep(j, n) {
				int x;
				scanf("%d", &x);
				cnt[x] += 1;
			}
		}
		vector<int> ans;
		for(int i = 1; i <= 2500; ++i) {
			if(cnt[i] % 2) ans.push_back(i);
		}
		assert(ans.size() == n);
		printf("Case #%d: ", tc);
		for(int x : ans) cout << x << " ";
		cout << "\n";
	}
	return 0;
}
