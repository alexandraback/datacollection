
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
using namespace std;


int n1;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&n1);
		char s1[n1][21];
		char s2[n1][21];
		for(int u=0;u<n1;u++)
		{
			scanf("%s %s",s1[u],s2[u]);
		}
		int list[n1];
		int max1 =0;
		for(int u=0;u< 2<<(n1) -1 ; u++)
		{
			int temp=u;
			memset(list,0,n1*sizeof(int));
			int j=0;
			int t2=0;
			while(temp)
			{
				list[j]=temp%2;
				temp/=2;
				if(list[j])
					t2++;
				j++;
			}
			if(t2<=max1)
				continue;
			for(int t=0;t<n1;t++)
			{
				if(list[t])
				{
					bool found=false;
					for(int t3=0;t3<n1;t3++)
					{
						if(list[t3]==0)
						{
							if(strcmp(s1[t],s1[t3])==0)
							{
								found =true;
								break;
							}
								
						}
					}
					if(!found)
						goto a;

					found=false;
					for(int t3=0;t3<n1;t3++)
					{
						if(list[t3]==0)
						{
							if(strcmp(s2[t],s2[t3])==0)
							{
								found =true;
								break;
							}
						}
					}
					if(!found)
						goto a;
				}
			}
			max1=t2;
a:
			continue;
			
		}

		printf("Case #%d: %d\n",i,max1);
	}
}
