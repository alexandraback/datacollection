#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f

using namespace std;

const double PI = acos(-1.0);
typedef pair<int, int> pii;
typedef long long ll;

int letters[30];
int cost[10][30];

int convert(char x) {return x - 'a'; }

string solve (int k) {
	bool flag = true;
	for (int i = 0; i < 30; i++) {
		if (letters[i]) flag = false;
		if (letters[i] < 0) return "";
	}
	string x; x.pb('0' + k);
	if (flag) return x;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 30; j++) {
			letters[j] -= cost[i][j];
		}
		string k = solve (i);
		if (k.size()) {
			k.pb(i + '0');
			return k;
		}
		for (int j = 0; j < 30; j++) {
			letters[j] += cost[i][j];
		}
	}
	return "";
}
int main (void) {
	int t; scanf("%d", &t);
	cost[0][convert('z')] = cost[0][convert('e')] = cost[0][convert('r')] = cost[0][convert('o')] = 1;
	cost[1][convert('o')] = cost[1][convert('n')] = cost[1][convert('e')] = 1;
	cost[2][convert('t')] = cost[2][convert('w')] = cost[2][convert('o')] = 1;
	cost[3][convert('t')] = cost[3][convert('h')] = cost[3][convert('r')] = 1; cost[3][convert('e')] = 2;
	cost[4][convert('f')] = cost[4][convert('o')] = cost[4][convert('u')] = cost[4][convert('r')] = 1;
	cost[5][convert('f')] = cost[5][convert('i')] = cost[5][convert('v')] = cost[5][convert('e')] = 1;
	cost[6][convert('s')] = cost[6][convert('i')] = cost[6][convert('x')] = 1;
	cost[7][convert('s')] = cost[7][convert('v')] = cost[7][convert('n')] = 1; cost[7][convert('e')] = 2;
	cost[8][convert('e')] = cost[8][convert('i')] = cost[8][convert('g')] = cost[8][convert('h')] = cost[8][convert('t')] = 1;
	cost[9][convert('n')] = cost[9][convert('i')] = cost[9][convert('n')] = cost[9][convert('e')] = 1;
	cost[9][convert('n')] = 2;
	for (int cases = 1; cases <= t; cases++) {
		memset (letters, 0, sizeof letters);
		string str;
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			letters[str[i]-'A']++;
		}

		string resp =  solve (0);
		printf("Case #%d: ", cases);
		for (int i = resp.size() - 1; i >= 1; i--) {
			printf("%c", resp[i]);
		}
		printf("\n");
	}

	return 0;
}
