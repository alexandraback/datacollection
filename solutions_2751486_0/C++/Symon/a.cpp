#pragma warning(disable:4786)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<sstream>
#include<utility>
using namespace std;
typedef int LL;
//typedef __int64 LL;
//typedef unsigned __int64 LL;

LL MX(LL a,LL b){return (a>b)?a:b;}
LL MN(LL a,LL b){return (a<b)?a:b;}
//LL ABS(LL a){return (a<0)?-1*a:a;}
//LL S(LL a){return a*a;}
char str[103];
LL id[103];
int main()
{
	LL t,cas=0,n,i,j,ans,flag,cnt,L;
	freopen("aai.txt","r",stdin);
	freopen("aao.txt","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%d",str,&n);
		L=strlen(str);
		for(i=0;i<L;i++)
		{
			id[i]=0;
		}
		for(i=0;i<L;i++)
		{
			cnt=0;
			for(j=i;j<L;j++)
			{
				if(str[j]!='a'&&str[j]!='e'&&str[j]!='i'&&str[j]!='o'&&str[j]!='u')
				{
					cnt++;
					if(cnt==n){id[i]=1;break;}
				}
				else{break;}
			}
		}
		ans=0;
		for(i=0;i<L;i++)
		{
			flag=0;
			for(j=i;j<L;j++)
			{
				if(id[j]==1)
				{
					ans+=(L-1)-(j+n-1)+1;
					flag=1;
					break;
				}
			}
		}
		printf("Case #%d: %d\n",++cas,ans);
	}
	return 0;
}