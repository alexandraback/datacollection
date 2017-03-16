#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<memory.h>
using namespace std;
int rec[105];
int snum[10];
int n;
map<string,bool>mymap;
void getn(int s)
{
	n = 0;
	int num[10];
	num[n++] = s%10;
	while(s/=10)
	{
		num[n++] = s%10;
	}
	for(int i=0;i<n;i++)
		snum[i] = num[n-i-1];
}

int main()
{
	int T;
	freopen("C-small-attempt1.in","r",stdin);
	freopen("out.out","w",stdout);
	scanf("%d",&T);
	int a,b,ans,sum;
	int tp[10];
	for(int icas=1;icas<=T;icas++)
	{
		scanf("%d%d",&a,&b);
		ans = 0;
		mymap.clear();
		for(int i=a;i<=b;i++)
		{
			if(i<10)continue;
			getn(i);
			
			for(int j=1;j<n;j++)
			{
				for(int k=0;k<n;k++)
				{
					tp[k] = snum[(k+j)%n];
				}
				sum = 0;
				for(int k=0;k<n;k++)
				{
					sum = sum*10+tp[k];
				}
				if(sum>i&&sum<=b)
				{
				
					char ss[20];
					sprintf(ss,"{%d,%d}",i,sum);
					string str = ss;
					if(!mymap[str])
					{
						ans++;
						mymap[str] = 1;
					}
				//	else cout<<str<<endl;
				}
			}			
		}
		printf("Case #%d: %d\n",icas,ans);
	}
	
}
