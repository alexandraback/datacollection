#include<stdio.h>
#include<algorithm>
using std::min;
double fix[100005];
int main()
{
	freopen("in.in","r",stdin);
	freopen("out.txt","w",stdout);
	int c;
	scanf("%d",&c);
	for(int cs = 1; cs <= c; ++cs)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i = 1; i <= a; ++i)
			scanf("%lf",&fix[i]);
		double ans = b + 2;
		double tmp = 1.0;
		for(int i = 1; i <= a; ++i)
			tmp *= fix[i];
		double tmp2 = tmp*(-a+b+1) + (1-tmp)*(-a+b+b+2);
		ans = min(ans, tmp2);
		for(int i = 1; i <= a; ++i)
		{
			tmp = (i == 1) ? (1) : (tmp*fix[i-1]);
			tmp2 = tmp*(a+b-i-i+3) + (1-tmp)*(a+b+b-i-i+4);
			ans = min(ans, tmp2);
		}
		printf("Case #%d: %.6lf\n", cs, ans);
	}
	return 0;
}
