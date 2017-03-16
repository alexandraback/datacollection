#include<iostream>
#include<cstdio>
#include<algorithm>
#include<time.h>
#include<cmath>
#include<set>
#include<stack>
#include<vector>
#include<cstring>
#include<string>
#define bug puts("here!")
#define maxn 40
using namespace std;
#define ll long long
#define inf 1e17
int mod;
#define vec vector<int>
#define mat vector<vec>
int b[maxn],k[maxn],T;
string a[maxn];
bool to[maxn][maxn];
int n,m,u,v;
string work()
{
	string res="";
	for(int i=0;i<n;++i)
		res+=a[b[i]];
	return res;
}
bool ok()
{
	stack<int> sta;
	sta.push(b[0]);
	for(int i=1;i<n;++i)
	{
		int t=sta.top();
		while(!to[t][b[i]])
		{
			sta.pop();
			if(sta.empty())
				return 0;
			else
				t=sta.top();
		}
		sta.push(b[i]);
	}
	return 1;
}
int main()
{
	freopen("C:\\Users\\Administrator\\Desktop\\C-small-attempt0.in","r",stdin);
	freopen("C:\\Users\\Administrator\\Desktop\\D.txt","w",stdout);
	scanf("%d",&T);
	int kase=1;
	while(T--)
	{
		scanf("%d%d",&n,&m);
		memset(to,0,sizeof(to));
		for(int i=1;i<=n;++i)
			cin>>a[i];
		for(int i=0;i<m;++i)
			scanf("%d%d",&u,&v),to[u][v]=1,to[v][u]=1;
		for(int i=0;i<n;++i)
			b[i]=i+1;
		string ans="";
		for(int i=0;i<n;++i)
			ans+="99999";
		if(ok())
			ans=min(ans,work());
		while(next_permutation(b,b+n))
		{
			if(ok())
			ans=min(ans,work());
		}
		printf("Case #%d: ",kase++);
		cout<<ans<<endl;
	}
}