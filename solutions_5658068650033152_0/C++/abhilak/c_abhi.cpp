#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<stack>
#include<string>
#include<cctype>
#include<list>
#include<set>
#include<deque>
#include<queue>
#include<bitset>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iomanip>
#include<ctime>

#define      pii               std::pair<int,int>
#define      mp(a,b)           std::make_pair(a,b)
#define      X                 first
#define      Y                 second
#define 	pb(x)       	   push_back(x)
typedef long long ll;

ll MOD = 1000000007;
 
using namespace std;
int A[30][30],vis[30][30],n , m ; 
int dfs(int i , int j ,int* p)
{
	if(vis[i][j]||A[i][j])return *p;
	vis[i][j]=1;
	*p+=1;
	if((i<n-1)&&(!vis[i+1][j])&&(!A[i+1][j]))dfs(i+1,j,p);
	if((j<m-1)&&(!vis[i][j+1])&&(!A[i][j+1]))dfs(i,j+1,p);
	if((i>0)&&(!vis[i-1][j])&&(!A[i-1][j]))dfs(i-1,j,p);
	if((j>0)&&(!vis[i][j-1])&&(!A[i][j-1]))dfs(i,j-1,p);
	return *p;
}
void solve()
{
	int k ;
	scanf("%d%d%d",&n,&m,&k);
	int t = 1<<(m*n);
	int ans = m*n;
	for(int i=0;i<t;i++)
	{
		int curr = i ;
		memset(A,false,sizeof A);
		for(int j =0 ; j < m*n ;j++)
		{
			A[j/m][j-(j/m)*m]=curr%2;
			curr/=2;
		}
		curr=0;
		//printf("HI\n");
		memset(vis,false,sizeof vis);
		for(int j = 0 ;j<m;j++)
		{
			int p;
			p=0;
			curr+=dfs(0,j,&p);
			p=0;
			curr+=dfs(n-1,j,&p);
		}
		for(int j = 0 ;j<n;j++)
		{
			int p;
			p=0;
			curr+=dfs(j,0,&p);
			p=0;
			curr+=dfs(j,m-1,&p);
		}
		if(m*n-curr>=k)ans=min(ans,__builtin_popcount(t));
	}
	printf("%d\n",ans );
	return;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;++i)
	{
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}