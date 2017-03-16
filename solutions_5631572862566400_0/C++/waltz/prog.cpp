#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define x first
#define y second

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

int a[1010],head[1010],next[1010],d[1010];
bool v[1010];

template <class T>
void read(T &x)
{
	char ch;
	for (ch=getchar();(ch<'0'||ch>'9')&&ch!='-';) ch=getchar();
	x=0;int t=1;if (ch=='-') {ch=getchar();t=-1;}
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	x*=t;
}

void dfs(int k)
{
	int p=head[k];d[k]=0;
	while (p)
	{
		dfs(p);d[k]=max(d[k],d[p]);p=next[p];
	}
	d[k]++;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int test;read(test);
	for (int T=1;T<=test;T++)
	{
		int n;read(n);
		for (int i=1;i<=n;i++) read(a[i]);
		int ans=0;
		for (int i=1;i<=n;i++)
		{
			memset(v+1,0,n*sizeof(bool));
			int k=i,s=0;
			while (!v[k])
			{
				v[k]=1;k=a[k];s++;
			}
			if (k==i) ans=max(ans,s);
		}
		memset(head+1,0,n*sizeof(int));
		for (int i=1;i<=n;i++)
			if (a[a[i]]!=i)
			{
				next[i]=head[a[i]];head[a[i]]=i;
			}
		for (int i=1;i<=n;i++) if (a[a[i]]==i) dfs(i);
		int s=0;for (int i=1;i<=n;i++) if (a[a[i]]==i&&i<a[i]) s=s+d[i]+d[a[i]];
		ans=max(ans,s);
		printf("Case #%d: %d\n",T,ans);
	}
	return 0;
}

