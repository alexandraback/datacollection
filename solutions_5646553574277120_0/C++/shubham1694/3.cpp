#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define inf 1000000000
#define maxn 1000000

#define ll long long
#define pii pair<int, int>
#define pb push_back
#define sin scanint
#define bitcount(x) __builtin_popcount(x)
#define fill(s, p) memset(s, p, sizeof(s));
#define gc getchar

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}


vector<int> v1[40];
vector<int> v2;
int dp[40], arr[40], seen[40], cnt[40];

int main()
{
	#ifndef ONLINE_JUDJE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int t, c, ca = 1, d, v, i, j, k, s, add, mcnt, mno;
	sin(t);
	while(t--){
		add = 0;
		for(i=0; i<32; i++){
			v1[i].clear();
			cnt[i] = 0;
			dp[i] = 0;
			seen[i] = 0;
		}
		sin(c);
		sin(d);
		sin(v);
		for(i=0; i<d; i++){
			sin(arr[i]);
			seen[arr[i]] = 1;
		}
		for(i=1; i<=d; i++){
			for(j=0; j<(1<<d); j++){
				if(bitcount(j)!=i)
					continue;
				s = 0;
				for(k=0; k<d; k++){
					if(j&(1<<k))
						s+=arr[k];
				}
				dp[s] = 1;
			}
		}
		for(i=1; i<=v; i++){
			if(dp[i]==0){
				add++;
				v2.clear();
				for(j=1; j<=v; j++){
					if(dp[j]==1)
						v2.pb(j+i);
				}
				for(j=0; j<v2.size(); j++)
					dp[v2[j]] = 1;
				dp[i] = 1;
			}
		}
		printf("Case #%d: %d\n", ca++, add);
	}
	return 0;
}