#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<iomanip>
#include<unordered_set>
#include<unordered_map>
#include<ctime>
#include<cstdlib>
#include<climits>
#include<string>
#include<cstring>
using namespace std;
using ll = long long;

int code(char c) {
	return c - '0';
}

int solve() {
	int n;
	cin >> n;
	vector<int> left(n), right(n);
	map<string,int> leftmap, rightmap;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		if (leftmap.find(a) != leftmap.end())
			left[i] = leftmap[a];
		else
			left[i] = leftmap[a] = leftmap.size();
		if (rightmap.find(b) != rightmap.end())
			right[i] = rightmap[b];
		else
			right[i] = rightmap[b] = rightmap.size();
	}
	int cnt = n;
	for (int i = 0; i < (1 << n); i++) {
		if (cnt <= (__popcnt(i)))
			continue;
		vector<bool> usedleft(leftmap.size(), false);
		vector<bool> usedright(rightmap.size(), false);
		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				usedleft[left[j]] = true;
				usedright[right[j]] = true;
			}
		}
		bool flag = true;
		for (int i = 0; i < usedleft.size(); i++) {
			if (!usedleft[i]) {
				flag = false;
				break;
			}
		}
		if (!flag)
			continue;
		for (int i = 0; i < usedright.size(); i++) {
			if (!usedright[i]) {
				flag = false;
				break;
			}
		}
		if (!flag)
			continue;
		cnt = __popcnt(i);
	}
	return n-cnt;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	srand(time(NULL));

	int tnumber;
	cin >> tnumber;
	for (int tcase = 1; tcase <= tnumber; tcase++) {
		cout << "Case #" << tcase << ": ";
		cout << solve();
		cout << endl;
	}

	return 0;
}