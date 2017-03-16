/*
  Beautiful Codes are MUCH better than 'Shorter' ones !
user  : triveni
date  : 16/04/2016
time  : 07:15:27
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
		string s;
		cin >> s;
		int n = s.length();
		string ans;
		for(int i = 0; i < n; ++i) {
			if(ans.length() == 0 || s[i] >= ans[0]) ans = s[i] + ans;
			else ans += s[i];
		}
		printf("Case #%d: ", tc);
		cout << ans << "\n";
	}
	return 0;
}
