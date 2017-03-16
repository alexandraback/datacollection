#include <cstdio>
#include <cstring>

using namespace std;

int L, X;
char s[10002];

int f[255], T[5][5];
int pre[10002], suf[10002];

int trans(int a, int b) {
	int a_ = (a < 0 ? -a : a);
	int b_ = (b < 0 ? -b : b);
	return (T[a_][b_] * (a < 0 ? -1 : 1) * (b < 0 ? -1 : 1));
}

void init() {
	f[49] = 1; f[105] = 2; f[106] = 3; f[107] = 4;
	T[1][1] = 1; T[1][2] = 2; T[1][3] = 3; T[1][4] = 4;
	T[2][1] = 2; T[2][2] = -1; T[2][3] = 4; T[2][4] = -3;
	T[3][1] = 3; T[3][2] = -4; T[3][3] = -1; T[3][4] = 2;
	T[4][1] = 4; T[4][2] = 3; T[4][3] = -2; T[4][4] = -1;
}

int main(int argc, char const *argv[])
{
	freopen("input.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	init();
	int i, k, tc, T;
	scanf("%d", &T);
	for(tc = 1; tc <= T; tc++) {
		scanf("%d%d", &L, &X);
		scanf("%s", s);
		for(i = L; i < L * X; i++) {
			s[i] = s[i - L];
		}
		s[i] = '\0';
		printf("Case #%d: ", tc);
		pre[0] = f[(int)s[0]];
		for(i = 1; i < L * X; i++) {
			pre[i] = trans(pre[i - 1], f[(int)s[i]]);
		}
		suf[L * X - 1] = f[(int)s[L * X - 1]];
		for(i = L * X - 2; i >= 0; i--) {
			suf[i] = trans(f[(int)s[i]], suf[i + 1]);
		}
		if(pre[L * X - 1] != -1) {
			puts("NO");
			continue;
		}
		i = 0; k = L * X - 1;
		while(i < L * X) {
			if(pre[i] == 2)
				break;
			i++;
		}
		while(k > i) {
			if(suf[k] == 4)
				break;
			k--;
		}
		if(i + 1 < k && pre[i] == 2 && suf[k] == 4) puts("YES");
		else puts("NO");
	}
	return 0;
}