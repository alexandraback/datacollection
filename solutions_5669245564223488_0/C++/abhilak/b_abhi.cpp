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
#include<cassert>


bool check(string& str){
	int l = str.length();
	int temporary[26];
	memset(temporary,false,sizeof(temporary));
	temporary[str[0]-'a'] = true;
	for(int i=1;i<l;++i)
	{
		if(str[i] == str[i-1]) continue;
		if(temporary[str[i]-'a']) return false;
		temporary[str[i]-'a'] = true;
	}
	return true;
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
	int t;
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}