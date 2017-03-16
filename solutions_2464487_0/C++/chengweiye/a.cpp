#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
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

#define For(i,n) for (i=0; i<int(n); i++)
#define ForR(i,n) for (i=int(n)-1; i>=0; i--)
#define Sz(s) int((s).size())
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second

template<typename T> T Abs(T x) { return(x < 0 ? -x : x); }
template<typename T> T Sqr(T x) { return(x*x); }

const int INF = (int)1e9;
const LD EPS = 1e-9;
const LD PI = acos(-1.0);

#define DEBUG 0


int main()
{
	//files
	freopen("in.in","r",stdin);
		if (!DEBUG)
			freopen("out.txt","w",stdout);
	//vars
	int tt,TT;
	long long h,t;
	//testcase loop
	scanf("%d",&TT);
		For(tt,TT)
		{
			//init
			printf("Case #%d: ",tt+1);
			//input
			scanf("%lld%lld",&h,&t);
			long long ans=1;
			long long l=1;
			long long r=t/(2*h+1);
			long long m=0;
			while(l<=r)
			{
				m=(l+r)/2;
				if(m==1) {l++; continue;}
				long long have=t-m*(2*h+1);
				long long tx=have/(2*(m-1));
				if(tx>=m)
				{
					if(ans<m) ans=m;
					l=m+1;
				}else
				{
					r=m-1;
				}

			}
			printf("%lld\n",ans);
		}
	return(0);
}