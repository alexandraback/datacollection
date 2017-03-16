#include <cstdio>
#include <cstring>
#define MOD 1000000007
#define DE 

char str[200];
int cant[400];
int ru[400];
int chu[400];
int num[400];
long long jie[200];

void getjie() {
	jie[0] = 1;
	for (int i = 1; i < 200; i++) {
		jie[i] = (jie[i-1] * i) % MOD;
	}
}

int main() {
	getjie();
    int t;
    scanf("%d", &t);
	int cas = 1;
    while (t--) {
		printf("Case #%d: ", cas++);
        int n;
        scanf("%d", &n);
		memset(cant,false,sizeof(cant));
		memset(ru, 0, sizeof(ru));
		memset(chu, 0, sizeof(chu));
		memset(num, 0, sizeof(num));

		char pre;
		bool ok = true;
        for (int i = 0; i < n; i++) {
			pre = ' ';
            scanf("%s", str);
			int len = strlen(str);
			bool allsame = true;
			for (int i = 0; i < len; i++) {
				if (str[i] != str[0]) {
					allsame = false;
					break;
				}
			}
			if (allsame) {
				num[str[0]]++;
				continue;
			}

			for (int i = 1; i < len-1; i++) {
				if (cant[str[i]]) {
					if (pre == str[i]);
					else {
						ok = false;
						DE("1");
						break;
					}
				}
				cant[str[i]]++;
				pre = str[i];
			}
			if (!ok) break;
            char u = str[0];
            char v = str[len-1];
			for (int i = 1; str[i] == str[0]; i++) {
				cant[u]--;
			}
			for (int i = len-2; i > 0 && str[i] == str[len-1]; i--) {
				cant[v]--;
			}
			//if (str[0] == str[1]) cant[u]--;
			//if (str[len-2] == str[len-1]) cant[v]--;
			if (cant[u]) {
				ok = false;
				DE("2");
				break;
			}
			if (cant[v]) {
				ok = false;
				DE("3");
				break;
			}
			chu[u]++;
			ru[v]++;

		}
		int rudian = 0;
		int chudian = 0;
		int zhongjiandian = 0;
		for (int i = 'a'; i <= 'z'; i++) {
			if (chu[i] == 1 && ru[i] == 0) {
				rudian++;
			} else if (ru[i] == 1 && chu[i] == 0) {
				chudian++;
			} else if (ru[i] == 1 && chu[i] == 1) {
				zhongjiandian++;
			} else if (!((ru[i] == 0 && chu[i] == 0) || (ru[i] == 1 && chu[i] == 1))) {
//				printf("%c chu=%d, ru=%d\n", i, chu[i], ru[i]);
				ok = false;
				DE("4");
				break;
			}
		}
		long long free;
		if (rudian == 0 && chudian == 0) {
			free = 0;
			if (zhongjiandian != 0) {
				ok = false;
				DE("5");
			}
		} else {
			if (rudian != chudian) {
				ok = false;
				DE("6");
			}
			free = rudian;
		}

		if (!ok) {
			puts("0");
			continue;
		}

		long long ans = 1;
		for (int i = 'a'; i <= 'z'; i++) {
			//if (num[i]) printf("%c num = %d\n", i, num[i]);
			ans *= jie[num[i]];
			ans %= MOD;
			if (chu[i] == 0 && ru[i] == 0 && num[i]) free++;
		}
		//printf("free = %d\n", free);
		ans *= jie[free];
		ans %= MOD;
		printf("%lld\n", ans);
	}
	return 0;
}

