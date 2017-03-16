#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned int UI;

#define FOR(k,a,b) for(int k(a); k < (b); ++k)
#define FORD(k,a,b) for(int k(b-1); k >= (a); --k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define ABS(a) ((a)>0?(a):-(a))

typedef vector<int> VI;
typedef vector<pair<int,int> > VII;
typedef vector<LL> VL;
typedef vector<vector<int> > VVI;
typedef vector<bool> VB;


int main()
{
#ifdef HOME	
	clock_t startclock=clock();
	freopen ("C-small-attempt1.in","r",stdin);
	freopen ("C-small-attempt1.out","w",stdout);
	//freopen ("in.txt","r",stdin);
	//freopen ("out.txt","w",stdout);
	freopen ("out_err.txt","w",stderr);	
#endif
	FILE* dict=fopen("garbled_email_dictionary.txt","r");
	//FILE* dict=fopen("dictionary.txt","r");
	vector<string> vs;
	vs.reserve(522000);
	char c[100];
	REP(i,521196)
	//REP(i,2)
	{
		fscanf(dict,"%s",c);
		vs.push_back(c);
	}
	fclose(dict);
	int T;
	scanf("%d",&T);
	FOR(testcase,1,T+1)
	{
		scanf("%s",c);
		string str(c);
		int N=str.size();
		vector<vector<int> > dp(N+1, vector<int> (N+1,N+1));
		//last diff, actual end
		dp[0][0]=0;
		REP(i,N) FOR(o,max(i-6,0),i+1) if(dp[o][i]!=N+1)
		{
			REP(j,vs.size()) if(i+vs[j].size()<=N)
			{
				int lastdiff=o;
				bool ok=1;
				int ctr=0;
				REP(k,vs[j].size())
				{
					if(vs[j][k]!=str[i+k])
					{
						if(lastdiff!=0 && i+k-lastdiff<4)
						{
							ok=0;
							break;
						}
						else
						{
							++ctr;
						}
						lastdiff=k+1;
					}
				}
				if(ok)
				{
					if(lastdiff+5<i+vs[j].size())
					{
						lastdiff=i+vs[j].size()-5;
						lastdiff=max(0,lastdiff);
					}
					dp[lastdiff][i+vs[j].size()]=min(dp[lastdiff][i+vs[j].size()],dp[o][i]+ctr);
				}
			}
		}
		int ans=N+1;
		REP(i,N+1)
			ans=min(ans,dp[i][N]);
		printf("Case #%d: %d\n",testcase,ans);
	}
#ifdef HOME
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-startclock));
	fflush(stderr);
#endif 
	return 0;
} 