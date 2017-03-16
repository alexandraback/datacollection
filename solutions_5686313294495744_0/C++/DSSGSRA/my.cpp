#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<queue>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#define rep(i,k,n) for(int i=(k);i<=(n);i++)
#define rep0(i,n) for(int i=0;i<(n);i++)
#define red(i,k,n) for(int i=(k);i>=(n);i--)
#define sqr(x) ((x)*(x))
#define clr(x,y) memset((x),(y),sizeof(x))
#define pb push_back
#define mod 1000000007
const int maxn=1010;
char s[maxn][2][30];
map<string,int>mp[2];
map<string,bool>mm[2];
bool flag[maxn];
int main()
{
	int T,cas=0;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		printf("Case #%d: ",++cas);
		scanf("%d",&n);
		mp[0].clear();
		mp[1].clear();
		mm[0].clear();mm[1].clear();
		rep(i,1,n)
		{
			scanf("%s%s",s[i][0],s[i][1]);
			mp[0][s[i][0]]++;
			mp[1][s[i][1]]++;
		}
		clr(flag,0);
		rep(i,1,n)
		{
			rep(j,0,1)if(mp[j][s[i][j]]==1)flag[i]=1;
			if(flag[i])
			{
				rep(j,0,1)mm[j][s[i][j]]=true;
			}
		}
		rep(i,1,n)if(!flag[i])
		{
			if(!mm[0][s[i][0]] || !mm[1][s[i][1]])
			{
				flag[i]=1;
				mm[0][s[i][0]]=true;
				mm[1][s[i][1]]=true;
			}
		}
		int ans=0;
		rep(i,1,n)if(!flag[i])ans++;
		printf("%d\n",ans);
	}
	
	return 0;
}
