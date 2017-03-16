#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 2505

int t;
int cnt[MAX], n;

int main()
{
	scanf("%d", &t);
	for(int tc=1; tc<=t; ++tc)
	{
		memset(cnt, 0, sizeof(cnt));
		
		scanf("%d", &n);
		for(int i=0; i<2*n-1; ++i)
			for(int j=0; j<n; ++j)
			{
				int x; scanf("%d", &x);
				cnt[x]++;
			}
		
		vector<int> v;	
		for(int i=1; i<MAX; ++i)
			if(cnt[i] & 1)
				v.pb(i);
		sort(v.begin(), v.end());
		
		printf("Case #%d:", tc);
		for(int i=0; i<n; ++i) printf(" %d", v[i]);
		puts("");
	}

	return 0;
}
