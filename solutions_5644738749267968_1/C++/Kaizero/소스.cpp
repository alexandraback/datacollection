#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int n;
int a[1010], b[1010], p[1010];
bool v[1010];
int main()
{
	int TC, T, i, j, R, R2, pv;
	double t;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &TC);
	for (T = 1; T <= TC; T++){
		printf("Case #%d: ", T);
		scanf("%d", &n);
		for (i = 0; i < n; i++){
			scanf("%lf", &t);
			a[i] = t * 100000;
		}
		for (i = 0; i < n; i++){
			v[i] = false;
			scanf("%lf", &t);
			b[i] = t * 100000;
		}
		sort(a, a + n);
		sort(b, b + n);
		R2 = 0;
		for (i = n - 1; i >= 0; i--){
			for (j = 0; j < n; j++){
				if (!v[j] && a[i] < b[j])break;
			}
			if (j == n)R2++;
			else v[j] = true;
		}
		pv = 0;
		R = 0;
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				if (b[i] < a[j])break;
			}
			p[i] = j;
			if (pv < j)pv = j;
			if (pv == n) break;
			R++, pv++;
		}
		printf("%d %d\n", R, R2);
	}
}