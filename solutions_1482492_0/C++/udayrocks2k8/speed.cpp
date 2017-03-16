#include<cstdio>
#include<cmath>
using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	for(int t = 1; t <= tc; t++) {
		printf("Case #%d: \n", t);
		double D;
		int N, A;
		scanf("%lf%d%d", &D, &N, &A);
		double time[N], position[N];
		for(int i = 0; i < N; i++) {
			scanf("%lf%lf", &time[i], &position[i]);
		}
		while(A--) {
			double acc;
			scanf("%lf", &acc);
			double tt;
			if(D <= position[0]) {
				tt = sqrt(2 * D / acc);
			} else if(position[0] <= D && position[1] >= D) {
				time[1] = (D - position[0]) * (time[1] - time[0]) / (position[1] - position[0]);
				position[1] = D;
				double np = 0.5 * acc * time[1] * time[1];
				if(np >= position[1]) {
					tt = time[1];
				} else {
					tt = sqrt(2 * D / acc);
				}
			}
			printf("%lf\n", tt);
		}
	}
	return 0;
}
