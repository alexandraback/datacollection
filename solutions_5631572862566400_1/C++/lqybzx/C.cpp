#include<queue>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct line
{
	int s,t;
	int next;
}a[20001];
int head[10001];
int edge;
inline void add(int s,int t)
{
	a[edge].next=head[s];
	head[s]=edge;
	a[edge].s=s;
	a[edge].t=t;
}
queue<int> Q;
int next[20001];
int indeg[20001];
int dep[20001];
bool v[20001];
int max1,max2;
inline void dfs1(int d) //最大环
{
	v[d]=true;
	int t=next[d];
	if(!v[t])
	{
		dep[t]=dep[d]+1;
		dfs1(t);
	}
	else
		max1=max(dep[d]-dep[t]+1,max1);
}
inline void dfs2(int d) //二元环 
{
	max2=max(dep[d],max2);
	v[d]=true;
	int i;
	for(i=head[d];i!=0;i=a[i].next)
	{
		int t=a[i].t;
		if(!v[t])
		{
			dep[t]=dep[d]+1;
			dfs2(t); 
		}
	}
}
int main()
{
//	freopen("C-small-attempt1.in","r",stdin);
//	freopen("C-small-attempt1.out","w",stdout);
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	int T;
	int k=0;
	scanf("%d",&T);
	while(T>0)
	{
		T--;
		k++;
		int n;
		scanf("%d",&n);
		int i,x;
		memset(a,0,sizeof(a));
		memset(head,0,sizeof(head));
		edge=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			next[i]=x;
			edge++;
			add(x,i);
		}
		while(!Q.empty())
			Q.pop();
		bool flag=false;
		for(i=1;i<=n;i++)
		{
			if(indeg[i]==0)
			{
				flag=true;
				Q.push(i);
			}
		}
		printf("Case #%d: ",k);
		if(!flag)
			printf("%d\n",n);
		max1=0;
		while(!Q.empty())
		{
			int d=Q.front();
			Q.pop();
			memset(v,false,sizeof(v));
			memset(dep,0,sizeof(dep));
			dfs1(d);
		}
		for(i=1;i<=n;i++)
			if(i==next[next[i]])
				Q.push(i);
		int s=0;
		memset(dep,0,sizeof(dep));
		memset(v,false,sizeof(v));
		while(!Q.empty())
		{
			int d=Q.front();
			Q.pop();
			if(!v[d])
			{
				v[d]=true;
				v[next[d]]=true;
				max2=0;
				dfs2(d);
				s+=max2;
				max2=0;
				dfs2(next[d]);
				s+=max2;
				s+=2;
			}
		}
		printf("%d\n",max(s,max1));
	}
	return 0;
}
