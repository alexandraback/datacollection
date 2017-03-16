#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
using namespace std;

int get_kth(int a, int k) {
	int ans = (a >> k);
	return ans % 2;
}

int invert_kth(int a, int k) {
	int ans = a ^= (1 << k);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	cin >> tests;
	for (int test = 0; test < tests; test++) {
		cout << "Case #" << test + 1 << ": ";
		int n;
		cin >> n;
		set <string> dict;
		vector <pair<string, string> > input;
		for (int i = 0; i < n; i++) {
			string x, y;
			cin >> x >> y;
			input.push_back(make_pair(x, y));
			dict.insert(x);
			dict.insert(y);
		}
		map <string, int> numer;
		vector <pair<int, int> > arr;
		int nm = 0;
		for (auto k : dict) {
			numer[k] = nm;
			nm += 1;
		}
		for (int i = 0; i < n; i++) {
			arr.push_back(make_pair(numer[input[i].first], numer[input[i].second]));
		}
		vector <int> ans(100000, -1);
		ans[0] = 0;
		for (int i = 0; i < n; i++) {
			ans[invert_kth(0, i)] = 0;
			for (int j = i + 1; j < n; j++) {
				ans[invert_kth(invert_kth(0, i), j)] = 0;
			}
		}
		for (int i = 0; i < (1<<n); i++) {
			// cout << i << " " << ans[i] << endl;
			if (ans[i] == -1) {
				ans[i] = 0;
				for (int j = 0; j < n; j++) {
					if (get_kth(i, j) == 1) {
						int newmask = invert_kth(i, j);
						bool firstex = false;
						bool secex = false;

						for (int t = 0; t < n; t++) {
							if (get_kth(newmask, t) and arr[t].first == arr[j].first) {
								firstex = true;
							}
							if (get_kth(newmask, t) and arr[t].second == arr[j].second) {
								secex = true;
							}
						}

						if (firstex and secex) {
							ans[i] = max(ans[i], ans[newmask] + 1);
						}
					}
				} 
			}
		}
		int answer = ans[(1<<n)-1];
		cout << answer << endl;
		ans.clear();

	}

	fclose(stdin);
	fclose(stdout);
	// while (1==1) {
	// 	int x, y;
	// 	cin >> x >> y;
	// 	cout << set0_kth(x, y) << endl;
	// }
	return 0;
}