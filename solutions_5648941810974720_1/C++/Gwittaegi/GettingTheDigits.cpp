#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int tc = 0;++tc <= t;tc) {
		string s;
		int sCnt[26] = { 0, };
		int resCnt[10] = { 0, };
		cin >> s;
		int len = s.length();
		for (int i = 0;i < len;++i)
			++sCnt[s[i] - 'A'];
		resCnt[0] = sCnt['Z' - 'A'];
		sCnt['Z' - 'A'] -= resCnt[0];
		sCnt['E' - 'A'] -= resCnt[0];
		sCnt['R' - 'A'] -= resCnt[0];
		sCnt['O' - 'A'] -= resCnt[0];

		resCnt[2] = sCnt['W' - 'A'];
		sCnt['T' - 'A'] -= resCnt[2];
		sCnt['W' - 'A'] -= resCnt[2];
		sCnt['O' - 'A'] -= resCnt[2];

		resCnt[4] = sCnt['U' - 'A'];
		sCnt['F' - 'A'] -= resCnt[4];
		sCnt['O' - 'A'] -= resCnt[4];
		sCnt['U' - 'A'] -= resCnt[4];
		sCnt['R' - 'A'] -= resCnt[4];

		resCnt[6] = sCnt['X' - 'A'];
		sCnt['S' - 'A'] -= resCnt[6];
		sCnt['I' - 'A'] -= resCnt[6];
		sCnt['X' - 'A'] -= resCnt[6];

		resCnt[8] = sCnt['G' - 'A'];
		sCnt['E' - 'A'] -= resCnt[8];
		sCnt['I' - 'A'] -= resCnt[8];
		sCnt['G' - 'A'] -= resCnt[8];
		sCnt['H' - 'A'] -= resCnt[8];
		sCnt['T' - 'A'] -= resCnt[8];

		resCnt[1] = sCnt['O' - 'A'];
		sCnt['O' - 'A'] -= resCnt[1];
		sCnt['N' - 'A'] -= resCnt[1];
		sCnt['E' - 'A'] -= resCnt[1];

		resCnt[3] = sCnt['T' - 'A'];
		sCnt['T' - 'A'] -= resCnt[3];
		sCnt['H' - 'A'] -= resCnt[3];
		sCnt['R' - 'A'] -= resCnt[3];
		sCnt['E' - 'A'] -= resCnt[3];
		sCnt['E' - 'A'] -= resCnt[3];

		resCnt[5] = sCnt['F' - 'A'];
		sCnt['F' - 'A'] -= resCnt[5];
		sCnt['I' - 'A'] -= resCnt[5];
		sCnt['V' - 'A'] -= resCnt[5];
		sCnt['E' - 'A'] -= resCnt[5];

		resCnt[7] = sCnt['S' - 'A'];
		sCnt['S' - 'A'] -= resCnt[7];
		sCnt['E' - 'A'] -= resCnt[7];
		sCnt['V' - 'A'] -= resCnt[7];
		sCnt['E' - 'A'] -= resCnt[7];
		sCnt['N' - 'A'] -= resCnt[7];

		resCnt[9] = sCnt['E' - 'A'];

		printf("Case #%d: ", tc);
		for (int i = 0;i <= 9;++i)
			for (int j = 0;j < resCnt[i];++j)
				printf("%d", i);
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);

	return 0;
}