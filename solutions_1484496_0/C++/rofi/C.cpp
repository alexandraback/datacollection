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

const int GN = 0;
const int GA = 1;
const int GB = 2;

int	data[100];
int	group[100];
int	index;
int	N;

bool check(int a, int b)
{
	if(a == b) {
		if(a != 0)
			return true;
	}
	if(N == index)
		return false;

	group[index] = GA;
	if(check(a + data[index++], b))
		return true;

	--index;
	group[index] = GB;
	if(check(a, b + data[index++]))
		return true;

	--index;
	group[index++] = GN;
	if(check(a, b))
		return true;

	--index;
	return false;
}

void solve()
{
	cin >> N;
	rep(i, N)
		cin >> data[i];
	index = 0;

	if(check(0, 0)) {
		bool	check = false;
		rep(i, index) {
			if(group[i] == GA) {
				if(check)
					cout << " ";
				cout << data[i];
				check = true;
			}
		}
		cout << endl;
		check = false;
		rep(i, index) {
			if(group[i] == GB) {
				if(check)
					cout << " ";
				cout << data[i];
				check = true;
			}
		}
		cout << endl;
	} else {
		cout << "Impossible" << endl;
	}
}

int main( void )
{
	int	T;

	cin >> T;
	rep(i, T) {
		cout << "Case #" << (i+1) << ":" << endl;
		solve();
	}
}
