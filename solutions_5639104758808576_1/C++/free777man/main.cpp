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

char s[1010];
int n;

void solve()
{
	scanf("%d %s",&n,s);
	int res = 0, sum = 0;
	REP(i,n+1)if(s[i]>'0')
	{
		if(sum<i)res+=i-sum,sum=i;
		sum+=s[i]-'0';
	}

	printf("%d\n",res);
}

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("outputA.txt","w+",stdout);
	int T;
	scanf("%d",&T);
	REP(i,T)printf("Case #%d: ",i+1),solve();
}
