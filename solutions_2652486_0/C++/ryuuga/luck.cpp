#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <sstream>
#include <unordered_map>

using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,b) FOR(i,0,b)

typedef unsigned long long ll;


typedef vector<int> vi;
typedef unordered_map<int, int> mii;

string solve() {
	int r, n, m, k;
	cin >> r >> n >> m >> k;
	// r lines
	// n - a random set of size n
	// m - the maximum, all numbers between 2,m
	// k - The number of products of random subsets given

	// get at least 50 right
	//cerr << r << " " << n << " "<< m << " " << k << endl;

	vector<mii> subsets;
	vector<string> keys;
	mii ONE;
	ONE[1] = 1;
	subsets.push_back(ONE);
	keys.push_back("");

	REP(ii,n) {
		vector<mii> old_subsets;
		vector<string> old_keys;
		subsets.swap(old_subsets);
		keys.swap(old_keys);
		REP(i,old_subsets.size()) {
			const mii& s = old_subsets[i];
			const string& key = old_keys[i];

			FOR(i,2,m+1) {
				if(key.length() > 0 && i < (*key.rbegin()) - '0')
					continue;
				//cout << key << endl;;
				mii t = s;
				for(auto a: s) {
					t[a.first *i] += a.second;
				}
				subsets.push_back(t);
				char c = '0' + i;
				keys.push_back(key + c);
			}
		}
	}

	vi products(k);
	stringstream oss;

	REP(ii, r) {
		for(int& p: products)
			cin >> p;
		int best = -1;
		double best_total = 0;
		REP(i, subsets.size()){
			const mii&s = subsets[i];
			bool good = true;
			double total = 1;
			for(const int x: products) {
				if(s.count(x) == 0) {
					good = false;
					break;
				} else {
					total *= s.find(x)->second;
				}
			}
			if(good && total >= best_total) {
				best = i;
				best_total = total;
			}
		}

		oss << (best >= 0 ? keys[best] : "???") << "\n";
	}
	return oss.str();
}

int main() {
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	REP(i,t) {
		cout << "Case #" << (i+1) << ":\n" << solve();
	}
}
