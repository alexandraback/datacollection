#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#define MIN(x,y) (x)<(y)?(x):(y)
using namespace std;

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	for(int cnt=1;cnt<=t;cnt++)
	{
		double c,f,x;
		scanf("%lf%lf%lf",&c,&f,&x);
		
		double ans = 0;
		double rate = 2, lx = x;
		while(1)
		{
            if(lx/rate > c/rate+lx/(rate+f))
            {
                ans += c/rate;
                rate += f;
            }
            else
            {
                ans += lx/rate;
                break;
            }
		}
		
		printf("Case #%d: %.7lf\n",cnt,ans);
	} 
} 
