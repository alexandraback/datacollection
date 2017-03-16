#include <bits/stdc++.h>

using namespace std;

int cnt[26];
int digs[10];

bool can_sub(string s)
{
	for (int i = 0; i < s.size(); i++) {
		if (cnt[s[i] - 'A'] == 0) return false;
	}
	return true;
}

void sub(string s)
{
	for (int i = 0; i < s.size(); i++) {
		cnt[s[i] - 'A']--;
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL

    int n;
    cin >> n;
    for (int tc = 1; tc <= n; tc++) {
		string s;
		cin >> s;

		fill_n(cnt, 26, 0);
		fill_n(digs, 10, 0);

		for (int i = 0; i < s.size(); i++) {
			cnt[s[i] - 'A']++;
		}

		while (can_sub("ZERO")) digs[0]++, sub("ZERO"); // z unique
		while (can_sub("SIX")) digs[6]++, sub("SIX"); // x unique
		while (can_sub("TWO")) digs[2]++, sub("TWO"); // w unique
		while (can_sub("EIGHT")) digs[8]++, sub("EIGHT"); // h unique
		while (can_sub("SEVEN")) digs[7]++, sub("SEVEN"); // s unique after six reduced
		while (can_sub("FIVE")) digs[5]++, sub("FIVE"); // v unique after seven reduced
		while (can_sub("FOUR")) digs[4]++, sub("FOUR"); // f unique after five reduced
		while (can_sub("ONE")) digs[1]++, sub("ONE"); // o unique after four reduced
		while (can_sub("THREE")) digs[3]++, sub("THREE"); // t unique after one reduced
		while (can_sub("NINE")) digs[9]++, sub("NINE"); // n unique after three reduced

		for (int i = 0; i < 26; i++) {
			assert(cnt[i] == 0);
		}

		cout << "Case #" << tc << ": ";
		for (int i = 0; i < 10; i++) {
			while (digs[i]--) cout << i;
		}
		cout << endl;

    }
    return 0;
}
