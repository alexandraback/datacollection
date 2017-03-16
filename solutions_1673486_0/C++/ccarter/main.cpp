#include <iostream>

using namespace std;

double poss[100010];
double mul[100010];
int main()
{
	int tt;
	scanf("%d",&tt);
	for (int ttt=1;ttt<=tt;ttt++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		for (int i=0;i<a;i++)
			scanf("%lf",&poss[i]);
		mul[0]=poss[0];
		for (int i=1;i<a;i++)
			mul[i]=mul[i-1]*poss[i];
		mul[a]=mul[a-1];
		double least = 9999999999.0;
		for (int i=0;i<a;i++)
		{
			double tmp = mul[i]*((a-i-1)+(b-i-1)+1)+(1-mul[i])*(((a-i-1)+(b-i-1)+1)+b+1);
			if (tmp<least) least = tmp;
		}
		if (least > (2+b)) least = 2+b;
		printf("Case #%d: %.6lf\n",ttt,least);
	}
    return 0;
}
