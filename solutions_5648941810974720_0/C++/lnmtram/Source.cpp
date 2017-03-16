#include <iostream>
#include <string>
using namespace std;

int main() {
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		string str;
		cin >> str;
		int cnt[10] = { 0 };
		int a[26] = { 0 };
		for (int i = 0; i < str.length(); ++i)
			a[str[i] - 'A']++;
		cnt[0] = a['Z' - 'A'];
		a['O' - 'A'] -= a['Z' - 'A'];
		a['Z' - 'A'] = 0;

		cnt[2] = a['W' - 'A'];
		a['O' - 'A'] -= a['W' - 'A'];
		a['W' - 'A'] = 0;

		cnt[4] = a['U' - 'A'];
		a['F' - 'A'] -= a['U' - 'A'];
		a['O' - 'A'] -= a['U' - 'A'];
		a['U' - 'A'] = 0;


		cnt[6] = a['X' - 'A'];
		a['S' - 'A'] -= a['X' - 'A'];
		a['I' - 'A'] -= a['X' - 'A'];
		a['X' - 'A'] = 0;

		cnt[8] = a['G' - 'A'];
		a['I' - 'A'] -= a['G' - 'A'];
		a['H' - 'A'] -= a['G' - 'A'];
		a['G' - 'A'] = 0;

		cnt[5] = a['F' - 'A'];
		a['I' - 'A'] -= a['F' - 'A'];
		a['F' - 'A'] = 0;

		cnt[7] = a['S' - 'A'];
		cnt[9] = a['I' - 'A'];
		cnt[3] = a['H' - 'A'];
		cnt[1] = a['O' - 'A'];
		
		cout << "Case #" << t+1 << ": ";
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < cnt[i]; ++j) cout << i;
		}
		cout << endl;
	}
}