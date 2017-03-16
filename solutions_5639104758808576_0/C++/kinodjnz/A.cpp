#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <string.h>

typedef long long ll;
using namespace std;

int solve(int smax, const string &s)
{
	vector<int> shyness;
	for (int i = 0; i <= smax; i++) {
		shyness.push_back(s[i]-'0');
	}
	int standing = 0;
	int ans = 0;
	for (int i = 0; i <= smax; i++) {
		if (standing < i) {
			ans += i - standing;
			standing = i;
		}
		standing += shyness[i];
	}
	return ans;
}

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int smax;
		string s;
		cin >> smax >> s;
		int ans = solve(smax, s);
		cout << "Case #" << t+1 << ": " << ans << endl;
	}
}
