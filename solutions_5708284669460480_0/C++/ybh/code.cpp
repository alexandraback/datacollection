#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define FORD(i,h,l) for(int i=(h);i>=(l);--i)

#define maxn 110
//#define maxm 1010
//#define maxnumber 500000

typedef long long LL;

char key[maxn],s[maxn];
int next[maxn],f[maxn][maxn];
double g[maxn][maxn];
bool b[maxn][maxn],v[maxn][maxn];

int main()
{
	//freopen("input.txt","r",stdin);
	//reopen("output.txt","w",stdout);
	
	int T;
	scanf("%d",&T);
	for(int tcase=1;tcase<=T;tcase++)
	{
		printf("Case #%d: ",tcase);
		
		int K,L,S;
		scanf("%d%d%d",&K,&L,&S);
		scanf("%s",key+1);
		scanf("%s",s+1);
		
		memset(next,0,sizeof(next));
		next[1]=0;
		int j=0;
		FOR(i,2,L)
		{
			while (j>0 && s[j+1]!=s[i])
				j=next[j];
			if (s[j+1]==s[i]) j++;
			next[i]=j;
			//cout<<"next"<<i<<" "<<j<<endl;
		}
		
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		memset(b,0,sizeof(b));
		b[0][0]=true;
		FOR(i,0,S-1)
			FOR(j,0,min(i,L))
			{
				if (!b[i][j]) continue;
				FOR(k,1,K)
				{
					int j1=j;
					while (j1==L || j1>0 && s[j1+1]!=key[k])
						j1=next[j1];
					//if (i==3 && j==3) cout<<"!"<<j1<<endl;
					if (s[j1+1]==key[k])
					{
						if (j1+1==L)
						{
							//cout<<i<<" "<<j<<" "<<i+1<<" "<<j1+1<<endl;
							f[i+1][j1+1]=max(f[i+1][j1+1],f[i][j]+1);
							v[i+1][j1+1]+=v[i][j]*(1.0/K);
							g[i+1][j1+1]+=(g[i][j]+1*v[i][j])*(1.0/K);
							b[i+1][j1+1]=true;
						}
						else
						{
							f[i+1][j1+1]=max(f[i+1][j1+1],f[i][j]);
							v[i+1][j1+1]+=v[i][j]*(1.0/K);
							g[i+1][j1+1]+=g[i][j]*(1.0/K);
							b[i+1][j1+1]=true;
						}
					}
					else
					{
						f[i+1][0]=max(f[i+1][0],f[i][j]);
						v[i+1][0]+=v[i][j]*(1.0/K);
						g[i+1][0]+=g[i][j]*(1.0/K);
						b[i+1][0]=true;
					}
				}
			}
		
		/*FOR(i,0,S)
		{
			FOR(j,0,L)
				cout<<g[i][j]<<" ";
			cout<<endl;
		}*/
				
		int ans1=0;
		double ans2=0;
		FOR(i,0,L)
		{
			ans1=max(ans1,f[S][i]);
			ans2+=g[S][i];
		}
		//cout<<ans1<<" "<<ans2<<" ";
		printf("%.10f\n",ans1-ans2);
	}
	
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
