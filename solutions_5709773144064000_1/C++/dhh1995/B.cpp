#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(i,n) for (int i=0;i<n;++i)
typedef long long LL;
int T,Case; double C,F,X,v,s,ans;
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%lf%lf%lf",&C,&F,&X),v=2,ans=X/v,s=0;
		double Lim=(X*F-C*F)/C;
		for (int i=0;v<Lim;++i)
			s+=C/v,v+=F,ans=min(ans,s+X/v);
		printf("Case #%d: %.9lf\n",++Case,ans);
	}
	return 0;
}

