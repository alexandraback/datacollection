#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<cmath>
using namespace std;

#define debug(x) cout << #x << "=" << x << endl
#define sqr(x) ((x)*(x))

int T;
double C,F,X,S;

int main()
{
	freopen("b2.in","r",stdin);
	freopen("b2.out","w",stdout);
	int i,j,k;
	scanf("%d",&T);
	for (int cases=1;cases<=T;cases++)
	{
		scanf("%lf%lf%lf",&C,&F,&X);
		S = F*X / C;
		int n = (int)((S-2) / F);
		double ans = 0;
		double num = 2;
		for (i=0;i<n;i++,num += F)
		{
			ans += C / num;
		}
		ans += X / num;
		printf("Case #%d: %.8f\n", cases, ans);
	}
	return 0;
}
