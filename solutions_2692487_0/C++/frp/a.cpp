#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define infinity 2000000000
void test(int num) {
	cout << "Case #" << num << ": ";
	int a, n;
	cin >> a >> n;
	vector<int> motes(n);
	for (int i = 0; i < n; i++)
		cin >> motes[i];
	if (a == 1) {
		cout << n << endl;
		return;
	}
	sort(motes.begin(), motes.end());
	int cur = 0, actions = 0, actions_final = infinity;
	while(cur < motes.size()) {
		if (a > motes[cur]) {
			a += motes[cur];
			cur++;
		} else {
			actions_final = min(actions_final, int(actions + motes.size() - cur));
			a += a - 1;
			actions++;
		}
	}
	actions_final = min(actions_final, actions);
	cout << actions_final << endl;
}
int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++)
		test(i+1);
}
