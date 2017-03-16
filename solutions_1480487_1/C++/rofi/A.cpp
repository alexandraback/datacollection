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


void solve()
{
	int		N;

	cin >> N;
	VI	cont(N);

	rep(i, N)
		cin >> cont[i];

	VI	tmp = cont;
	double	sum;
	sum = accumulate(all(cont), 0);
	sort(all(cont));

	bool	check;
	do {
		check = false;

		int	subsum = accumulate(all(cont), 0);
		rep(i, cont.size()) {
			if((sum + subsum) / cont.size() < cont[i]) {
				cont.pop_back();
				check = true;
				break;
			}
		}
	} while(check);

	int	subsum = accumulate(all(cont), 0);
	rep(i, N) {
		double	res = (sum + subsum) / cont.size();
		printf(" %.10f", res < tmp[i] ? 0.0 : (res - tmp[i]) / sum * 100.0);
	}
	puts("");
}

int main( void )
{
	int		n;
	cin >> n;
	rep(i, n) {
		printf("Case #%d:", i + 1);
		solve();
	}
}
