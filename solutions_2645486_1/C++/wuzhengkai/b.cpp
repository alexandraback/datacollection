#include <iostream>
#include <cstdio>
#include <cstdlib>
#define LL long long

using namespace std;

int tt;
int e,r,n;
int v[10010];
LL ans;

LL solve(int st,int ed,int fi,int la) {
	if (st>ed) return 0;
	int k=st;
	for (int i=st+1;i<=ed;++i)
		if (v[i]>v[k]) k=i;
	int cur=(int)min((LL)fi+(LL)r*(LL)(k-st),(LL)e);
	int cap=cur;
	if ((LL)r*(LL)(ed-k+1)<(LL)la) cur-=la-r*(ed-k+1);
	LL ans=(LL)cur*(LL)v[k];
	if (st==ed) return ans;
	ans+=solve(st,k-1,fi,cap);
	ans+=solve(k+1,ed,min(e,cap-cur+r),la);
	return ans;
}

int main() {
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);

	scanf("%d",&tt);

	for (int ii=1;ii<=tt;++ii) {
		scanf("%d%d%d",&e,&r,&n);
		for (int i=0;i<n;++i) scanf("%d",&v[i]);
		ans=solve(0,n-1,e,0);
		printf("Case #%d: ",ii);
		cout << ans << endl;
	}
}

