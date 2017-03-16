#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>

using namespace std;

string s;
int T;
int n;
long long a;
long long f;
long long ans;

int main() {
	cin >> T;
	for (int caseNum = 0; caseNum < T; ++caseNum) {
		cin >> s >> n;
		a = 0;
		f = 0;
		ans = 0;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || 
				s[i] == 'o' || s[i] == 'u') {
				a = 0;
			} else {
				a ++;
			}
			if (a >= n) {
				f = i + 2 - n;
			}
			ans += f;
		}
		cout << "Case #" << caseNum + 1 << ": " << ans << endl;
	}
}