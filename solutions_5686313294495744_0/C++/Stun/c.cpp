#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>
#include <unordered_map>

using namespace std;

struct Item {
	int first;
	int second;
	bool unique;

	bool operator < (const Item & o) const {
		if (unique != o.unique) return unique;
		if (first != o.first) return first < o.first;
		return second < o.second;
	}
};

int sol(vector<Item> & in) {
	int ret = 0;
	vector<bool> seen1(in.size(), 0);
	vector<bool> seen2(in.size(), 0);
	for (int i = 0 ; i < in.size() ; ++i) {
		if (seen1[in[i].first]  && seen2[in[i].second])
			ret++;
		seen1[in[i].first] = true;
		seen2[in[i].second] = true;
	}
	return ret;
}

int solve(vector<Item> & in) {
	std::sort(in.begin(), in.end());
	int x = 0;
	for (int i = 0 ; i < in.size() ; ++i) {
		if (!in[i].unique) break;
		++x;
	}
	int ret = 0;
	do {
		ret = max(ret, sol(in));
	}while(next_permutation(in.begin() + x, in.end()));
	return ret;
}

int main(){
	int tcase;
	cin >> tcase;
	
	for(size_t casen = 0; casen < tcase; ++casen)
	{
		
		cout << "Case #" << casen + 1 << ": ";

		unordered_map<string, int> M1, M2;
		string a, b;
		int t;
		cin >> t;
		vector<Item> input(t);
		vector<int> X1(t, 0);
		vector<int> X2(t, 0);
		for (int i = 0 ; i < t ; ++i) {
			cin >> a >> b;
			if (M1.count(a) == 0) 
				M1.emplace(a, M1.size());
			if (M2.count(b) == 0) 
				M2.emplace(b, M2.size());
			input[i] = {M1[a], M2[b], false};
			X1[M1[a]]++;
			X2[M2[a]]++;
		}
		for (int i = 0 ; i < input.size() ; ++i) {
			if (X1[input[i].first] < 2 || X2[input[i].second] < 2) {
				input[i].unique = true;
			}
		}
		cout << solve(input) << endl;
		
	}
	

	return 0;
}
