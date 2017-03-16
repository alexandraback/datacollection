#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int T;
	cin >> T;

	for(int t = 1; t <= T; t++) {
		int N;
		vector<int> ans;
		vector<int> cnt;
		cnt.resize(3000);
		fill(cnt.begin(), cnt.end(), 0);

		cin >> N;
		for(int i = 0; i < N*2-1; i++) {
			for(int i = 0; i < N; i++) {
				int tmp;
				cin >> tmp;
				cnt[tmp]++;
			}
		}

		for(int i = 0; i < cnt.size(); i++) {
			if(cnt[i] % 2) {
				ans.push_back(i);
			}
		}

		cout << "Case #" << t << ":";
		for(int i = 0; i < ans.size(); i++)
			cout << " " << ans[i];
		cout << endl;
	}
}
