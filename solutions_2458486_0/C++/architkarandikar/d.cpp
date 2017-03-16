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
#include <ctime>
#include <limits>
#include <string>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define forup(i,a,b) for(int i=a; i<b; ++i)
#define fordn(i,a,b) for(int i=a; i>b; --i)
#define rep(i,a) for(int i=0; i<a; ++i)

#define dforup(i,a,b) for(i=a; i<b; ++i)
#define dfordn(i,a,b) for(i=a; i>b; --i)
#define drep(i,a) for(i=0; i<a; ++i)

#define slenn(s,n) for(n=0; s[n]!='\0'; ++n)

#define gi(x) scanf("%d",&x)
#define gl(x) cin>>x
#define gd(x) scanf("%lf",&x)
#define gs(x) scanf("%s",x)

#define pis(x) printf("%d ",x)
#define pin(x) printf("%d\n",x)
#define pls(x) cout<<x<<" "
#define pln(x) cout<<x<<"\n"
#define pds(x) printf("%.12f ",x)
#define pdn(x) printf("%.12f\n",x)
#define pnl() printf("\n")

#define fs first
#define sc second

#define pb push_back

const int inv=numeric_limits<int>::max();
const int minv=numeric_limits<int>::min();

const int max_p2n=1048586;
const int max_n=25;
const int kt=200;

int T;

int n,ik;

int ip[max_n];
int op[max_n][kt];

int net[max_p2n][kt];
bool netpos[max_p2n];

int mark[max_p2n];
int res[max_p2n][max_n];

int main()
{
	gi(T);
	
	rep(z,T)
	{
		gi(ik); gi(n);
		
		netpos[0]=true;
		rep(i,kt)
			net[0][i]=0;
		
		int ct;
		rep(i,ik)
		{
			gi(ct); --ct;
			++net[0][ct];
		}
		
		rep(i,n)
		{
			gi(ip[i]); --ip[i];
			gi(ik);
			rep(j,kt)
				op[i][j]=0;
			rep(j,ik)
			{
				gi(ct); --ct;
				++op[i][ct];
			}
		}
		
		forup(g,1,(1<<n))
		{
			for(int b=0; b<n; ++b)
			{
				if((g>>b)%2)
				{
					rep(i,kt)
						net[g][i]=net[g-(1<<b)][i]+op[b][i];
					--net[g][ip[b]];
					
					netpos[g]=true;
					rep(i,kt)
						netpos[g] = netpos[g] and (net[g][i]>=0);
					
					break;
				}
			}
		}
		
		/*rep(g,(1<<n))
		{
			cout<<g<<": "<<netpos[g]<<": ";
			rep(i,5)
				cout<<net[g][i]<<" ";
			cout<<"\n";
		}*/
		
		mark[0]=true;
		forup(g,1,(1<<n))
		{
			int n1g=0;
			rep(b,n)
				n1g+=((g>>b)%2);
			
			mark[g]=false;
			rep(i,n1g)
				res[g][i]=n;
			
			rep(b,n)
			{
				//cout<<g<<" "<<b<<": "<<((g>>b)%2)<<" "<<mark[g-(1<<b)]<<" "<<netpos[g]<<endl;
				if(((g>>b)%2) and mark[g-(1<<b)] and net[g-(1<<b)][ip[b]]>0 and netpos[g])
				{
					mark[g]=true;
					//cout<<g<<" "<<mark[g]<<endl;
					
					int cdt[max_n];
					rep(i,n1g-1)
						cdt[i]=res[g-(1<<b)][i];
					cdt[n1g-1]=b;
					
					bool better;
					rep(i,n1g)
					{
						if(cdt[i]<res[g][i]) {better=true; break;}
						else if(cdt[i]>res[g][i]) {better=false; break;}
					}
					
					if(better)
					{
						rep(i,n1g)
							res[g][i]=cdt[i];
					}
				}
			}
			
			/*cout<<g<<" : ";
			if(mark[g])
			{
				rep(i,n1g)
					cout<<res[g][i]<<" ";
			}
			cout<<endl;*/
		}
		
		//cout<<"AA: "<<mark[15]<<" "<<(1>>n)-1<<endl;
		printf("Case #%d: ",z+1);
		if(not mark[(1<<n)-1])
			printf("IMPOSSIBLE\n");
		else
		{
			rep(i,n)
				printf("%d ",res[(1<<n)-1][i]+1);
			printf("\n");
		}
	}
	
	return 0;
}