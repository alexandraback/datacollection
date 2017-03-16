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


string solve()
{
	set<pair<pair<int,int>,int>> fashion;
	map<pair<int,int>,int> combJS;
	vector<pair<int,int>> combJP;
	vector<pair<int,int>> combPS;

	int J, P, S, K;
	cin >> J >> P >> S >> K;
	rep(i, J)
		rep(j, P)
			rep(k, K)
				combJP.pb(mp(i + 1, j + 1));
	rep(i, P)
		rep(j, S)
			rep(k, K)
				combPS.pb(mp(i + 1, j + 1));
	rep(i, combJP.size()) {
		rep(j, combPS.size()) {
			if(combPS[j].first < 0)
				continue;
			if(combJP[i].second != combPS[j].first)
				continue;
			if(fashion.find(mp(combJP[i], combPS[j].second)) != fashion.end())
				continue;
			if(combJS[mp(combJP[i].first, combPS[j].second)] >= K)
				continue;
			fashion.insert(mp(combJP[i], combPS[j].second));
			combJS[mp(combJP[i].first, combPS[j].second)]++;

			combPS[j] = mp(-1, -1);
			break;
		}
	}

	string result = to_string(fashion.size());
	for(auto it = fashion.begin() ; it != fashion.end() ; ++it)
		result += "\n" + to_string(it->first.first) + " " + to_string(it->first.second) + " " + to_string(it->second);
	return result;
}

int main()
{
	int T;

	cin >> T;
	rep(i, T)
		cout << "Case #" << (i + 1) << ": " << solve() << endl;
}

