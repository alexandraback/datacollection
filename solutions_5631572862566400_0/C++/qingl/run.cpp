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
int nxt[N],d[N],q[N],len[N],bg[N],mxlen[N],sd[N];
bool u[N],two[N];
int main()
{
	freopen("C-small-attempt1.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T,ca=1;
	scanf("%d",&T);
	while(T--)
	{
		printf("Case #%d: ",ca++);
		int n,k=0;
		scanf("%d",&n);
		memset(d,0,sizeof(d));
		memset(u,0,sizeof(u));
		memset(two,0,sizeof(two));
		memset(mxlen,0,sizeof(mxlen));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&nxt[i]);
			d[nxt[i]]++;
		}
		int t=0,w=0;
		for(int i=1;i<=n;i++)
		{
			sd[i]=d[i];
			if(!d[i])
			{
				q[w++]=i;
			}
		}
		while(t<w)
		{
			int x=q[t++];
			u[x]=true;
			d[nxt[x]]--;
			if(!d[nxt[x]])q[w++]=nxt[x];
		}
		memset(bg,-1,sizeof(bg));
		int mx=0;
		for(int i=1;i<=n;i++)
		{
			if(!u[i])
			{
				int cnt=1,j=nxt[i];
				while(j!=i)
				{
					cnt++;
					j=nxt[j];
				}
				if(cnt==2)
				{
					two[i]=true;
					/*for(j=nxt[i];;j=nxt[j])
					{
						bg[j]=k;
						if(j==i)break;
					}*/
					k++;
				}
				if(mx<cnt)mx=cnt;
			}
		}
		//puts("what");
		for(int i=1;i<=n;i++)if(!sd[i])
		{
			int j=i;
			len[i]=1;
		//	printf("i:%d \n",i);
			for(j=nxt[i];;j=nxt[j])
			{
				//printf("j:%d \n",j);
				if(!u[j])
				{
					if(two[j]&&mxlen[j]<len[i])mxlen[j]=len[i];
					break;
				}
				len[i]++;
			}
		}
		//puts("here");
		int totlen=0;
		for(int i=1;i<=n;i++)if(two[i])totlen+=mxlen[i]+1;
		int ret=mx;
		if(ret<totlen)ret=totlen;
		printf("%d\n",ret);
	}
	return 0;
}

