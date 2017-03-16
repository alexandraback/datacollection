#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <utility>
#include <list>
#include <functional>

#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <sstream>
#include <iterator>
#include <stack>
#include <queue>
#include <numeric>
using namespace std;

#define	mp						make_pair
#define	pb						push_back
#define	For(i,a,b)				for(int i=(a);i<(b);++i)
#define	rep(i,n)				For(i,0,(n))
#define	all(v)					(v).begin(),(v).end()

typedef	long long				LL;
typedef	vector<int>				VI;
typedef	vector<LL>				VLL;
typedef	vector<vector<int> >	VVI;
typedef	vector<bool>			VB;
typedef	vector<string>			VS;
typedef	pair<int,int>			PII;


int calc(int use, const vector<pair<string, string>> &wlist)
{
	set<string> fword, sword;

	int result = 0;
	rep(i, wlist.size()) {
		if(use & (1 << i)) {
			if(fword.find(wlist[i].first) != fword.end() && sword.find(wlist[i].second) != sword.end()) {
				return 0;
			} else {
				fword.insert(wlist[i].first);
				sword.insert(wlist[i].second);
			}
		}
	}
	rep(i, wlist.size()) {
		if(!(use & (1 << i))) {
			if(fword.find(wlist[i].first) == fword.end() || sword.find(wlist[i].second) == sword.end()) {
				return 0;
			}
			++result;
		}
	}
	return result;
}

int solve()
{
	int N;

	cin >> N;
	vector<pair<string, string>> wlist;

	rep(i, N) {
		pair<string, string> t;
		cin >> t.first >> t.second;
		wlist.pb(t);
	}

	int  result = -1;
	rep(i, 1 << N) {
		int tmp = calc(i, wlist);
		result = max(result, tmp);
	}

	return result;
}

int main()
{
	int T;

	cin >> T;
	rep(i, T)
		cout << "Case #" << (i + 1) << ": " << solve() << endl;
}

