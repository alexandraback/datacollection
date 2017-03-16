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
LL a[14][1<<19],b[14][1<<19],dp[14][1<<19];
char s1[20],s2[20];
int n;
struct ANS
{
	LL a,b,res;
	bool operator < (const ANS &x) const
	{
		if(res==x.res)
		{
			if(a==x.a)return b<x.b;
			return a<x.a;
		}
		return res<x.res;
	}
}ans;

void dfs(int pos,ANS tmp)
{
	if(pos==n)
	{
		if(tmp<ans)ans=tmp;
		return;
	}
	if(s1[pos]==s2[pos])
	{
		if(s1[pos]=='?')
		{
			if(tmp.res==0)
			{
				ANS tt=tmp;
				tt.a=tt.a*10;
				tt.b=tt.b*10;
				dfs(pos+1,tt);
				tt.b++;
				tt.res=1;
				dfs(pos+1,tt);
				tt.a++;tt.b--;
				dfs(pos+1,tt);
				return;
			}
			else if(tmp.a>tmp.b)
			{
				tmp.a=tmp.a*10;
				tmp.b=tmp.b*10+9;
				tmp.res=abs(tmp.a-tmp.b);
			}
			else
			{
				tmp.a=tmp.a*10+9;
				tmp.b=tmp.b*10;
				tmp.res=abs(tmp.a-tmp.b);
			}
		}
		else
		{
			int k1=s1[pos]-'0',k2=s2[pos]-'0';
			tmp.a=tmp.a*10+k1;
			tmp.b=tmp.b*10+k2;
			tmp.res=abs(tmp.a-tmp.b);
		}
	}
	else
	{
		if(s1[pos]!='?' &&s2[pos]!='?')
		{
			int k1=s1[pos]-'0',k2=s2[pos]-'0';
			tmp.a=tmp.a*10+k1;
			tmp.b=tmp.b*10+k2;
			tmp.res=abs(tmp.a-tmp.b);
		}
		else
		{
			if(s1[pos]=='?')
			{
				int k2=s2[pos]-'0';
				// cout<<k2<<endl;
				if(tmp.res==0)
				{
					ANS tt=tmp;
					tt.a=tmp.a*10+k2;
					tt.b=tmp.b*10+k2;
					tt.res=abs(tt.a-tt.b);
					tmp=tt;
					dfs(pos+1,tt);
					if(k2>0)
					{
						tt.a=tmp.a-1;
						tt.res=abs(tt.a-tt.b);
						dfs(pos+1,tt);
					}
					if(k2<9)
					{
						tt.a=tmp.a+1;
						tt.res=abs(tt.a-tt.b);
						dfs(pos+1,tt);
					}
					return;
				}
				else if(tmp.a>tmp.b)
				{
					tmp.a=tmp.a*10;
					tmp.b=tmp.b*10+k2;
					tmp.res=abs(tmp.a-tmp.b);
				}
				else
				{
					tmp.a=tmp.a*10+9;
					tmp.b=tmp.b*10+k2;
					tmp.res=abs(tmp.a-tmp.b);
				}
			}
			else
			{
				int k1=s1[pos]-'0';
				// cout<<k1<<endl;
				if(tmp.res==0)
				{
					ANS tt=tmp;
					tt.a=tmp.a*10+k1;
					tt.b=tmp.b*10+k1;
					tt.res=abs(tt.a-tt.b);
					tmp=tt;
					dfs(pos+1,tt);
					if(k1>0)
					{
						tt.b=tmp.b-1;
						tt.res=abs(tt.a-tt.b);
						dfs(pos+1,tt);
					}
					if(k1<9)
					{
						tt.b=tmp.b+1;
						tt.res=abs(tt.a-tt.b);
						dfs(pos+1,tt);
					}
					return;
				}
				else if(tmp.a>tmp.b)
				{
					tmp.a=tmp.a*10+k1;
					tmp.b=tmp.b*10+9;
					tmp.res=abs(tmp.a-tmp.b);
				}
				else
				{
					tmp.a=tmp.a*10+k1;
					tmp.b=tmp.b*10;
					tmp.res=abs(tmp.a-tmp.b);
				}
			}
		}
	}
	// cout<<tmp.a<<' '<<tmp.b<<endl;
	dfs(pos+1,tmp);
}

int main()
{
	int T,cas=0;
	scanf("%d",&T);
	while(T--)
	{
		printf("Case #%d: ",++cas);
		scanf("%s%s",s1,s2);
		n=strlen(s1);
		ans.res=0x3f3f3f3f3f3f3f3f;
		ANS tt;tt.a=tt.b=tt.res=0;
		dfs(0,tt);
		for(int i=n-1;i>=0;i--)
		{
			if(s1[i]=='?')s1[i]=ans.a%10+'0';
			if(s2[i]=='?')s2[i]=ans.b%10+'0';
			ans.a/=10;
			ans.b/=10;
		}
		printf("%s %s\n",s1,s2);
	}
	
	return 0;
}
