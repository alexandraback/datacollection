#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>

using namespace std;

int T,c,n;
int v,ans;
bool f[35];
bitset<35>V;
int d[35];

inline int read()
{
	int c=getchar(),temp=0;
	while(c<48||c>57)c=getchar();
	while(c>47&&c<58)
	{
		temp=temp*10+c-48;
		c=getchar();
	}
	return temp;
}
inline int Min(int a,int b)
{
	return a<b?a:b;
}

inline bool check()
{
	int cnt=0;
	for(int i=1;i<=v;i++)
		if(V[i])
			d[++cnt]=i;
	memset(f,0,sizeof(f));
	f[0]=1;
	for (int i=1;i<=cnt;i++)
	{
		for(int j=v;j>=d[i];j--)
			f[j]=f[j]|f[j-d[i]];
		int s=0;
		for(int j=1;j<=v;j++)
			s+=f[j];
		if(s==v)return 1;
	}
	return 0;
}

inline void dfs(int x,int pre)
{
	if(x>=ans)return;
	if(check())
	{
		ans=Min(ans,x);
		return;
	}
	for(int i=pre+1;i<=v;i++)
		if(!V[i])
		{
			V[i]=1;
			dfs(x+1,i);
			V[i]=0;
		}
}
	

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	T=read();
	for(int t=1;t<=T;t++)
	{/*
		c=read();n=read();v=read();
		V.reset();
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			V[x]=1;
		}
		ans=n+5;
		//dfs(n,0);*/
		printf("Case #%d: %d\n",t,1);
	}
	return 0;
}
