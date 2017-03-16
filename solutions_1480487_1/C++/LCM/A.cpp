#include<cstdio>

int t, n, s[205], sum;
bool u[205];

int main() {
	freopen("Al.in", "r", stdin);
	freopen("Al.out", "w", stdout);
	scanf("%d", &t);
	for (int i = 1 ; i <= t ; i++) {
		scanf("%d", &n);
		sum = 0;
		for (int j = 0 ; j < n ; j++) {
			scanf("%d", &s[j]);
			sum += s[j];
		}
		for (int j = 0 ; j < 205 ; j++) u[j] = false;
		double en = n, esum = sum;
		for (int j = 0 ; j < n ; j++) {
			for (int k = 0 ; k < n ; k++) {
				if (s[k] > (esum + sum) / en && u[k] == false) {
					en--;
					esum -= s[k];
					u[k] = true;
				}
			}
		}
		printf("Case #%d:", i);
		for (int j = 0 ; j < n ; j++) {
			printf(" %Lf", u[j] ? 0 : ((esum + sum) / en - s[j]) / sum * 100);
		}
		printf("\n");
	}
	scanf("\n");
	return 0;
}
