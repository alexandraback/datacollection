#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <queue>
using namespace std;
#define   sqr(a)         ((a)*(a))
#define   rep(i,a,b)  for(int i=(a);i<(int)(b);i++)
#define   per(i,a,b)  for(int i=((a)-1);i>=(int)(b);i--)
#define   PER(i,n)     per(i,n,0)
#define   REP(i,n)     rep(i,0,n)
#define   FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define   clr(a)      memset((a),0,sizeof (a))
#define   SZ(a)         ((int)((a).size()))
#define   CLEAR(a, v)    memset((a), (v), sizeof(a))
#define   ALL(v)          (v).begin(), (v).end()
#define   mabs(a)       ((a)>0?(a):(-(a)))
#define   inf         1000000001
#define  MAXN     70
#define  eps      1e-6
#define   PB push_back
#define   FI 		first
#define   SE 		second
#define   MP 		make_pair
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
typedef long long int64;
int dp[MAXN][MAXN];
struct dictree
{
	struct dictree*next[26];
	int fg;
	dictree()
	{
		CLEAR(next,0);
		fg=0;
	}
};
void insert(dictree*r,char *s)
{
	dictree*p=r;
	int l=strlen(s);
	REP(i,l)
	{
		if (!p->next[s[i]-'a'])
		{
			p->next[s[i]-'a']=new dictree;
		}
		p=p->next[s[i]-'a'];
	}
	p->fg=1;
}
bool find(dictree*r,string s)
{
	dictree*p=r;
	int t;
	REP(i,SZ(s))
	{
		if (s[i]<'a'||s[i]>'z')return 0;
		if (!p->next[s[i]-'a'])return 0;
		p=p->next[s[i]-'a'];
	}
	return p->fg;
}
char s[MAXN];
int n;
int main()
{
	FILE *fin=fopen("garbled_email_dictionary.txt","r");
	char st[13];
	dictree *root=new dictree;
	while (fscanf(fin,"%s",st)!=EOF)
	{
		insert(root,st);
	}
	int i,j,k,n,T,cc=0,ii,jj;
	freopen("C-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&T);
	REP(t,T)
	{
		scanf("%s",s+1);
		int l=strlen(s+1);
		CLEAR(dp,10);
		dp[0][0]=0;
		REP(i,l)
		{
			REP(j,l)if (dp[i][j]<10000)
			{
				string u="";
				rep(k,1,11)
				{
					u+=s[i+k];
					if (find(root,u))
					{
						dp[i+k][j]=min(dp[i+k][j],dp[i][j]);
					}
					REP(ii,SZ(u))
					{
						int p=i+1+ii;
						if (j>0&&p-j<5)continue;
						char tmp=u[ii];
						for (char r='a';r<='z';r++)
						{
							u[ii]=r;
							if (find(root,u))
							{
								dp[i+k][p]=min(dp[i+k][p],dp[i][j]+1);
								break;
							}
						}
						u[ii]=tmp;
					}
					REP(ii,SZ(u))
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
									if (find(root,u))
									{
										dp[i+k][i+1+jj]=min(dp[i+k][i+1+jj],dp[i][j]+2);
										break;
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
		REP(i,l+1)
		{
			ans=min(ans,dp[l][i]);
		}
		printf("Case #%d: %d\n",t+1,ans);
	}
	return 0;
}
