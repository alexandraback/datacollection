#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<set>
#include<cmath>
using namespace std;

const int MAX_N = 2005;
double t[MAX_N];
double x[MAX_N];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	cin >> T;
	for(int cas = 1; cas <= T; ++cas){
		double D;
		int N, A;
		scanf("%lf %d %d", &D, &N, &A);
		for(int i = 0; i < N; ++i){
			scanf("%lf %lf", &t[i], &x[i]);
		}
		printf("Case #%d:\n", cas);
		for(int i = 0; i < A; ++i){
			double g;
			scanf("%lf", &g);
			double t1 = sqrt(D * 2.0 / g);
			if(x[0] >= D || N == 1){
				printf("%.9f\n", t1);
			}
			else{
				if(N == 2){
					double t2 = (D - x[0]) * (t[1] - t[0]) / (x[1] - x[0]) + t[0];
					printf("%.9f\n", max(t1, t2));
				}
				else{
					printf("===========unsupported\n");///
				}
			}
		}
	}

	return 0;
}
