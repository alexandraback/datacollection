//Aleksander "kaalex" Kramarz

#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#define f first
#define s second
using namespace std;

int z;
double p[100000], a, b;

int main()
{
	scanf("%d",&z);
	for(int i = 1; i <= z; i++)
	{
		scanf("%lf%lf",&a,&b);
		for(int j = 0; j < a; j++)
			scanf("%lf",p+j);
		double x = 1, res=b+2;
		for(int j = 0; j < a; j++)
		{
			x *= p[j];
			res = min(res,(a-j-1+b-j)*x + (a-j+b-j+b)*(1.0-x));
		}
		printf("Case #%d: %.6lf\n",i,res);
	}
}
