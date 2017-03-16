#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <map>
#include <bitset>
#include <utility>
#include <algorithm>

#define REP(a, b) for (int a = 0; a < b; ++a)
#define FORU(a, b, c) for (int a = b; a <= c; ++a)
#define FORD(a, b, c) for (int a = b; a >= c --a)
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using namespace std;

int tot = 0, K, L, S, T;
vector <string> allWord;
char kata[11], keyboard[11], wanted[11];

void generate(int pos) {
	if (pos == S) {
		kata[pos] = '\0';
		string temp = kata;
		allWord.pb(temp);
	}
	else {
		REP(i, K) {
			kata[pos] = keyboard[i];
			generate(pos + 1);
		}
	}
}

int findMax() {
	int maks = 0;
	int sz = allWord.size();

	REP(i, sz) {
		string tampung = allWord[i];
		// printf("%s\n", tampung.c_str());
		int ret = 0;

		for (int j = 0; j <= S - L; ++j) {
			bool oke = true;
			REP(k, L) {
				if (tampung[j + k] != wanted[k]) {
					oke = false;
					break;
				}
			}

			if (oke) {
				++ret;
			}
		}

		maks = max(maks, ret);
		tot += ret;
	}

	return maks;
}

int main() {
	scanf("%d", &T);

	FORU(tc, 1, T) {
		scanf("%d %d %d", &K, &L, &S);

		scanf("%s", keyboard);
		scanf("%s", wanted);

		allWord.clear();
		tot = 0;

		generate(0);
		int maks = findMax();

		int ans = maks * allWord.size() - tot;

		printf("Case #%d: %lf\n", tc, ans / (double) allWord.size());
	}

	return 0;
}
