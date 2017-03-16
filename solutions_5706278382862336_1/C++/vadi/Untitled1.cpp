#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for(int j=1;j<=t;j++)
	{
		long long  a,b;
		scanf("%lld/%lld",&a,&b);
		long long h=__gcd(a,b);
		a/=h;
		b/=h;
		double g;
		g=(double)a/b*2;
	//	cout<<a<<" "<<b<<" "<<g<<" ";
		printf("Case #%d: ",j);
		if(b && (!(b&(b-1))))
		{
			for(int i=0;i<=40;i++)
			{
				if(g>=(1/pow(2,i)))
				{
					printf("%d\n",i+1);
					break;
				}
			}
		}
		else 
			printf("impossible\n");
			
	}
	return 0;
}
