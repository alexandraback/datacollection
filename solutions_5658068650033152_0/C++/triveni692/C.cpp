/*
user  : triveni
date  : 11/05/2014
time  : 14:32:57
*/
#include <bits/stdc++.h>

using namespace std;

#define      pii               std::pair<int,int>
#define      mp(a,b)           std::make_pair(a,b)
#define      X                 first
#define      Y                 second

typedef long long ll;

bool A[100][100];
bool vis[100][100];
int Ans[22][22][22];
int N,M;

bool is_val(int x, int y)
{
	if(!(0<=x && x<N && 0<=y && y<M)) return false;
	if(vis[x][y] == 0 && A[x][y] == 0) return true;
	return false;
}
void dfs(int i, int j)
{
	vis[i][j] = true;
	int x, y;
	x = i+1,y = j;
	if(is_val(x,y)) dfs(x,y);
	x = i-1,y=j;
	if(is_val(x,y)) dfs(x,y);
	x = i,y=j-1;
	if(is_val(x,y)) dfs(x,y);
	x = i,y=j+1;
	if(is_val(x,y)) dfs(x,y);
}

bool solve1(int K)
{
	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
			vis[i][j] = 0;

	for(int i=0;i<N;++i)
	{
		if(vis[i][0]==0 && A[i][0]==0) dfs(i,0);
	}
	for(int i=0;i<N;++i)
	{
		if(vis[i][M-1]==0 && A[i][M-1]==0) dfs(i,M-1);
	}
	for(int i=0;i<M;++i)
	{
		if(vis[0][i]==0 && A[0][i]==0) dfs(0,i);
	}
	for(int i=0;i<M;++i)
	{
		if(vis[N-1][i]==0 && A[N-1][i]==0) dfs(N-1,i);
	}
	int ct = 0;
	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
		{
			if(A[i][j] || (vis[i][j] == 0 && A[i][j] ==0) ) ct++;
		}
	if(ct>=K) return true;
	return false;
}
int bit_ct(int x)
{
	return __builtin_popcount(x);
	int ct = 0;
	while(x)
	{
		if(x&1) ct++;
		x>>=1;
	}
	return ct;
}
void solve()
{
	int K;
	cin>>N>>M>>K;
	// N = a, M = b, K = c;
	memset(A,false,sizeof A);
	int x = 1<<(N*M), ans = 1000;
	for(int i=0;i<x;++i)
	{
		int n = i;
		int j=0;
		while(n)
		{
			if(n&1) A[j/M][j%M] = true;
			++j;
			n>>=1;
		}
		if(solve1(K))
		{
			ans = min(bit_ct(i),ans); 
		}
		for(int j=0;j<N;++j)
			for(int k=0;k<M;++k)
				A[j][k] = 0;
	}
	assert(ans != 1000);
	cout << ans << endl;
	// return ans;
}

int main()
{
	// for(int i=1;i<=20;++i)
	// 	for(int j=1;j*i<=20;++j)
	// 		for(int k=1;k<=i*j;k++)
	// 		{
	// 			Ans[i][j][k] = solve(i,j,k);
	// 			cout << Ans[i][j][k] << "\n";
	// 		}
	int T;
	cin>>T;
	for(int i=1;i<=T;++i)
	{
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}