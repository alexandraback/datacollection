#include <bits/stdtr1c++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef complex<ld> pt;

string digits[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
//x, "ONE", x, "THREE", x, "FIVE", x, "SEVEN", x, "NINE"
char uniq[] = {'Z', '-', 'W', '-', 'U', '-', 'X', '-', 'G', '-'};
char uniq2[] = {'-', 'O', '-', 'T', '-', 'F', '-', 'S', '-', 'N'};
int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    for (int ca = 1; ca <= t; ca++) {
        cout << "Case #" << ca << ": ";
		
		string s; cin >> s;
		map<char, int> freq;
		vector<int> sol;
		for (char c : s) {
			freq[c]++;
		}
		
		while (true) {
			int matched = 0;
			for (int i = 0; i < 10; i++) {
				while (freq[uniq[i]]) {
					for (char c : digits[i]) {
						assert(freq[c]);
						freq[c]--;
					}
					sol.push_back(i);
					matched = 1;
				}
			}
			if (!matched) break;
		}
		
		while (true) {
			int matched = 0;
			for (int i = 0; i < 10; i++) {
				while (freq[uniq2[i]]) {
					for (char c : digits[i]) {
						assert(freq[c]);
						freq[c]--;
					}
					sol.push_back(i);
					matched = 1;
				}
			}
			if (!matched) break;
		}
		
		sort(sol.begin(), sol.end());
		for (int x : sol) {
			cout << x;
		}
		cout << endl;
    }
	return 0;
}