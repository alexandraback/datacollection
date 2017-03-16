#include <iostream>
#include <bitset>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

void backtrack(int day, int j, int p, int s, int k,
              set<vector<int> >& sets,
			  vector<vector<int> >& pairsjp,
			  vector<vector<int> >& pairsjs,
			  vector<vector<int> >& pairsps,
			  set<vector<int> >& sol, int& ma,
			  set<pair<int, set<vector<int> > > >& dp) {
	auto status = pair<int, set<vector<int> > >(day, sets);
	if (dp.find(status) != dp.end()) return;
	//cerr << dp.size() << endl;
	dp.insert(status);
	if (day > ma) {
		ma = day;
		sol = sets;
	}
    vector<int> v(3);
	for (int j2 = 0; j2 < j; ++j2) {
		v[0] = j2;
    	for (int p2 = 0; p2 < p; ++p2) {
    		v[1] = p2;
    		if (pairsjp[j2][p2] < k) {
    			for (int s2 = 0; s2 < s; ++s2) {
    				if (pairsjs[j2][s2] < k && pairsps[p2][s2] < k) {
    					v[2] = s2;
    					if (sets.find(v) == sets.end()) {
    						//cerr << j2 << ' ' << p2 << ' ' << s2 << endl;
    						sets.insert(v);
    						pairsjp[j2][p2]++;
    						pairsjs[j2][s2]++;
    						pairsps[p2][s2]++;
    						backtrack(day+1, j, p, s, k, sets, pairsjp, pairsjs, pairsps, sol, ma, dp);
    						sets.erase(v);
    						pairsjp[j2][p2]--;
    						pairsjs[j2][s2]--;
    						pairsps[p2][s2]--;
    						if (rand()%2 == 0) return;
						}
    				}
    			}
    		}
		}
	}
}

int main() {
	int cases;
	cin >> cases;
	for (int cas = 1; cas <= cases; ++cas) {
		cout << "Case #" << cas << ": ";
		int j, p, s, k;
		cin >> j >> p >> s >> k;
		set<vector<int> > sets;
		set<vector<int> > sol;
		vector<vector<int> > pairsjp(j, vector<int>(p, 0));
		vector<vector<int> > pairsjs(j, vector<int>(s, 0));
		vector<vector<int> > pairsps(p, vector<int>(s, 0));
		int ma = 0;
		set<pair<int, set<vector<int> > > > dp;
		backtrack(0, j, p, s, k, sets, pairsjp, pairsjs, pairsps, sol, ma, dp);
		cout << ma << endl;
		for (auto v : sol) cout << v[0]+1 << ' ' << v[1]+1 << ' ' << v[2]+1 << endl;
	}
}

