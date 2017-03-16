#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;
		cout << "Case #" << t << ": ";
		if (n == 0) {
			cout << "INSOMNIA" << endl;
			continue;
		}
		set <int> dig;
		for (int i = 0; i < 10; i++)
			dig.insert(i);
		int now = n;
		do {
			int cur = now;
			while (cur) {
				if (dig.count(cur % 10))
					dig.erase(cur % 10);
				cur /= 10;
			}
			now += n;
		} while (!dig.empty());

		cout << now - n << endl;
	}
}