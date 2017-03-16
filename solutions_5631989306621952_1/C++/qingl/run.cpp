#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
const int N = 1005;
char str[N],ret[N];
bool u[N];
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T,ca=1;
	scanf("%d",&T);
	while(T--)
	{
		printf("Case #%d: ",ca++);
		memset(u,0,sizeof(u));
		scanf("%s",str);
		int n=strlen(str),k=0;
		for(int i=n-1;i>=0;)
		{
			int p;
			char mx=0;
			for(int j=i;j>=0;j--)
			{
				if(mx<str[j])mx=str[j];
			}
			//printf("mx:%c i:%d\n",mx,i);
			for(int j=i;j>=0;j--)
			{
				if(str[j]==mx)
				{
					p=j;
					ret[k++]=str[j];
					u[j]=true;
					break;
				}
			}
			i=p-1;
		}
		//printf("k:%d \n",k);
		for(int i=0;i<n;i++)
		{
			if(!u[i])
			{
				ret[k++]=str[i];
			}
		}
		ret[k]=0;
		puts(ret);
	}
	return 0;
}

