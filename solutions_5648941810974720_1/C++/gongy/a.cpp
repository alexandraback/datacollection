#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<(n);i++)
#define MOD 1000000007
#define PB push_back
typedef long long ll;

string s[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int o[] = {0, 8, 6, 7, 5, 2, 4, 1, 3, 9};


int T, c[26];
vector<int> v;
char in[2200];

int main () {
	scanf("%d", &T);
	for (int _ = 1; _ <= T; _++) {
		v.clear();
		fo(i, 26) c[i] = 0;
		scanf(" %s", in);
		int N = (int) strlen(in);
		fo(i, N) c[in[i] - 'A']++;
		//fo(i, 26) printf("%d ", c[i]); puts("");
		for (int i = 0; i < 10; i++) {
			while (1) {
				int j = o[i], bad = 0;
				for (char x : s[j]) if (!c[x-'A']) bad = 1;
				if (!bad) {
					v.push_back(j);
					for (char x : s[j]) c[x-'A']--;
				} else break;
			}
		}
		fo(i, 26) assert(!c[i]);
		sort(v.begin(), v.end());
		printf("Case #%d: ", _); for (int i : v) printf("%d", i); puts("");
	}
	return 0;
}
