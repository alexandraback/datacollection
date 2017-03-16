#include <cstdio>
using namespace std;

const int maxk = 7;
const int maxl = 7;
const int maxs = 7;

char keys[maxk +1];
char word[maxl +1];
char nice[maxs +1];

int k, l, s;

int search(int x, int *maxv)
{
	int cnt = 0;
	if (x) {
		for (int i = 0; i < k; i++) {
			nice[x -1] = keys[i];
			cnt += search(x -1, maxv);
		}
	}
	else {
		for (int i = 0; i <= s - l; i++) {
			int j = 0;
			for (; j < l; j++) {
				if (word[j] != nice[i + j])
					break;
			}
			if (l == j)
				cnt++;
		}
		if (cnt > *maxv)
			*maxv = cnt;
	}
	return cnt;
}

void solve()
{
	scanf("%i%i%i%s%s", &k, &l, &s, keys, word);
	int maxv = 0;
	int vars = search(s, &maxv);
	int den = 1;
	for (int i = 0; i < s; i++) {
		den *= k;
	}
	printf("%.7g", (maxv * den - vars) / (double) den);
}

int main()
{
	int t;
	scanf("%i", &t);
	for (int i = 0; i < t; i++) {
		printf("Case #%i: ", i +1);
		solve();
		printf("\n");
	}
	return 0;
}

