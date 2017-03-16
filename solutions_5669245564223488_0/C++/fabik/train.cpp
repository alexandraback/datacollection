#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

const ll mod = 1000000007;

int N;
char slova[105][105];
int delky[105];
int posloupnost[105];
bool v_posloupnosti[105];
int naposledy_viden[26];
int age;

ll dfs(int pouzito)
{
	if (pouzito == N) {
		age++;
		int aktualni_znak = -1;
		for (int i = 0; i < N; i++) {
			int slovo = posloupnost[i];
			for (int j = 0; slova[slovo][j]; j++) {
				int znak = slova[slovo][j] - 'a';
				if (znak != aktualni_znak) {
					if (naposledy_viden[znak] == age) {
						return 0;
					}
					naposledy_viden[znak] = age;
					aktualni_znak = znak;
				}
			}
		}
		// printf("# ");
		// for (int i = 0; i < N; i++) {
		// 	int slovo = posloupnost[i];
		// 	for (int j = 0; slova[slovo][j]; j++) {
		// 		printf("%c", slova[i][j]);
		// 	}
		// }
		// printf("\n");
		return 1;
	}
	ll vysledek = 0;
	for (int i = 0; i < N; i++) {
		if (!v_posloupnosti[i]) {
			v_posloupnosti[i] = true;
			posloupnost[pouzito] = i;
			vysledek = (vysledek + dfs(pouzito+1)) % mod;
			v_posloupnosti[i] = false;
		}
	}
	return vysledek;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%s", slova[i]);
			delky[i] = strlen(slova[i]);
		}
		ll vysledek = 0;
		for (int i = 0; i < N; i++) {
			v_posloupnosti[i] = true;
			posloupnost[0] = i;
			vysledek = (vysledek + dfs(1)) % mod;
			v_posloupnosti[i] = false;
		}
		printf("Case #%d: %lld\n", t, vysledek);
	}
	return 0;
}
