#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <cstring>
#include <cmath>

using namespace std;

int tt;
int r,n,m,k;
int cnt[10];
int maxi[10];
int now;
int ans6;

void get(int x) {
	int e=cnt[x]*2;
	int ans=0;
	double res=(double)e/(double)k;
	for (int i=0;i<n;++i)
		if (fabs((double)i-res)<fabs((double)ans-res)) ans=i;
	ans=min(ans,maxi[x]);
	for (int i=0;i<ans;++i) printf("%d",x);
	now+=ans;
}

void get3() {
	int cc=maxi[3];
	double now1=1000,e=cnt[6]*2/(double)k;
	ans6=0;
	for (int i=0;i<=cc;++i) {
		double exp=(double)i/2.0;
		double p1=(cnt[2]*2/(double)k-i);
		double p2=(cnt[3]*2/(double)k-i);
		if (p1<-0.1 || p2<-0.1) continue;
		exp+=min(p1,p2)/2;
		if (fabs(exp-e)<now1) {
			now1=fabs(exp-e);
			ans6=i;
		}
	}
	ans6=min(ans6,maxi[6]);
	for (int i=0;i<ans6;++i) printf("6");
	for (int i=0;i<cc-ans6;++i) printf("3");
	now+=cc;
}

void get2() {
	int a[12];
	for (int i=0;i<n-now;++i) a[i]=2;
	int cc1=maxi[2]-ans6;
	cc1-=(n-now);
	if (cc1>0)
		for (int i=0;i<n-now && cc1>0;++i,cc1--) a[i]*=2;
	if (cc1>0)
			for (int i=0;i<n-now && cc1>0;++i,cc1--) a[i]*=2;
	for (int i=0;i<n-now;++i) printf("2");
}

int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);

	scanf("%d",&tt);
	for (int ii=1;ii<=tt;++ii) {
		scanf("%d%d%d%d",&r,&n,&m,&k);
		printf("Case #1:\n");
		for (int i=0;i<r;++i) {
			memset(cnt,0,sizeof(cnt));
			memset(maxi,0,sizeof(maxi));
			for (int j=0;j<k;++j) {
				int x;
				scanf("%d",&x);
				for (int p=2;p<=8;++p) {
					int ff=x;
					int cc=0;
					while (ff%p==0) cnt[p]++,ff/=p,cc++;
					maxi[p]=max(maxi[p],cc);
				}
			}
			now=0;
			get(5);
			get(7);
			get3();
			get2();
			printf("\n");
		}
	}
}
