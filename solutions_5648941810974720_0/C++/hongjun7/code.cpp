#include <stdio.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <string.h>
#include <algorithm>
using namespace std;
int cnt[26];
char S[2005];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, runs = 0; for (scanf("%d", &T); T--; ) {
		memset(cnt, 0, sizeof(cnt));
		++runs;
		scanf("%s", S);
		int x;
		for (int i = 0; S[i]; i++) {
			x = S[i] - 'A';
			cnt[x]++;
		}
		printf("Case #%d: ", runs);
		vector <int> v;
		x = cnt['Z' - 'A'];
		for (int i = 0; i < cnt['Z' - 'A']; i++) v.push_back(0);
		cnt['Z' - 'A'] -= x; cnt['E' - 'A'] -= x; cnt['R' - 'A'] -= x; cnt['O' - 'A'] -= x;
		x = cnt['X' - 'A'];
		for (int i = 0; i < cnt['X' - 'A']; i++) v.push_back(6);
		cnt['S' - 'A'] -= x; cnt['I' - 'A'] -= x; cnt['X' - 'A'] -= x;
		x = cnt['U' - 'A'];
		for (int i = 0; i < cnt['U' - 'A']; i++) v.push_back(4);
		cnt['F' - 'A'] -= x; cnt['O' - 'A'] -= x; cnt['U' - 'A'] -= x; cnt['R' - 'A'] -= x;
		x = cnt['W' - 'A'];
		for (int i = 0; i < cnt['W' - 'A']; i++) v.push_back(2);
		cnt['T' - 'A'] -= x; cnt['W' - 'A'] -= x; cnt['O' - 'A'] -= x;
		x = cnt['G' - 'A'];
		for (int i = 0; i < cnt['G' - 'A']; i++) v.push_back(8);
		cnt['E' - 'A'] -= x; cnt['I' - 'A'] -= x; cnt['G' - 'A'] -= x; cnt['H' - 'A'] -= x; cnt['T' - 'A'] -= x;
		x = cnt['F' - 'A'];
		for (int i = 0; i < cnt['F' - 'A']; i++) v.push_back(5);
		cnt['F' - 'A'] -= x; cnt['I' - 'A'] -= x; cnt['V' - 'A'] -= x; cnt['E' - 'A'] -= x;
		x = cnt['R' - 'A'];
		for (int i = 0; i < cnt['R' - 'A']; i++) v.push_back(3);
		cnt['T' - 'A'] -= x; cnt['H' - 'A'] -= x; cnt['R' - 'A'] -= x; cnt['E' - 'A'] -= 2 * x;
		x = cnt['V' - 'A'];
		for (int i = 0; i < cnt['V' - 'A']; i++) v.push_back(7);
		cnt['S' - 'A'] -= x; cnt['E' - 'A'] -= x; cnt['V' - 'A'] -= x; cnt['E' - 'A'] -= x; cnt['N' - 'A'] -= x;
		x = cnt['O' - 'A'];
		for (int i = 0; i < cnt['O' - 'A']; i++) v.push_back(1);
		cnt['O' - 'A'] -= x; cnt['N' - 'A'] -= x; cnt['E' - 'A'] -= x;
		x = cnt['E' - 'A'];
		for (int i = 0; i < cnt['E' - 'A']; i++) v.push_back(9);
		cnt['N' - 'A'] -= x; cnt['I' - 'A'] -= x; cnt['N' - 'A'] -= x; cnt['E' - 'A'] -= x;
		sort(v.begin(), v.end());
		for (auto &y : v) printf("%d", y);
		puts("");
	}
	fcloseall();
	return 0;
}