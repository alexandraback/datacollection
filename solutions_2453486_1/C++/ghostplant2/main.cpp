#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <vector>
//#include <map>
#include <string>

using namespace std;

char map[8][8];

bool same(char a, char b) {
	return a == 'T' || b == 'T' || a == b;
}

char check(char a, char b, char c, char d) {
	if (b == 'T')
		return check(b, a, c, d);
	if (c == 'T')
		return check(c, b, a, d);
	if (d == 'T')
		return check(d, b, c, a);
	if (a == 'T')
		return (b != '.' && b == c && c == d) ? b : 0;
	else
		return (a != '.' && a == b && b == c && c == d) ? a : 0;
}

int main() {
	freopen("/home/family/Desktop/A-large.in", "r", stdin);
	freopen("/home/family/Desktop/A-large.out", "w", stdout);
	int T, Cas = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%s%s%s%s", map[0], map[1], map[2], map[3]);
		char s = 0;
		bool blank = false;
		for (int i = 0; !s && i < 4; i++) {
			s |= check(map[i][0], map[i][1], map[i][2], map[i][3]);
			s |= check(map[0][i], map[1][i], map[2][i], map[3][i]);
			blank |= map[i][0] == '.' || map[i][1] == '.' || map[i][2] == '.'
					|| map[i][3] == '.';
		}
		if (!s) {
			s |= check(map[0][0], map[1][1], map[2][2], map[3][3]);
			s |= check(map[0][3], map[1][2], map[2][1], map[3][0]);
		}
		printf("Case #%d: ", ++Cas);
		if (s)
			printf("%c won\n", s);
		else if (blank)
			printf("Game has not completed\n");
		else
			printf("Draw\n");
	}
	return 0;
}
