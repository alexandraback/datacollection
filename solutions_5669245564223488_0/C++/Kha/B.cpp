#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <algorithm>
#include <iomanip>
#include <complex>
#include <valarray>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define rep(i,s,e) for (int i=(s);i<(e);++i)
#define pb push_back
#define mk make_pair
#define fst first
#define snd second
#define all(x) (x).begin(),(x).end()
#define clr(x,y) memset(x,y,sizeof x)
#define contains(x,y) (x).find(y)!=(x).end()
#define endl "\n"

int dx[]={0,0,1,-1,1,-1,1,-1}, dy[]={-1,1,0,0,1,-1,-1,1};
const int mod = 1e9+7;

ll fact(int n) {
	ll sol = 1;
	rep(i,1,n+1)
		sol = (sol * i) % mod;
	return sol;
}

ll part(vector<string>& cars) {
	map<char, int> unicars;
	map<char, int> occ;
	map<int, bool> unicar;
	rep(i,0,cars.size()) {
		string &car = cars[i];
		rep (j,1,car.size())
			if (cars[i][j] != cars[i][0]) goto het;
		unicars[cars[i][0]]++;
		unicar[i] = true;
		continue;
het:;
	}
	rep(i,0,cars.size()) {
		string &car = cars[i];
		if (unicar[i]) continue;
		for (auto c = car.begin(); c != car.end(); c++) {
			if (c != car.begin() && *(c-1) == *c)
				continue;
			if (c != car.begin())
					while (c+1 != car.end() && *(c+1) == *c) c++;

			if (occ[*c]) {
				if (c == car.begin()) {
					if (occ[*c] != 2) // end
						return 0;
					else
						occ[*c] = 3; // closed
				} else {
					if (c+1 == car.end() && occ[*c] == 1) // begin
						occ[*c] = 3;
					else
						return 0;
				}
			} else {
				if (c == car.begin())
					occ[*c] = 1;
				else if (c+1 == car.end())
					occ[*c] = 2;
				else {
					if (!unicars[*c])
						occ[*c] = 4; // mid
					else return 0;
				}
			}
		}
	}
	ll sol = 1;
	for (auto p : unicars)
		sol = (sol * fact(p.snd)) % mod;
	//cout << "sol " << sol << endl;
	return sol;
}

int main() {
	ios::sync_with_stdio(0);
	cout << fixed << setprecision(16);

	int t;
	cin >> t;
	for (int ti = 1; ti <= t; ti++) {
		cout << "Case #" << ti << ": ";
		int n;
		cin >> n;
		vector<string> cars(n);
		rep(i,0,n) cin >> cars[i];
		vector<bool> partitioned(n);
		int partitions = 0;
		ll sol = 1;
		rep(i,0,n) {
			if (partitioned[i]) continue;
			partitions++;
			set<char> chars;
			vector<string> partition;
			partitioned[i] = true;
			partition.pb(cars[i]);
			chars.insert(all(cars[i]));
			bool changed;
			do {
				changed = false;
				rep(j,0,n) {
					if (!partitioned[j])
						for (char c : cars[j])
							if (chars.count(c)) {
								partitioned[j] = true;
								partition.pb(cars[j]);
								chars.insert(all(cars[j]));
								changed = true;
								break;
							}
				}
			} while (changed);
			//for (auto car : partition)
			//	cout << car << " ";
			//cout << endl;
			sol = (sol * part(partition)) % mod;
		}
		sol = (sol * fact(partitions)) % mod;
		cout << sol << endl;
	}
}
