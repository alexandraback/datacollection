#include <cstdio>
#include <cstring>

typedef long long ll;
const int MAXL = 1100000;
int tab[MAXL];
char word[MAXL];

int main() {
	int T;
	scanf("%d", &T);
	for (int t=0; t<T; ++t) {
		memset(tab, 0, sizeof(tab));
		int n;
		scanf("%s %d", word, &n);
		int len = strlen(word);
		for (int i=0; i<len; ++i) {
			tab[i+1] = tab[i];
			char cc = word[i];
			if ((cc=='a')||(cc=='e')||(cc=='i')
					||(cc=='o')||(cc=='u'))
			{
				++tab[i+1];
			}
		}

		ll ret = 0;
		int last = n-1;
		for (int i=0; i<len; ++i) {
			while (last - n + 1 < i) ++last;
			while ((last < len) && (tab[last+1] - tab[last-n+1] != 0)) ++last;
			if (last >= len) break;
			ret += len - last;
		}

		printf("Case #%d: %lld\n", t+1, ret);
	}
	return 0;
}
