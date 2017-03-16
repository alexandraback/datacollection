#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	FILE *f;
	freopen_s(&f, "in.txt", "rt", stdin);
	freopen_s(&f, "out.txt", "wt", stdout);

	int t;
	cin >> t;
	for (int test_num = 1; test_num <= t; ++test_num) {
		int n;
		string s;
		cin >> n >> s;
		int clapping = 0, need = 0;
		for (int i = 0; i < s.length(); ++i) {
			int count = s[i] - '0';
			if (clapping < i)
				need += i - clapping;
			clapping = max(clapping, i) + count;
		}
		cout << "Case #" << test_num << ": " << need << endl;
	}
}