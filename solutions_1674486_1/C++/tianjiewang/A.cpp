#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<iomanip>
using namespace std;
#define maxn 1001000
struct Graph
{
	int e,first[maxn],next[maxn],v[maxn],w[maxn];
	void init(){fill(first,first+maxn,-1);e=0;}
	void input(int a,int b)
	{
		v[e]=b;next[e]=first[a];first[a]=e++;
	}
}T;
int fa[maxn];
int dfs(int x)
{
	fa[x]=true;
	for(int i=T.first[x];i!=-1;i=T.next[i])
		if(fa[T.v[i]]==0)
		{
			if(dfs(T.v[i])) return 1;
		}
		else return 1;
	return 0;
}
int main()
{
	ifstream cin("A-large.in");
	ofstream cout("A-large.out");
	int N;
	cin>>N;
	for(int k=1;k<=N;k++)
	{
		T.init();
		int n,m,tmp,i;
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>m;
			for(int j=0;j<m;j++)
			{
				cin>>tmp;
				T.input(i,tmp);
			}
		}
		for(i=1;i<=n;i++)
		{
			memset(fa,0,sizeof(fa));
			if(dfs(i)) break;
		}
		if(i<=n) cout<<"Case #"<<k<<": Yes"<<endl;
		else cout<<"Case #"<<k<<": No"<<endl;
	}
	return 0;
}