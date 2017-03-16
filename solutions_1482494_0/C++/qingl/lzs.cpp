#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
#define mp(x,y) make_pair(x,y)
typedef pair<int,int> per;
const int N = 100005;
per a[N],b[N];
bool u[N],v[N];
int v1[N],v2[N];
int main()
{
	//freopen("B-small-attempt1.in","r",stdin);
	freopen("out.out","w",stdout);
	int T,ca=1,n,i,x,y;
	scanf("%d",&T);
	while(T--)
	{
		memset(u,false,sizeof(u));
		memset(v,false,sizeof(v));
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			v1[i]=x;v2[i]=y;
			a[i]=mp(x,i);
			b[i]=mp(y,i);
		}
		sort(b,b+n);
		int j,now=0,r=0,flag=0,p;
		for(i=0;i<n;i++)
		{
			while(now<b[i].first)
			{
				p=-1;
				for(j=0;j<n;j++)
				{
					if(!u[a[j].second]&&now>=a[j].first&&(p==-1||v2[j]>v2[p]))p=j;
				}
				if(p==-1){flag=1;break;}
				now++;
				u[p]=true;
				r++;
			}
			//printf("now:%d i:%d j:%d r:%d \n",now,i,j,r);
			if(now<b[i].first){flag=1;break;}
			if(!u[b[i].second])now+=2;
			else now++;
			r++;
			u[b[i].second]=true;
		}
		printf("Case #%d: ",ca++);
		if(flag)puts("Too Bad");
		else printf("%d\n",r);
	}
	return 0;
}