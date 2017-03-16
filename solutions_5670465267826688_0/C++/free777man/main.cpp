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

int f[8][8] =
{
	{0, 1, 2, 3, 4, 5, 6, 7},
	{1, 4, 3, 6, 5, 0, 7, 2},
	{2, 7, 4, 1, 6, 3, 0, 5},
	{3, 2, 5, 4, 7, 6, 1, 0},
	{4, 5, 6, 7, 0, 1, 2, 3},
	{5, 0, 7, 2, 1, 4, 3, 6},
	{6, 3, 0, 5, 2, 7, 4, 1},
	{7, 6, 1, 0, 3, 2, 5, 4}
};

char s[10010];

void solve()
{
	int n,m,v=0,state=0,c;
	scanf("%d %d %s",&n,&m,s);

	int cnt=min(m,(m&3)+12);
	REP(ttt,cnt)REP(i,n)
	{
		c=s[i]=='i'?1:s[i]=='j'?2:3;
		v=f[v][c];
		if(state<3&&v==state+1)++state,v=0;
	}

	printf("%s\n",state==3&&v==0?"YES":"NO");
}

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("outputC.txt","w+",stdout);
	int T;
	scanf("%d",&T);
	REP(i,T)printf("Case #%d: ",i+1),solve();
}
