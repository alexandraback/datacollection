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
using namespace std;
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()
#define FOR(i,s,n) for(int i=(s);i<(n);++i)
#define REP(i,n) FOR(i,0,(n))
#define PB(x) push_back((x))
#define CLR(a,v) memset((a),(v),sizeof((a)))
typedef long long ll;

int p[1010], n;

void solve()
{
	int pp,res=1010;
	CLR(p,0);
	scanf("%d",&n);
	REP(i,n)scanf("%d",&pp),++p[pp];

	FOR(j,1,1010)
	{
		int r=j;
		FOR(i,j+1,1010)r+=p[i]*((i-1)/j);
		if(r<res)res=r;
	}

	printf("%d\n",res);
}

int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("outputB.txt","w+",stdout);
	int T;
	scanf("%d",&T);
	REP(i,T)printf("Case #%d: ",i+1),solve();
}
