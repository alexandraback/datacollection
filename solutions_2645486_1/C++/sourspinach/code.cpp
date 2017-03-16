#define DEBUG 1

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
using namespace std;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define Fox(i,n) for (i=0; i<n; i++)
#define Fox1(i,n) for (i=1; i<=n; i++)
#define FoxI(i,a,b) for (i=a; i<=b; i++)
#define FoxR(i,n) for (i=n-1; i>=0; i--)
#define FoxR1(i,n) for (i=n; i>0; i--)
#define FoxRI(i,a,b) for (i=b; i>=a; i--)
#define Foxen(i,s) for (i=s.begin(); i!=s.end(); i++)
#define Min(a,b) a=min(a,b)
#define Max(a,b) a=max(a,b)
#define Sz(s) int((s).size())
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second

template<typename T> T Abs(T x) { return(x<0 ? -x : x); }
template<typename T> T Sqr(T x) { return(x*x); }
string plural(string s) { return(Sz(s) && s[Sz(s)-1]=='x' ? s+"en" : s+"s"); }

const int INF = (int)1e9;
const LD EPS = 1e-9;
const LD PI = acos(-1.0);

#if DEBUG
#define GETCHAR getchar
#else
#define GETCHAR getchar_unlocked
#endif

void Read(int &x)
{
	char c,r=0,n=0;
	x=0;
		for(;;)
		{
			c=GETCHAR();
				if ((c=='-') && (!r))
					n=1;
				else
				if ((c>='0') && (c<='9'))
					x=x*10+c-'0',r=1;
				else
				if (r)
					break;
		}
		if (n)
			x=-x;
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	freopen("b.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T,t;
	int E,R,N,M;
	int i,j,k,ind;
	LL mx;
	static LL V[10000];
	static LL dyn1[10005][10005]; //dyn1[i][j] = max. value to be at event i with R*j energy
	static LL dyn2[10005]; //dyn2[i] = max. value to be at event i with E energy
	Read(T);
		Fox1(t,T)
		{
			Read(E),Read(R),Read(N);
			Min(R,E);
				Fox(i,N)
					scanf("%lld",&V[i]);
				Fox(i,N+1)
				{
						Fox(j,N+1)
							dyn1[i][j]=0;
					dyn2[i]=0;
				}
			M=min(E/R,N);
				Fox(i,N)
				{
					//use no energy
						Fox1(j,M-1)
							Max(dyn1[i+1][j+1],dyn1[i][j]);
					//use all energy
						Fox1(j,M)
							Max(dyn1[i+1][1],dyn1[i][j]+V[i]*j*R);
					Max(dyn1[i+1][1],dyn2[i]+V[i]*E);
					//save energy for an event in the future
					mx=dyn2[i],ind=M,k=E;
						FoxI(j,i+1,N-1)
						{
							k-=R;
								if (k<0)
									break;
							mx+=V[i]*R;
								while (R*ind>=k)
								{
									Max(mx,dyn1[i][ind]+V[i]*(R*ind-k));
									ind--;
								}
							Max(dyn2[j],mx);
						}
				}
			printf("Case #%d: %lld\n",t,dyn1[N][1]);
		}
	return(0);
}