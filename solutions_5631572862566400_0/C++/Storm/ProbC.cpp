#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>

using namespace std;

int n;
vector<int> f(1001);
int last = -1;
int count(int pos, int num, vector<int> &used)
{
	used[pos] = num;
	if (used[f[pos]] != -1) {
		if (used[f[pos]] != num - 1 && used[f[pos]] != 1) {
			last = -1;
		}
		else {
			last = pos;
		}
		return 1;
	}

	return 1 + count(f[pos], num+1, used);
}

int count2(int pos, vector<bool> &used, vector<int> &old_used)
{
	used[pos] = true;
	if (used[f[pos]] || old_used[f[pos]] != -1) {
		last = pos;
		if (old_used[f[pos]] != -1) {
			last = f[pos];
		}
		return 1;
	}
	return 1 + count2(f[pos], used, old_used);
}

int main()
{
	freopen("C:\\Projects\\gcj\\input.txt", "r", stdin);
	freopen("C:\\Projects\\gcj\\output.txt", "w", stdout);

	int z;
	cin >> z;
	for (int q1=0;q1<z;q1++) {
		cin >> n;
		for (int i=0;i<n;i++) {
			cin >> f[i];
			f[i] -= 1;
		}

		int best = -1;
		for (int k=0;k<n;k++) {
			vector<int> used(n, -1);
			int val = count(k, 1, used);
			if (last == -1)
				continue;
			best = max(best, val);
			if (f[last] == k) {
				continue;
			}
			int prev_last = last;
			for (int i=0;i<n;i++) {
				vector<bool> used2(n, false);
				if (used[i] != -1) {
					continue;
				}
				int size2 = count2(i, used2, used);
				if (used2[f[last]])
					continue;
				if (last != prev_last) {
					continue;
				}
				best = max(best, val + size2);
			}
		}

		cout << "Case #" << (q1+1) << ": " << best << endl;
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}