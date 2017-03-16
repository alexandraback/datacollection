#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define	pb						push_back
#define	For(i,a,b)				for(int i=(a);i<(b);++i)
#define	rep(i,n)				For(i,0,(n))
#define	all(v)					(v).begin(),(v).end()


vector<int> solve()
{
	int N;
	map<int, bool> stat;

	cin >> N;
	rep(i, 2 * N - 1) {
		int h;
		rep(j, N) {
			cin >> h;
			bool tmp = stat[h];
			stat[h] = !tmp;
		}
	}

	vector<int> result;
	for(auto it = stat.begin() ; it != stat.end() ; ++it)
		if(it->second)
			result.pb(it->first);

	sort(all(result));
	return result;
}

int main()
{
	int T;

	cin >> T;
	rep(i, T) {
		cout << "Case #" << (i + 1) << ":";
		vector<int> result = solve();
		rep(i, result.size())
			cout << " " << result[i];
		cout << endl;
	}
}

