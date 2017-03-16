#include <cstdio>
#include <cstring>

using namespace std;

int T, K, L, S;
char keys[110];
int count[300];
char word[110];
int lps[110];

long double ans;

int main() {
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t) {
		scanf("%d%d%d", &K, &L, &S);
		scanf("%s", keys);
		memset(count, 0, sizeof(count));
		memset(lps, 0, sizeof(lps));
		for(int i = 0; keys[i]; ++i)
			count[keys[i]]++;
		scanf("%s", word);
		ans = S - L + 1;
		
		int len = 0;
		lps[0] = 0;
		int i = 1;
		while(i < L) {
			if(word[i] == word[len]) {
				len++;
				lps[i] = len;
				i++;
			}
			else {
				if(len != 0)
					len = lps[len - 1];
				else {
					lps[i] = 0;
					i++;
				}
			}
		}
		
		int v = L - lps[L - 1];
		for(int i = 0; word[i]; ++i)
			ans *= (long double)(count[word[i]]) / K;
		ans = (S - L + v)/v - ans;
		for(int i = 0; word[i]; ++i) {
			if(count[word[i]] == 0) {
				ans = 0;
				break;
			}
		}
		printf("Case #%d: %.7Lf\n", t, ans);
	}
}
