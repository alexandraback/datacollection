#include <cstdio>
#define MAX 256

int main () {
	int v[MAX], n, m;
	scanf("%d", &n);
	for (int i = 0; i != n; i++) {
		scanf("%d", &m);
		int sum = 0;
		for (int j = 0; j != m; j++) {
			scanf("%d", &v[j]);
			sum += v[j];
		}
		double target = (sum<<1)/m, t2;
		int cnt = 0, s = 0;
		for (int j = 0; j != m; j++) {
			if (v[j] < target) {
				s += v[j];
				cnt++;
			}
		}
		double told = target;
		if (cnt) target = (sum+(double)s)/cnt;

//		printf("Case #%d: %lf %lf %d %d ", i+1, told, target, s, cnt);

		printf("Case #%d: ", i+1);
		for(int j = 0; j != m; j++)  {
			printf("%.6lf%c", v[j] >= told ? 0 : (target-v[j])*100/sum, j == m-1 ? '\n' : ' ');
		}
		
	}
	return 0;

}
