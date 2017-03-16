#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long LL;

const int maxn	=	10005;

int E,R,N,v[maxn];
LL x[maxn],l[maxn],y[maxn];

int main()
{
	int T,test=1;
	for (scanf("%d",&T);test<=T;++test){
		scanf("%d%d%d",&E,&R,&N);
		if (R>E) R=E;
		for (int i=0;i<N;++i){
			scanf("%d",&v[i]);
		}
		l[0]=R;
		x[0]=E;
		for (int i=1;i<N;++i){
			x[i]=R;
			l[i]=R;
			LL ma = R;
			for (int j=i-1;j>=0;--j){
				ma=max(ma,l[j]);
				LL delta = min(x[j], E-ma);
				if (v[j]>v[i]){
					delta=0;
				}
				x[i] += delta;
				y[j] = delta;
				ma += delta;
			}
			LL sum=0;
			for (int j=0;j<i;++j){
				sum+=y[j];
				x[j]-=y[j];
				l[j]+=sum;
			}
/*for (int j=0;j<=i;++j){
	cout << l[j] << ", " << x[j] << endl;
}
cout << endl;*/
		}
		LL ans=0;
		for (int i=0;i<N;++i){
			ans+=x[i]*v[i];
		}
		cout << "Case #" << test << ": " << ans << endl;
	}
	return 0;
}
