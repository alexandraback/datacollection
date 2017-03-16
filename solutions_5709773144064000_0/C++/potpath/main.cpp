#include<cstdio>
int main()
{
	int T;
	long double c,f,x;
	scanf("%d",&T);
	for (int iT=1;iT<=T; ++iT) {
		long double ans=0,r=2;
		scanf("%Lf%Lf%Lf",&c,&f,&x);
		int n=(f*x/c-2)/f;
		for (int i=0; i<n; ++i) {
			ans+=c/r;
			r+=f;
		}
		printf("Case #%d: %.7Lf\n",iT,ans+x/r);
	}
    return 0;
}

