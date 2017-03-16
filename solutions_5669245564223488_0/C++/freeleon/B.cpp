#include <cstdio>
#include <cstring>
#define MOD 1000000007

typedef long long LL;

char str[200];
int fno[400];
int ru[400];
int chu[400];
int fca[400];
LL fact[200];


int main() {
	fact[0] = 1;
	for (int i = 1; i < 200; i++) {
		fact[i] = (fact[i-1] * i) % MOD;
	}
	int T;
    scanf("%d", &T);
	for (int ca = 1; ca <= T; ca++) {
		printf("Case #%d: ", ca);
		memset(fno, 0,sizeof(fno));
		memset(ru, 0, sizeof(ru));
		memset(chu, 0, sizeof(chu));
		memset(fca, 0, sizeof(fca));
        int n;
        scanf("%d", &n);
		char pre;
		bool ok = true;
        for (int i = 0; i < n; i++) {
			pre = ' ';
			memset(str, 0, sizeof(str));
            scanf("%s", str);
			int len = strlen(str);
			bool equal = true;
			for (int i = 0; i < len; i++) {
				if (str[i] != str[0]) {
					equal = false;
					break;
				}
			}
			if (equal) {
				fca[str[0]]++;
				continue;
			}

			for (int i = 1; i < len-1; i++) {
				if (fno[str[i]]) {
					if (pre != str[i]) {
						ok = false;
						break;
					}
				}
				fno[str[i]]++;
				pre = str[i];
			}
			if (!ok) continue;
            char u = str[0];
            char v = str[len-1];
			for (int i = 1; str[i] == str[0]; i++) {
				fno[u]--;
			}
			for (int i = len-2; i > 0 && str[i] == str[len-1]; i--) {
				fno[v]--;
			}
			if (fno[u]) {
				ok = false;
				break;
			}
			if (fno[v]) {
				ok = false;
				break;
			}
			chu[u]++;
			ru[v]++;

		}
		int ind = 0;
		int outd = 0;
		int mid = 0;
		for (int i = 'a'; i <= 'z'; i++) {
			if (chu[i] == 1 && ru[i] == 0) {
				ind++;
			} else if (ru[i] == 1 && chu[i] == 0) {
				outd++;
			} else if (ru[i] == 1 && chu[i] == 1) {
				mid++;
			} else if (!((ru[i] == 0 && chu[i] == 0) || (ru[i] == 1 && chu[i] == 1))) {
				ok = false;
				break;
			}
		}
		LL free;
		if (ind == 0 && outd == 0) {
			free = 0;
			if (mid != 0) {
				ok = false;
			}
		} else {
			if (ind != outd) {
				ok = false;
			}
			free = ind;
		}

		if (!ok) {
			puts("0");
			continue;
		}
		LL ans = 1;
		for (int i = 'a'; i <= 'z'; i++) {
			ans *= fact[fca[i]];
			ans %= MOD;
			if (chu[i] == 0 && ru[i] == 0 && fca[i]) free++;
		}
		ans *= fact[free];
		ans %= MOD;
		printf("%lld\n", ans);
	}
	return 0;
}

