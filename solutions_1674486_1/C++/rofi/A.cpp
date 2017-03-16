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


bool solve()
{
	int	N;

	cin >> N;

	VVI	inh(N);
	rep(i, N) {
		int	Mi;

		cin >> Mi;
		rep(j, Mi) {
			int	n;

			cin >> n;
			inh[i].pb(n - 1);
		}
	}
	rep(i, N) {
		VB	check(N, false);

		queue<int>	q;
		q.push(i);
		while(!q.empty()) {
			int	pos = q.front();
			q.pop();

			if(check[pos])
				return true;
			check[pos] = true;
			rep(j, inh[pos].size())
				q.push(inh[pos][j]);
		}
	}

	return false;
}

int main( void )
{
	int	T;

	cin >> T;
	rep(i, T) {
		cout << "Case #" << (i+1) << ": " << (solve() ? "Yes" : "No") << endl;
	}
}
