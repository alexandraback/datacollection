#include <stdio.h>
#include <string.h>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <map>
#include <stack>

#define fi first
#define se second
#define mp make_pair
#define ll long long
#define pii pair <int, int>
#define vi vector <int>
#define REP(a,b) for(int a = 0; a < b; ++a)
#define FORU(a,b,c) for(int a = b; a <= c; ++a)
#define FORD(a,b,c) for(int a = b; a >= c; --a)
#define MOD 1000000000
#define MODLL 1000007LL
#define INF 2123123123
#define pb push_back
using namespace std;

int main() {
	int T, freqNum[13], freqChar[33];
	char st[2005];

	scanf("%d", &T);

	FORU(tc, 1, T) {
		scanf("%s", st);

		memset(freqNum, 0, sizeof(freqNum));
		memset(freqChar, 0, sizeof(freqChar));

		int len = strlen(st);

		REP(i, len) {
			++freqChar[st[i] - 'A'];
		}

		freqNum[0] = freqChar['Z' - 'A'];
		freqChar['Z' - 'A'] -= freqNum[0];
		freqChar['E' - 'A'] -= freqNum[0];
		freqChar['R' - 'A'] -= freqNum[0];
		freqChar['O' - 'A'] -= freqNum[0];

		freqNum[6] = freqChar['X' - 'A'];
		freqChar['S' - 'A'] -= freqNum[6];
		freqChar['I' - 'A'] -= freqNum[6];
		freqChar['X' - 'A'] -= freqNum[6];

		freqNum[2] = freqChar['W' - 'A'];
		freqChar['T' - 'A'] -= freqNum[2];
		freqChar['W' - 'A'] -= freqNum[2];
		freqChar['O' - 'A'] -= freqNum[2];
		
		freqNum[8] = freqChar['G' - 'A'];
		freqChar['E' - 'A'] -= freqNum[8];
		freqChar['I' - 'A'] -= freqNum[8];
		freqChar['G' - 'A'] -= freqNum[8];
		freqChar['H' - 'A'] -= freqNum[8];
		freqChar['T' - 'A'] -= freqNum[8];

		freqNum[3] = freqChar['H' - 'A'];
		freqChar['T' - 'A'] -= freqNum[3];
		freqChar['H' - 'A'] -= freqNum[3];
		freqChar['R' - 'A'] -= freqNum[3];
		freqChar['E' - 'A'] -= freqNum[3];
		freqChar['E' - 'A'] -= freqNum[3];

		freqNum[7] = freqChar['S' - 'A'];
		freqChar['S' - 'A'] -= freqNum[7];
		freqChar['E' - 'A'] -= freqNum[7];
		freqChar['V' - 'A'] -= freqNum[7];
		freqChar['E' - 'A'] -= freqNum[7];
		freqChar['N' - 'A'] -= freqNum[7];

		freqNum[5] = freqChar['V' - 'A'];
		freqChar['F' - 'A'] -= freqNum[5];
		freqChar['I' - 'A'] -= freqNum[5];
		freqChar['V' - 'A'] -= freqNum[5];
		freqChar['E' - 'A'] -= freqNum[5];

		freqNum[4] = freqChar['F' - 'A'];
		freqChar['F' - 'A'] -= freqNum[4];
		freqChar['O' - 'A'] -= freqNum[4];
		freqChar['U' - 'A'] -= freqNum[4];
		freqChar['R' - 'A'] -= freqNum[4];

		freqNum[1] = freqChar['O' - 'A'];
		freqChar['O' - 'A'] -= freqNum[1];
		freqChar['N' - 'A'] -= freqNum[1];
		freqChar['E' - 'A'] -= freqNum[1];

		freqNum[9] = freqChar['N' - 'A'] >> 1;

		printf("Case #%d: ", tc);

		REP(i, 10) {
			REP(j, freqNum[i]) {
				printf("%d", i);
			}
		}

		printf("\n");
	}

	return 0;
}
