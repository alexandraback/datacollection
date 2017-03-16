#include <set>
#include <cmath>
#include <stack>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <vector>
#include <ctime>
#include <queue>
#include <list>
#include <map>
#define pi acos(-1.0)
#define INF 0x3f3f3f3f
#define clr(x)  memset(x,0,sizeof(x));
#define clrto(x,siz,y)  for(int xx=0;xx<=siz;xx++)  x[xx]=y;
#define clrset(x,siz)  for(int xx=0;xx<=siz;xx++)  x[xx]=xx;
#define clr_1(x) memset(x,-1,sizeof(x));
#define clrmax(x) memset(x,0x3f,sizeof(x));
#define clrvec(x,siz) for(int xx=0;xx<=siz;xx++)  x[xx].clear();
#define fop2   freopen(".in","r",stdin); //freopen(".out","w",stdout);
#define fop   freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
#define myprogram By_135678942570
#define clrcpy(x,siz,y)  for(int xx=0;xx<siz;xx++)  x[xx]=y[xx];
#define pb push_back
using namespace std;
string s[105];
long long MOD=1000000007;
long long dp[11][11][1<<11];
map<char,int>mp;
long long sum=0;
int use[55]={0};
int N;
int rr[55]={0};
int allsame[55]={0};
stack<int>st;
void dfs(int dep,int last)
{
	if(dep==N)
	{
		// for(int i=0;i<dep;i++)
		// 	printf("%d ",rr[i]);
		// puts("");
		sum++;
		return;
	}
	long long ss=0;
	for(int i=0;i<N;i++)
		if(use[i]==0)
		{
			// printf("%d %d %d\n",dep,last,i);
			if(s[i][0]!=s[last][s[last].size()-1]&&mp[s[i][0]])
				continue;
			if(s[i][0]!=s[i][s[i].size()-1]&&mp[s[i][s[i].size()-1]])
				continue;
			if(s[i][0]!=s[last][s[last].size()-1])
				mp[s[i][0]]=1;
			if(s[i][0]!=s[i][s[i].size()-1])
				mp[s[i][s[i].size()-1]]=1;
			// printf("%d %d %d\n",dep,last,i);
			use[i]=1;
			rr[dep]=i;
			dfs(dep+1,i);
			use[i]=0;
			if(s[i][0]!=s[last][s[last].size()-1])
				mp[s[i][0]]=0;
			if(s[i][0]!=s[i][s[i].size()-1])
				mp[s[i][s[i].size()-1]]=0;
		}
}
int main()
{
	fop;
	int T,cas=0;
	scanf("%d",&T);
	while(T--)
	{
		printf("Case #%d: ",++cas);
		sum=0;
		clr(allsame);
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			cin>>s[i];
			for(int j=0;j<s[i].size();j++)
				if(s[i][j]!=s[i][0])
				{
					allsame[i]=1;
					break;
				}
		}
		int flag=0;
		for(int i=0;i<N;i++)
		{
			int len=s[i].size();
			mp.clear();
			for(int j=0;j<len;j++)
			{
				int now=mp[s[i][j]];
				if(now!=0&&j>now)
				{
					i=N;
					flag=1;
					break;
				}
				mp[s[i][j]]=j+1;
			}
		}
		// printf("%d\n",flag);
		for(int i=0;i<N;i++)
		{
			int l=0,r=s[i].size()-1;
			int len=s[i].size();
			// for(int j=0;j<len;j++)
			// 	if(s[i][j]==s[i][0])
			// 		l=j;
			// 	else break;
			// for(int j=len-1;j>=0;j--)
			// 	if(s[i][j]==s[i][len-1])
			// 		r=j;
			// 	else break;
			for(int j=l;j<=r;j++)
				for(int k=0;k<N;k++)
					if(k!=i)
					{
						int l2,r2;
						int len2=s[k].size();
						for(int ll=0;ll<len2;ll++)
							if(s[k][ll]==s[k][0])
								l2=ll;
							else break;
						for(int ll=len2-1;ll>=0;ll--)
							if(s[k][ll]==s[k][len2-1])
								r2=ll;
							else break;
						for(int ll=l2+1;ll<r2;ll++)
							if(s[i][j]==s[k][ll])
							{
								// printf("%d %d %d %d\n",i,j,k,ll);
								// printf("%d %d\n",l2,r2);
								flag=1;
								goto loop;
							}
					}
		}
		loop:;
		// printf("%d\n",flag);
		if(flag)
		{
			printf("0\n");
			continue;
		}
		clr(dp);
		clr(use);
		mp.clear();
		for(int i=0;i<N;i++)
		{
			mp[s[i][0]]=1;
			mp[s[i][s[i].size()-1]]=1;
			use[i]=1;
			rr[0]=i;
			dfs(1,i);
			use[i]=0;
			mp[s[i][0]]=0;
			mp[s[i][s[i].size()-1]]=0;
		}
		printf("%lld\n",sum%MOD);
	}
}