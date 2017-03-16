#include <vector>
#include <queue>
#include <climits>
#include <list>
#include <map>
#include <set>
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
#include <cstring>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for(int i=n-1;i>=0;--i)
#define EACH(it,v) for(typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define CLEAR(x,with) memset(x,with,sizeof(x))
#define sz size()
#define mkp make_pair
typedef long long LL;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef pair <int, int> PI;
typedef vector <PI> VPI;

int rev(int N)
{
	int ret = 0;
	while(N != 0)
	{
		ret = ret * 10;
		ret = ret + N%10;
		N /=10;
	}

	return ret;

}

VI pre;
int calc(int n)
{
	int r = rev(n);

	int ret;
	if(r < n && rev(r) == n)
	{
		ret = min(pre[n-1],pre[r]) + 1;
	}
	else
	{
		ret = pre[n-1] + 1;
	}

	return ret;
}

int main()
{
	REP(i, 21)
	pre.pb(i);

	FOR(i, 21, 1000001)
	pre.pb(calc(i));

	int T; cin >> T;
	FOR(kase, 1, T+1)
	{
		int N; cin >> N;

		cout << "Case #" << kase << ": " << pre[N] << "\n";
	}

	return 0;
}
