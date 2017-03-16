#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int T, N, A;
double D, t[2000], x[2000], _a[250];

int main()
{
	scanf("%d", &T);
	for(int tt=0;tt<T;){
		scanf("%lf%d%d", &D, &N, &A);
		for(int i=0;i<N;i++) scanf("%lf%lf", t+i, x+i);
		for(int i=0;i<A;i++) scanf("%lf", _a+i);

		printf("Case #%d:\n", ++tt);

		double rtime = 0;
		if(N==2){
			if(x[0]>=D) rtime = 0;
			else{
				rtime = (t[1] - t[0]) * (D - x[0]) / (x[1] - x[0]);
			}
		}
		for(int i=0;i<A;i++){
			printf("%.7f\n", max(rtime, sqrt(2 * D / _a[i])));
		}
		/*
		for(int j=0;j<N-1;j++){
			if(x[j] < D && x[j+1] >= D){
				N = j+2;
				t[j+1] = t[j] + (t[j+1] - t[j]) * (D - x[j]) / (x[j+1] - x[j]);
				x[j+1] = D;
				break;
			}
		}

		for(int i=0;i<A;i++) scanf("%lf", _a+i);

		printf("Case #%d:\n", ++tt);
		printf("%d %f\n", N, t[N-1]);
		for(int i=0;i<A;i++){
			double a = _a[i];
			double pos = 0, v = 0, time = 0;
			for(int j=1;j<N;j++){
				double treq = t[j] - t[j-1];
				if(pos + 0.5 * treq * (2*v + a * treq) >= x[j]){
					//overtaking
					v = (x[j] - x[j-1]) / (t[j] - t[j-1]);
					pos = x[j];
				}else{
					pos += 0.5 * treq * (2*v + a * treq);
					v += a * treq;
				}
				time = t[j];
			}
			if(pos < D){
				double rm = D - pos;
				time += (sqrt(v * v + 2 * a * rm) - v) / a;
			}

			printf("%.7f\n", time);
		}
		*/
	}
	return 0;
}
