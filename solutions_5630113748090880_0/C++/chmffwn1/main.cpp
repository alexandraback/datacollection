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
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;
using namespace std;

int main() {
	freopen("B_small.in", "r", stdin);
	freopen("B_small.out", "w", stdout);
	//freopen("B_large.in", "r", stdin);
	//freopen("B_large.out", "w", stdout);
	ll T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		unordered_map<int, int> st;
		int num;
		cin >> num;
		int lp = num * 2 - 1;
		for (int i = 0; i < lp; i++) {
			for (int j = 0; j < num; j++) {
				int tmp;
				cin >> tmp;
				st[tmp]++;
			}
		}
		vector<int> res;
		for (auto it = st.begin(); it != st.end(); it++) {
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