#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<vector<int>, int> mp;
int solve(vector<int> v);

int main() {

	ifstream cin("Bsmall.in");
	ofstream cout("Bsmall.txt");

	int T;
	cin >> T;
	for(int t = 0; t < T; t++)
	{
		int D;
		vector<int> v;
		mp.clear();
		cin >> D;
		for(int i = 0; i < D; i++)
		{
			int x;
			cin >> x;
			v.push_back(x);
		}

		cout << "Case #" << t + 1 << ": " << solve(v) << endl;
	}

	return 0;
}

int solve(vector<int> v) {

	sort(v.begin(), v.end());
	if(mp.count(v) > 0) return mp[v];

	int res = 0;
	for(int i = 0; i < v.size(); i++) res = max(res, v[i]);

	for(int i = 0; i < v.size(); i++)
	{
		if(v[i] < 2) continue;
		for(int j = 2; j < v[i]; j++)
		{
			vector<int> w = v;
			w[i] -= j;
			w.push_back(j);
			//for(int k = 0; k < w.size(); k++) cout << w[k];
			//cout << endl;
			res = min(res, 1 + solve(w));
		}
	}

	mp[v] = res;
	return res;
}
