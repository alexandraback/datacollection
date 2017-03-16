#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define FOR(i,l,r) for(int i=(l);i<=(r);i++)
using namespace std;
typedef long long LL;
const int maxn=100001;

int main() {
	int T; scanf("%d",&T);
	for (int tt=1;tt<=T;tt++) {
		LL k,c,s; scanf("%lld%lld%lld",&k,&c,&s);
		printf("Case #%d: ",tt);

		/*if (c==1) {
			if (s!=k)
				puts("IMPOSSIBLE");
			else
				for (int i=1;i<=k;i++) printf("%d%c",i,i==k?10:32);
			continue;
		}

		vector<LL> ans;
		LL lev=1,pos=1;
		for (int i=1;i<=k;i++) {
			lev++;
			pos=(pos-1)*k+i+1;
			if (lev==c) {
				lev=1;
				ans.pb(pos); pos=i+1;
			}
		}
		if (lev!=1) {
			while (lev!=c) {
				lev++;
				pos=pos*c;
			}
			ans.pb(pos);
		}*/
		vector<LL> ans;
		LL i=1,pos=1,lev=1;
		while (i<=k) {  //当前的i值是已经走过的i值
			if (lev==c) {
				ans.pb(pos);
				if (i==k) break;
				
				i=i+1;
				pos=i;
				lev=1;
				continue;
			}
			if (i==k) {
				while (lev!=c) lev++,pos*=k;
				ans.pb(pos);
				break;
			}
			lev++;
			i++;
			pos=(pos-1)*k+i;
		}
		if ((LL)ans.size()>s)
			puts("IMPOSSIBLE");
		else
			for (int i=0;i<(int)ans.size();i++)
				printf("%lld%c",ans[i],i==ans.size()-1?10:32);
	}
	return 0;
}

/*
	碎碎念：
		每次走的是C-1步，但是能检查C块。
*/