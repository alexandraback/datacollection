#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;
int rec[105];
int main()
{
	int T;
	freopen("B-large.in","r",stdin);
	freopen("out.out","w",stdout);
	scanf("%d",&T);
	int n,s,p;
	for(int icas=1;icas<=T;icas++)
	{
		int base = 0;
		int sup = 0;
		scanf("%d%d%d",&n,&s,&p);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&rec[i]);
			if(rec[i]>=3*p-2)
			{
				base++;
			}
			else if(rec[i]<3*p-4);
			else  if(rec[i]>=2)
			{
				sup++;
			}
		}
		printf("Case #%d: %d\n",icas,base+min(sup,s));
	}
	
}
