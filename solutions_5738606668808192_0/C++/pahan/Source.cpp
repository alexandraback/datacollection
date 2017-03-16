#include<iostream>
#include<cstdio>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<cassert>
using namespace std;
using ll = long long;

string genrand(int n) {
	string s("1");
	for (int i = 0; i < n-2; i++)
		s.push_back((rand()&1) ? '1' : '0');
	s.push_back('1');
	return s;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	srand(time(NULL));

	int n = 16;
	int cntgen = 0;
	cout << "Case #1:" << endl;
	while (cntgen != 50) {
		string s = genrand(n);
		bool fail = false;
		vector<int> proof;
		for (int i = 2; i <= 10; i++) {
			for (int d = 2; d <= 1000; d++) {
				int rest = 0;
				for (int j = 0; j < n; j++) {
					int currest = (s[j] == '1');
					for (int k = 0; k < j; k++)
						currest = currest * i % d;
					rest = (currest + rest) % d;
				}
				if (rest == 0) {
					proof.push_back(d);
					break;
				}
			}
			if (proof.size() != i-1) {
				fail = true;
				break;
			}
		}
		if (!fail) {
			reverse(s.begin(), s.end());
			cout << s;
			for (int i = 0; i < proof.size(); i++)
				cout << ' ' << proof[i];
			cout << endl;
			cntgen++;
		}
	}

#ifdef LOCAL
	cerr << "time : " << (double)clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}