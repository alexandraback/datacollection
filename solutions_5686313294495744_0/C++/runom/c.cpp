#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main()
{
	int T; 
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		int n;
		cin >> n;
		vector<string> s1(n), s2(n);

		for(int i = 0; i < n; ++i) {
			cin >> s1[i] >> s2[i];
		}

		int ans = 0;
		for(int i = 0; i < (1 << n); ++i) {
			unordered_set<string> first, second;
			int real_num = 0;
			for(int j = 0; j < n; ++j) {
				if(i & (1 << j)) {
					first.insert(s1[j]);
					second.insert(s2[j]);
					real_num++;
				}
			}
			
			int fake_num = n - real_num;
			int cnt = 0;
			for(int j = 0; j < n; ++j) {
				if(!(i & (1 << j))) {
					if(first.count(s1[j]) && second.count(s2[j])) {
						cnt++;
					}
				}
			}

			if(cnt == fake_num) {
				ans = max(ans, cnt);
			}
		}

		cout << ans << endl;
	}
}
