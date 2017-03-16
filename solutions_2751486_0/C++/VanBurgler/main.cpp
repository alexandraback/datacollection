#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

int cc(const string& name) {
	int m = 0;
	int n = 0;
	for (char c : name) {
		if (c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u')
			n = 0;
		else
			n++;
		if (n > m) m = n;
	}
	return m;
}

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		string name;
		int k;

		cin >> name >> k;

		int p = 0;

		for (int i = 0; i < name.size() - k + 1; i++)
			for (int j = i + k - 1; j < name.size(); j++)
			{
				string sub = name.substr(i, j - i + 1);
				int len = cc(sub);
				if (len >= k) p++;
			}

		cout << "Case #" << t << ": " << p << endl;
	}
}
