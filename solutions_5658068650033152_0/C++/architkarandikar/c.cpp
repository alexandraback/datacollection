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
#include <cassert>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define forup(i,a,b) for(int i=a; i<b; ++i)
#define fordn(i,a,b) for(int i=a; i>b; --i)
#define rep(i,a) for(int i=0; i<a; ++i)

#define dforup(i,a,b) for(i=a; i<b; ++i)
#define dfordn(i,a,b) for(i=a; i>b; --i)
#define drep(i,a) for(i=0; i<a; ++i)

#define slenn(s,n) for(n=0; s[n]!=13 and s[n]!=0; ++n);s[n]=0

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

const int inv=1000000000;
const int minv=-inv;

const int max_m=20+5;
const int max_n=20+5;
const int max_mn=20+5;

int di[4]={-1,1,0,0};
int dj[4]={0,0,-1,1};

int T;
int m,n,k;
int res;

vector<int> adjl[max_mn];
bool edge[max_mn];
int f(int i, int j) { return n*i+j; }

bool visited[max_mn];
queue<int> Q;

int main()
{
	gi(T);

	rep(z,T)
	{
		printf("Case #%d: ",z+1);

		gi(m); gi(n); gi(k);
		res=k;

		//cout<<m<<" "<<n<<" "<<m*n<<"\n";

		rep(i,m*n) adjl[i].clear();
		rep(i,m)
			rep(j,n)
			{
				rep(dir,4)
				{
					int ni=i+di[dir], nj=j+dj[dir];
					if(0<=ni and ni<m and 0<=nj and nj<n)
						adjl[f(i,j)].pb(f(ni,nj));
				}
			}

		fill(edge,edge+m*n,false);
		rep(i,m)
			rep(j,n)
				if(i==0 or i==m-1 or j==0 or j==n-1)
					edge[f(i,j)]=true;

		rep(mask,(1<<(m*n)))
		{
			int nmask=0;
			rep(i,m*n)
				if(((mask)&(1<<i)))
					++nmask;

			if(nmask>=k) continue;

			int enclosed=0;
			rep(s,m*n)
			{
				if((mask)&(1<<s))
				{
					++enclosed;
					continue;
				}

				if(edge[s]) continue;

				bool closed=true;
				while(!Q.empty()) Q.pop();
				fill(visited,visited+m*n,false);
				Q.push(s);
				visited[s]=true;
				while(!Q.empty() and closed)
				{
					int vt=Q.front(); Q.pop();

					//cout<<s<<" "<<vt<<" "<<adjl[vt].size()<<"\n";

					int nb;
					rep(i,(int)adjl[vt].size())
					{
						nb=adjl[vt][i];
						//cout<<"@ "<<s<<" "<<vt<<" "<<nb<<" "<<visited[nb]<<" "<<edge[nb]<<"\n";
						if((mask&(1<<nb))==0 and (not visited[nb]))
						{
							if(edge[nb])
							{
								closed=false;
								break;
							}

							visited[nb]=true;
							Q.push(nb);
						}
					}
				}

				enclosed+=closed;
			}

			//cout<<mask<<" "<<nmask<<" "<<enclosed<<"\n";

			if(enclosed>=k)
				res=min(res,nmask);
		}

		pin(res);
	}
	
	return 0;
}