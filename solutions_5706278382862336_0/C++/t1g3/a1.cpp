#include <iostream>
#include <cstdio>
using namespace std;

char a[1005];

int main() 
{
	int i,j,k,t,ca=0,p,q;
	double d1,d2;
	scanf("%d",&t);
	while(t--)
	{
		++ca;
		scanf("%s",a);
		p=q=0;
		for(i=0;a[i]!='/';++i)
		{
			p=p*10+(a[i]-'0');
		}
		for(i=i+1;a[i];++i)
		{
			q=q*10+(a[i]-'0');
		}
		k=q-1;
		int n=q&k; 
		if(n==0)
		{
			j=2; k=1;
			d1=(double)p/(double)q; d2=1.0/(double)j;
			while(1)
			{
				if(d1>=d2)
				{
					break;
				}
				++k; j=j<<1; d2=1.0/(double)j;
			}
			printf("Case #%d: %d\n",ca,k);
		}
		else
		{
			printf("Case #%d: impossible\n",ca);
		}
	}
	//system("pause");
	return 0;
}
