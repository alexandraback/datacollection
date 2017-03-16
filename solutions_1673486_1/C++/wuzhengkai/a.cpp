#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <map>
#define LL long long
#define pb push_back
#define mp make_pair
#define maxn 100010

using namespace std;

int n,m;
double a[maxn];
double f[maxn][2];
double p[maxn];
double q[maxn];
int tt;

int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);

	scanf("%d",&tt);
	for (int ii=1;ii<=tt;++ii) {
		scanf("%d%d",&n,&m);
		for (int i=0;i<n;++i) scanf("%lf",&a[i]);
		f[n][1]=1; f[n][0]=0;
		for (int i=n-1;i>=0;--i)
			f[i][1]=(f[i-1][1]+f[i-1][0])*(1-a[i]),f[i][0]=(f[i-1][1]+f[i-1][0])*a[i];
		p[0]=a[0];
		for (int i=1;i<n;++i) p[i]=p[i-1]*a[i];
		double ans=m+2;
		ans=min((1-p[n-1])*(double)(m-n+m+2)+p[n-1]*(double)(m-n+1),ans);
		for (int i=0;i<n;++i) {
			double pp=1;
			if (i!=0) pp=p[i-1];
			ans=min(ans,pp*(2*(n-i)+m-n+1)
					+(1-pp)*(2*(n-i)+m-n+1+m+1));
		}

		printf("Case #%d: %.8lf\n",ii,ans);
	}
	return 0;
}
