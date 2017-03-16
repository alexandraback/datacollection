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
	freopen("c.in","r",stdin);
	freopen("out.txt","w",stdout);
	printf("Case #1:\n");
	int R,N,M,K,B;
	int i,j,b,b2,mx,p,cnt;
	int P[7],vis[7];
	vector <int> v,ans;
	Read(i),Read(R),Read(N),Read(M),Read(K);
	B=1;
		Fox(i,N)
			B*=M-1;
		while (R--)
		{
				Fox(i,K)
					Read(P[i]);
			mx=-1;
				Fox(b,B)
				{
					v.clear();
					j=b;
						Fox(i,N)
							v.pb(j%(M-1)+2),j/=M-1;
					cnt=0;
					Fill(vis,0);
						Fox(b2,1<<N)
						{
							p=1;
								Fox(i,N)
									if (b2&(1<<i))
										p*=v[i];
								Fox(i,K)
									if (P[i]==p)
										cnt++,vis[i]=1;
						}
						Fox(i,K)
							if (!vis[i])
								goto Bad;
						if (cnt>mx)
							mx=cnt,ans=v;
Bad:;
				}
				Fox(i,N)
					printf("%d",ans[i]);
			printf("\n");
		}
	return(0);
}