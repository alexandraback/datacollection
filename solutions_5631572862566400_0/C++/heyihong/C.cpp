#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int N(1010);

int f[N];
int max_len[N];
int pos[N];

int main() {
	int test_cases;
	cin >> test_cases;
	for (int tc = 1; tc <= test_cases; ++tc) {
		int n, fri;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> fri;
			f[i] = fri;
		}
		int result = 0;		
		memset(max_len, 0, sizeof(max_len));
		for (int i = 1; i <= n; ++i) {
			memset(pos, -1, sizeof(pos));
			int t = 0;
			int x = i;
			for (; pos[x] == -1; x = f[x]) {
				pos[x] = t++;
			}
			result = max(result, t - pos[x]);	
			if (t - pos[x] == 2) {
				max_len[x] = max(max_len[x], t - 1);
			}
			//cout << i << " " << min_idx << " " << t << " " << t - pos[x] << endl;
		}
		int total_len = 0;
		for (int i = 1; i <= n; ++i) {
			total_len += max_len[i];
		}
		result = max(result, total_len);
		cout << "Case #" << tc << ": " << result << endl;
	}
	return 0;
}
