#include <iostream>
#include <string>
#include <map>
using namespace std;

typedef long long LL;
string str;
map<char, int> mp;
int temp[10][10];

int main() {
	freopen("C-large.in","r",stdin);
	freopen("c.txt","w",stdout);
	mp['1'] = 1;
	mp['i'] = 2;
	mp['j'] = 3;
	mp['k'] = 4;
	temp[1][1] = 1;
	temp[1][2] = temp[2][1] = 2;
	temp[1][3] = temp[3][1] = 3;
	temp[1][4] = temp[4][1] = 4;
	temp[2][2] = -1;
	temp[2][3] = 4;
	temp[2][4] = -3;
	temp[3][2] = -4;
	temp[3][3] = -1;
	temp[3][4] = 2;
	temp[4][2] = 3;
	temp[4][3] = -2;
	temp[4][4] = -1;
	int t;
	cin >> t;
	LL X, st, end;
	int sum, res, L;
	bool flag;
	for (int k = 1; k <= t; ++k) {
		cin >> L >> X >> str;
		if (L*X < 3) {
			cout << "Case #" << k << ": NO" << endl;
			continue;
		}
		flag = true;
		sum = res = 1;
		st = end = -1;
		for (int i = 0; i < L; ++i) {
			res = res / abs(res) * temp[abs(res)][mp[str[i]]];
		}
		if (res == 1) {
			flag = false;
		}
		else if (res == -1) {
			if (X % 2 == 0) {
				flag = false;
			}
		}
		else {
			if (X % 4 != 2) {
				flag = false;
			}
		}
		if (flag) {
			res = 1;
			for (auto i = 0; i < L * 4; ++i) {
				res = res / abs(res) * temp[abs(res)][mp[str[i % L]]];
				if (res == 2) {
					st = i;
					break;
				}
			}
			for (auto i = 4 * L - 1; i >= 0; --i) {
				sum = sum / abs(sum) * temp[mp[str[i % L]]][abs(sum)];
				if (sum == 4) {
					end = i;
					break;
				}
			}
			if (end != -1) {
				end = X * L - (4 * L - end);
			}
			if (st == -1 || end == -1 || st >= end) {
				flag = false;
			}
		}
		cout << "Case #" << k << ": " << (flag ? "YES" : "NO") << endl;
	}
	fclose(stdout);
	return 0;
}

