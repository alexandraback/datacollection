#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int v[20000],d[20000];
long long e,r,ans,tmp,now,gao;
int testcase,test,n;

int main() {
	int i,j;
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&testcase);
	for (test=1;test<=testcase;test++) {
		cin>>e>>r>>n;
		for (i=1;i<=n;i++) scanf("%d",v+i);
		v[n+1]=1000000000;
		for (i=1;i<=n;i++)
			for (j=i+1;j<=n+1;j++)
				if (v[i]<v[j]) {
					d[i]=j;
					break;
				}
		now=e;
		ans=0;
		for (i=1;i<=n;i++,now=min(now+r,e)) {
			if (d[i]==n+1) {
				ans+=now*v[i];
				now=0;
				continue;
			}
			if (now+(d[i]-i)*r<=e) {
				continue;
			}
			tmp=now+(d[i]-i)*r-e;
			gao=min(tmp,now);
			ans+=gao*v[i];
			now-=gao;
		}
		printf("Case #%d: %I64d\n",test,ans);			
	}
}
