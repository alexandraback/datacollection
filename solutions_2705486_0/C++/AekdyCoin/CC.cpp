#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int dp[66][66];
const int state=1234567;
const int child=26;
int ac[state][child];
int fail[state],flag[state],top;
int w[128];
void init()
{
	memset(fail,0,sizeof(fail));
	memset(flag,0,sizeof(flag));
	memset(ac,0,sizeof(ac));
	top=1;
	for (int i=0;i<26;i++)w[i+'a']=i;
}
void ins(char *s)
{
	int p=0,i=0,t;
	while (s[i])
	{
		t=w[s[i]];
		if (!ac[p][t])
		{
			flag[top]=0;
			ac[p][t]=top++;
		}
		p=ac[p][t];
		i++;
	}
	flag[p]=1;
}
bool find(string s)
{
	//if (s.length()==7)cout<<s<<endl;
	int p=0,i=0,t;
	for (i=0;i<s.length();i++)
	{
		t=w[s[i]];
		if (!ac[p][t])return 0;
		p=ac[p][t];
	}
	return flag[p];
}
char s[4123];
int n;
int main()
{
	FILE *fp=fopen("C:\\fdsfsda\\garbled_email_dictionary.txt","r");
	char str[13];
	int ml=0;
	init();
	while (fscanf(fp,"%s",str)!=EOF)
	{
		ins(str);
	}
	int i,j,k,n,cas,cc=0,ii,jj;
	freopen("C:\\fdsfsda\\C-small-attempt0 (10).in","r",stdin);
	freopen("C:\\fdsfsda\\Cout.txt","w",stdout);
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%s",s+1);
		int l=strlen(s+1);
		
		memset(dp,10,sizeof(dp));
		dp[0][0]=0;
		for (i=0;i<l;i++)
		{
			for (j=0;j<l;j++)if (dp[i][j]<10000)
			{
				string u="";
				for (k=1;k<=10;k++)
				{
					u+=s[i+k];
					if (find(u))
					{
						dp[i+k][j]=min(dp[i+k][j],dp[i][j]);
					}
					for (ii=0;ii<u.length();ii++)
					{
						int p=i+1+ii;
						if (j>0&&p-j<5)continue;
						char tmp=u[ii];
						for (char r='a';r<='z';r++)
						{
							u[ii]=r;
							if (find(u))
							{
								dp[i+k][p]=min(dp[i+k][p],dp[i][j]+1);
							}
						}
						u[ii]=tmp;
					}
					for (ii=0;ii<u.length();ii++)
					{
						int p=i+1+ii;
						if (j>0&&p-j<5)continue;
						char tmp=u[ii];
						for (char r='a';r<='z';r++)
						{
							u[ii]=r;
							for (jj=ii+5;jj<u.length();jj++)
							{
								char tt=u[jj];
								for (char c='a';c<='z';c++)
								{
									u[jj]=c;
									
									if (find(u))
									{
									//if (k==7&&u=="codejam")puts("--");
										dp[i+k][i+1+jj]=min(dp[i+k][i+1+jj],dp[i][j]+2);
									}
								}
								u[jj]=tt;
							}
						}
						u[ii]=tmp;
					}
				}
			}
		}
		int ans=l;
		for (i=0;i<=l;i++)
		{
			ans=min(ans,dp[l][i]);
		}
		printf("Case #%d: %d\n",++cc,ans);
	}
	return 0;
}
