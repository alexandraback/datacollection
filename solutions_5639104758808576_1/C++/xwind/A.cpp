#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<list>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<map>
#include<string>
#define REP(it,end) for (int it = 1; it <= (end); it++)
#define FOR(it,begin,end) for (int it = (begin); it <= (end); it++)
#define ROF(it,begin,end) for (int it = (begin); it >= (end); it--)
using namespace std;
char s[1005];
int main()
{
	int T,n,con,ans,i;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++)
	{
		con=ans=0;
		scanf("%d",&n);
		scanf("%s",s);
		for(i=0;i<n+1;i++)
		{
			if(s[i]=='0')continue;
			else if(con>=i)con+=(s[i]-'0');
			else
			{
				//cout <<i<<" "<<con<<endl;
				ans+=(i-con);
				con=i;
				con+=(s[i]-'0');
			}
		}
		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}
