#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
using namespace std;

double val[100010];
double p[100010];

double sum[100010];
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);
	int T;
	int cas = 1;
	int a,b;
	cin>>T;
	while(T--)
	{
		cin>>a>>b;
		for(int i = 1 ; i <= a; i ++)
			cin>>p[i];
		double tmp = 1;
		for(int i = 1 ; i <= a; i ++ )
		{
			val[a-i+1] = tmp * (1.0 - p[i]);
			tmp = tmp * p[i];
		}
		val[0] = tmp;
// 		for(int i = 0; i <= a; i ++)
// 			cout<<val[i]<<endl;
		sum[0] = val[0];
		for(int i = 1; i <= a; i ++)
			sum[i] = sum[i-1] + val[i];
		double ans = b + 2;
		double x = b - a + 1;
		double y = b - a + 1 + b + 1;
		for(int i = 0; i <= a; i ++)
		{
			double cnt;
			if(i != a)
				cnt= sum[i]*x + y*(sum[a] - sum[i]);
			else
				cnt= sum[i]*x /*+ y * (a + 1 -i -1)*(sum[a] - sum[i+1])*/;
			ans = min(ans,cnt);
			x += 2;
			y += 2;
		}
		cout<<"Case #"<<cas++<<": ";
		cout<<ans<<endl;



	}
	return 0;
}