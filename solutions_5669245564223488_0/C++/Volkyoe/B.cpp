#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"set"
#include"map"
#include"queue"
#include"algorithm"
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef long long 		ll;
typedef pair<int, int>	ii;
typedef vector<ii>		vii;
typedef vector<int>		vi;
int T, t, n, i, j, k, per[30], p, q, ans;
char s[100000], arr[105][50];
bool used[30], yeah;
int main() {
	freopen("1.in", "r", stdin);
	freopen("1_1.txt", "w", stdout);
	scanf("%d", &T);
	for (i = 0; i < 30; i++) per[i] = i;
	while (T > t++) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%s", s);
			arr[i][0] = s[0];
			for (k = j = 1; s[j]; j++) {
				while (s[j] == s[j - 1]) j++;
				arr[i][k++] = s[j];
			}
			arr[i][k] = 0;
		}
		ans = 0;
		do {
			for (i = 0; i < 30; i++) used[i] = 0;
			yeah = 0;
			for (i = 0; i < n && !yeah; i++) {
				p = per[i];
				q = arr[p][0] - 'a';
				if (!used[q]) used[q] = 1;
				else if (q != arr[per[i-1]][j - 1] - 'a') yeah = 1;
				for (j = 1; arr[p][j]; j++) {
					q = arr[p][j] - 'a';
					if (!used[q]) used[q] = 1;
					else yeah = 1;
				}
			}
			if (!yeah) ans++;
		} while (next_permutation(per, per + n));
		printf("Case #%d: %d\n", t, ans);
	}
}
