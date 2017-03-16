#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <algorithm>
using namespace std;

#define ll long long;

int main() {

	ifstream cin("in.in");
	ofstream cout("out.txt");
	int T;
	cin >> T;
	for (int idx = 1; idx <= T; idx++) {
		int C, D, V;
		cin >> C >> D >> V;
		vector<int> coins(D);
		for (int i = 0; i < D; i++)
			cin >> coins[i];

		int added = 0; 
		if (coins[0] != 1) {
			coins.insert(coins.begin(), 1);
			added++;
		}

		vector<int> v;
		int range = 0;
		int j = 0;

		while (true) {
			range = 0;
			for (auto i : v) range += i;
			if (range >= V) break;
			sort(v.begin(), v.end());
			if (range == 0) {
				v.push_back(coins[j]);
				j++;
				continue;
			}
			if (j < coins.size()) {
				if (range > coins[j]) {
					v.push_back(coins[j]);
					j++;
				}
				else  
					v.push_back(range + 1);
				continue;
			}
			v.push_back(range+1);
		}


		cout << "Case #" << idx << ": " << v.size() - coins.size() + added << endl;
		//for (auto i : v) cout << i << " ";
		//cout << endl;
	}
	return 0;
}