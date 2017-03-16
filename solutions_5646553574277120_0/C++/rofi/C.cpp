#include <cstdlib>
#include <cmath>
#include <map>
#include <utility>
#include <set>
#include <sstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <numeric>
using namespace std;

#define	mp						make_pair
#define	pb						push_back
#define	bg						begin
#define	ed						end
#define	fs						first
#define	sc						second
#define	sz(x)					((int)((x).size()))
#define	For(i,a,b)				for(int i=(a);i<(b);++i)
#define	rep(i,n)				For(i,0,(n))
#define	rFor(i,a,b)				for(int i=(a);i>=(b);--i)
#define	rrep(i,n)				rFor(i,(n),0)
#define	all(v)					(v).begin(),(v).end()
#define	ITER(type)				type::iterator
#define	EACH(type,cont,it)		for(ITER(type) it=(cont).bg,s___=(cont).ed;it!=s___;++it)

typedef	long long				LL;
typedef	vector<int>				VI;
typedef	vector<LL>				VLL;
typedef	vector<vector<int> >	VVI;
typedef	vector<bool>			VB;
typedef	vector<string>			VS;
typedef	list<int>				LI;
typedef	list<LL>				LLL;
typedef	list<string>			LS;
typedef	pair<int,int>			PII;


bool check(int V, const VB &coins)
{
	VB table(V + 1, false);

	table[0] = true;
	rep(i, coins.size()) {
		if(!coins[i])
			continue;
		VB next = table;
		rep(j, V + 1) {
			if(table[j]) {
				if(j + i <= V) {
					next[j+i] = true;
				}
			}
		}
		table = next;
	}

	return find(all(table), false) == table.end();
}

bool mint(int V, VB &coins, int num, int s)
{
	if(!num)
		return check(V, coins);

	For(i, s, V + 1) {
		if(coins[i])
			continue;
		coins[i] = true;
		if(mint(V, coins, num - 1, i + 1))
			return true;
		coins[i] = false;
	}

	return false;
}

int solve()
{
	int C, D, V;

	cin >> C >> D >> V;

	vector<int> predenom(D);
	rep(i, D)
		cin >> predenom[i];

	int res = 5;
	VB coins(V + 1, false);
	rep(i, predenom.size())
		coins[predenom[i]] = true;
	rep(i, 5) {
		if(mint(V, coins, i, 1)) {
			res = i;
			break;
		}
	}

	return res;
}

int main()
{
	int T;

	cin >> T;

	rep(i, T)
		cout << "Case #" << (i + 1) << ": " << solve() << endl;
}
