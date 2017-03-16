#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
using namespace std;
const int INF=1<<30;
const int maxn=100005;
int n,m,a[maxn];
struct node
{
	int sum,sta;
}nd[1<<20];
bool cmp(node a,node b)
{
	if(a.sum==b.sum)
		return a.sta<b.sta;
	return a.sum<b.sum;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("ans.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=0;i<(1<<n);i++)
		{
			nd[i].sta=i;nd[i].sum=0;
			int tem=i,cnt=0;
			while(tem)
			{
				if(tem&1)
					nd[i].sum+=a[cnt];
				tem>>=1;cnt++;
			}
		}
		sort(nd,nd+(1<<n),cmp);
		printf("Case #%d:\n",t);
		for(int i=2;i<(1<<n);i++)
		{
			if(nd[i].sum==nd[i-1].sum)
			{
				//puts("*******");
				int tem=nd[i-1].sta,flag=0,cnt=0;
				while(tem)
				{
					if(tem&1)
					{
						if(flag!=0)
							printf(" ");
						else flag=1;
						printf("%d",a[cnt]);
					}
					tem>>=1;cnt++;
				}
				puts("");
				tem=nd[i].sta,flag=0,cnt=0;
				while(tem)
				{
					if(tem&1)
					{
						if(flag!=0)
							printf(" ");
						else flag=1;
						printf("%d",a[cnt]);
					}
					tem>>=1;cnt++;
				}
				puts("");
				break;
			}
		}
	}
	return 0;
}