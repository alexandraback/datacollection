#include <cstdio>
#include <cstring>

using namespace std;

typedef long long int ll;

int L;
ll X;
char s[100002];

int f[255], T[5][5];
int pre[100002], suf[100002];

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

int check(int unit, ll fr) {
	if(unit == 1) return 1;
	if(unit == -1) return (fr % 2 == 0 ? 1 : -1);
	if(fr % 2 == 1) return 0;
	ll pairs = fr / 2;
	if(pairs % 2 == 1) return -1;
	return 0;
}

int main(int argc, char const *argv[])
{
	freopen("iLC.in", "r", stdin);
	freopen("oLC.txt", "w", stdout);
	init();
	int i, k, tc, T;
	scanf("%d", &T);
	for(tc = 1; tc <= T; tc++) {
		scanf("%d%lld", &L, &X);
		scanf("%s", s);
		int x = 10;
		if(X < 10)	x = (ll)X;
		for(i = L; i < L * x; i++) {
			s[i] = s[i - L];
		}
		s[i] = '\0';
		printf("Case #%d: ", tc);
		pre[0] = f[(int)s[0]];
		for(i = 1; i < L * x; i++) {
			pre[i] = trans(pre[i - 1], f[(int)s[i]]);
		}
		suf[L * x - 1] = f[(int)s[L * x - 1]];
		for(i = L * x - 2; i >= 0; i--) {
			suf[i] = trans(f[(int)s[i]], suf[i + 1]);
		}
		if(check(pre[L - 1], X) != -1) {
			puts("NO");
			continue;
		}
		i = 0; k = L * x - 1;
		while(i < L * x) {
			if(pre[i] == 2)
				break;
			i++;
		}
		while(k >= 0) {
			if(suf[k] == 4)
				break;
			k--;
		}
		if(i == L * x || k < 0) {
			puts("NO");
			continue;
		}
		ll k_ = L * X - (L * x - k);
		ll i_ = i;
		if((i_ + 1) < k_) puts("YES");
		else puts("NO");
	}
	return 0;
}