#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#include<vector>
using namespace std;
#define LL long long
int r,n,m,k;
vector<int>v[650];
vector<int>::iterator it;
int flag[1000];
bool check(int a,int b,int c,int p)
{
	if(a==p||b==p||c==p) return 1;
	if(a*a==p||a*b==p||a*c==p||b*b==p||b*c==p||c*c==p) return 1;
	if(a*b*c==p)	return 1;
	return 0;
}
int main()
{
	freopen("C-small-1-attempt0.in","r",stdin);
	freopen("C.txt","w",stdout);
	int i,j;
	int cas=0,T;
	cin>>T;

	while(T--)
	{
		int ans=0;
		cas++;
		
		int p;
		scanf("%d%d%d%d",&r,&n,&m,&k);
		printf("Case #%d:\n",cas);
		int a,b,c;
		for(i=0;i<r;i++)
		{
			memset(flag,0,sizeof(flag));
			for(j=0;j<k;j++)
			{
				scanf("%d",&p);
				if(p==1)continue;
				for(a=2;a<=5;a++)
					for(b=a;b<=5;b++)
						for(c=b;c<=5;c++)
						{
							if(check(a,b,c,p))
							{
								int tmp=a*100+b*10+c;
								flag[tmp]++;
							}
						}
			}
			int res=0,ans=222;
			for(j=0;j<1000;j++)
			{
				if(flag[j]>res)
				{
					res=flag[j];
					ans=j;
				}
			}
			printf("%d\n",ans);

		}
		
	}
	return 0;	
}
