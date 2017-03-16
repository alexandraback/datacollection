#include <cstdio>
#include <cstring>

using namespace std;

char buf[2111];
int cnt[26];
int numcnt[10];
// NINE"
int main(){
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++){
		printf("Case #%d: ", cas);
		scanf("%s", buf);
		int n = strlen(buf);
		memset(cnt, 0, sizeof(cnt));
		memset(numcnt, 0, sizeof(numcnt));
		for (int i = 0; i < n; i++)
			cnt[buf[i] - 'A'] ++;

		// 0
		numcnt[0] = cnt['Z' - 'A'];
		cnt['E' - 'A'] -= numcnt[0];
		cnt['R' - 'A'] -= numcnt[0];
		cnt['O' - 'A'] -= numcnt[0];
		cnt['Z' - 'A'] -= numcnt[0];

		// 2
		numcnt[2] = cnt['W' - 'A'];
		cnt['T' - 'A'] -= numcnt[2];
		cnt['O' - 'A'] -= numcnt[2];
		cnt['W' - 'A'] -= numcnt[2];

		// 8
		numcnt[8] = cnt['G' - 'A'];
		cnt['E' - 'A'] -= numcnt[8];
		cnt['I' - 'A'] -= numcnt[8];
		cnt['G' - 'A'] -= numcnt[8];
		cnt['H' - 'A'] -= numcnt[8];
		cnt['T' - 'A'] -= numcnt[8];
		// 3
		numcnt[3] = cnt['H' - 'A'];
		cnt['T' - 'A'] -= numcnt[3];
		cnt['H' - 'A'] -= numcnt[3];
		cnt['R' - 'A'] -= numcnt[3];
		cnt['E' - 'A'] -= numcnt[3];
		cnt['E' - 'A'] -= numcnt[3];

		// 4
		numcnt[4] = cnt['U' - 'A'];
		cnt['F' - 'A'] -= numcnt[4];
		cnt['O' - 'A'] -= numcnt[4];
		cnt['U' - 'A'] -= numcnt[4];
		cnt['R' - 'A'] -= numcnt[4];

		// 1
		numcnt[1] = cnt['O' - 'A'];
		cnt['O' - 'A'] -= numcnt[1];
		cnt['N' - 'A'] -= numcnt[1];
		cnt['E' - 'A'] -= numcnt[1];

		// 5
		numcnt[5] = cnt['F' - 'A'];
		cnt['F' - 'A'] -= numcnt[5];
		cnt['I' - 'A'] -= numcnt[5];
		cnt['V' - 'A'] -= numcnt[5];
		cnt['E' - 'A'] -= numcnt[5];

		// 7
		numcnt[7] = cnt['V' - 'A'];
		cnt['S' - 'A'] -= numcnt[7];
		cnt['E' - 'A'] -= numcnt[7];
		cnt['V' - 'A'] -= numcnt[7];
		cnt['E' - 'A'] -= numcnt[7];
		cnt['N' - 'A'] -= numcnt[7];
		// 6
		numcnt[6] = cnt['S' - 'A'];
		cnt['S' - 'A'] -= numcnt[6];
		cnt['I' - 'A'] -= numcnt[6];
		cnt['X' - 'A'] -= numcnt[6];
		numcnt[9] = cnt['I' - 'A'];

		for (int i = 0; i < 10; i++)
			for (int j = 0; j < numcnt[i]; j++) printf("%d", i);
		puts("");

	}
}