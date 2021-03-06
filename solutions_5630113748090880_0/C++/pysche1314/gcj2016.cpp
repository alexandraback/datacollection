#include "StdAfx.h"
#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <list>
#include <set>
#include <map>
#include <ctime>
#include <unordered_map>



using namespace std;

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	//freopen("B_large.in", "r", stdin);
	//freopen("B_large.out", "w", stdout);
	long long Tc;
	cin >> Tc;
	for (int t = 0; t < Tc; t++) {
		unordered_map<int, int> mp;
		int num;
		cin >> num;
		int lc = num * 2 - 1;
		for (int i = 0; i < lc; i++) {
			for (int j = 0; j < num; j++) {
				int tmp;
				cin >> tmp;
				mp[tmp]++;
			}
		}
		vector<int> res;
		for (auto it = mp.begin(); it != mp.end(); it++) {
			
			if (it->second % 2 != 0) res.push_back(it->first);
		}

		sort(res.begin(), res.end());

		cout << "Case #" << (t + 1) << ":";

		for (int i = 0; i < res.size(); i++) {
			cout << " " << res[i];
		}
		cout << endl;
	}
	return 0;
}