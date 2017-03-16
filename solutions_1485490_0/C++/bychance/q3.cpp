
#include<iostream>
#include<algorithm>
#include<functional>
#include<sstream>
#include<set>
#include<map>
using namespace std;

#define MAXN 102

int T, N, M;
long long a[MAXN],b[MAXN];
int A[MAXN], B[MAXN];

long long ans;

void dfs(int i, int j, long long sum)
{
	if(i>=N||j>=M)
	{
		if(sum>ans)
		{
			ans = sum;
		}
		return;
	}

	if(A[i]==B[j])
	{
		if(a[i]>b[j])
		{
			a[i]-=b[j];
			dfs(i, j+1, sum+b[j]);
			a[i]+=b[j];
		}
		else// if(a[i]<b[j])
		{
			b[j]-=a[i];
			dfs(i+1, j, sum+a[i]);
			b[j]+=a[i];
		}
	}
	else
	{
		dfs(i, j+1, sum);
		dfs(i+1, j, sum);
	}
}

int main()
{
	freopen("C-small-attempt0 (2).in", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d\n", &T);
	for(int te=1;te<=T;++te)
	{
		cin>>N>>M;
		ans = 0;
		for(int i=0;i<N;++i)
		{
			cin>>a[i]>>A[i];
		}
		for(int i=0;i<M;++i)
		{
			cin>>b[i]>>B[i];
		}
		
		dfs(0,0,0);
		printf("Case #%d: %lld\n", te, ans);
	}
	return 0;
}

/*
#include<iostream>
#include<algorithm>
#include<functional>
#include<sstream>
#include<set>
#include<map>
using namespace std;

#define MAXN 102

int T, N, M;
long long a[MAXN],b[MAXN];
int A[MAXN], B[MAXN];
map<long long, map<long long, long long> > f[MAXN][MAXN];

long long ans;

void clearf()
{
	for(int i=0;i<MAXN;++i)
	{
		for(int j=0;j<MAXN;++j)
		{
			f[i][j].clear();
		}
	}
}

long long dp(int i, int j, long long ai, long long bj)
{
	if(f[i][j][ai].find(bj)!=f[i][j][ai].end())
	{
		return f[i][j][ai][bj];
	}

	f[i][j][ai][bj]=0;

	if(i>1)
	{
		if(A[i-1]==B[i])
		{

		}
	}

	if(j>1)
	{
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d\n", &T);
	for(int te=1;te<=T;++te)
	{
		cin>>N>>M;
		ans = 0;
		for(int i=0;i<N;++i)
		{
			cin>>a[i]>>A[i];
		}
		for(int i=0;i<M;++i)
		{
			cin>>b[i]>>B[i];
		}
		
		clearf();

		for(int i=1;i<=N;++i)
		{
			for(int j=1;j<=M;++j)
			{
				if(A[i]==B[j]
			}
		}
		printf("Case #%d: %ll\n", te, ans);
	}
	return 0;
}
*/