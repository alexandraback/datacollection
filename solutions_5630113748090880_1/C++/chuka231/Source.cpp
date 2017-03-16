#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<bitset>
#include<vector>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<iomanip>
#include <functional>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const int INF = 1 << 28;
//cout << fixed << std::setprecision(9)
//memset(a, 0, sizeof(a));
//--------------------------

int t;

int main()
{
	cin >> t;
	for (int i = 0; i < t; i++) {
		int h[2505];
		memset(h, 0, sizeof(h));
		int n;
		cin >> n;

		for (int l = 1; l < 2 * n; l++)
			for (int k = 0; k < n; k++) {
				int f;
				cin >> f;
				h[f]++;
			}

		vector<int> ans;
		for (int j = 0; j < 2505; j++) {
			if (h[j] % 2) {
				ans.push_back(j);
			}
		}

		sort(ans.begin(), ans.end());

		cout << "Case #" << i + 1 << ": ";
		for (int j = 0; j < ans.size(); j++) {
			if (j == 0) cout << ans[j];
			else cout << " " << ans[j];
		}
		cout << endl;
	}

	return 0;
}


//int t;
//
//int main()
//{
//	cin >> t;
//	for (int i = 0; i < t; i++) {
//		string s;
//		string ans = "";
//		cin >> s;
//
//		for (int j = 0; j < s.size(); j++) {
//			if (ans.size() == 0) ans += s[j];
//			else {
//				if (ans[0] > s[j]) ans += s[j];
//				else ans = s[j] + ans;
//			}
//		}
//
//		cout << "Case #" << i + 1 << ": " << ans << endl;
//	}
//
//	return 0;
//}