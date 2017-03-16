#include <cstdio>
#include <cstdlib>

using namespace std;

int T, L, X;
char S[10005];
int right[10005];

const int mul_table[8][8] = 
{
{0, 1, 2, 3, 4, 5, 6, 7},
{1, 4, 3, 6, 5, 0, 7, 2},
{2, 7, 4, 1, 6, 3, 0, 5},
{3, 2, 5, 4, 7, 6, 1, 0},
{4, 5, 6, 7, 0, 1, 2, 3},
{5, 0, 7, 2, 1, 4, 3, 6},
{6, 3, 0, 5, 2, 7, 4, 1},
{7, 6, 1, 0, 3, 2, 5, 4}
};

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small0.out", "w", stdout);
	scanf("%d", &T);
	for (int t = 1; t <= T; ++ t) {
		scanf("%d%d%s", &L, &X, S);
		int n = L * X;
		for (int i = L; i < n; ++ i) S[i] = S[i - L];
		for (int i = 0; i < n; ++ i) S[i] -= 'i' - 1;
		right[n - 1] = S[n - 1];
		for (int i = n - 2; i; -- i)
			right[i] = mul_table[S[i]][right[i + 1]];
		int can = 0, left = 0, mid;
		for (int i = 0; i < n && !can; ++ i) {
			left = mul_table[left][S[i]];
			if (left == 1) {
				mid = 0;
				for (int j = i + 1; j + 1 < n && !can; ++ j) {
					mid = mul_table[mid][S[j]];
					if (mid == 2 && right[j + 1] == 3)
						can = 1;
				}
			}
		}
		printf("Case #%d: %s\n", t, (can? "YES" : "NO"));
	}
	return 0;
}
