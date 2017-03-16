#include <cstdio>
#include <algorithm>

using namespace std;
#define double long double
const int maxn = 210;
const double eps = 0.00000001;

int T, N, A[maxn];

inline double abs(double x) {
	if(x < 0) return -x;
	return x;
}
inline bool comp(double x, double y) {
	if(x < y - eps) return 1;
	double val = abs(x - y) ; 
	if(val < eps) return 1;
	return 0;
}
int main() {


	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);


	scanf("%d\n", &T);

	for(int t = 1; t <= T; ++t) {
		scanf("%d", &N);
		double X = 0;
		
		for(int i = 1; i <= N; ++i) {
			scanf("%d", &A[i]);
			X += A[i];
		}
		printf("Case #%d: ", t);
		
		for(int i = 1; i <= N; ++i) {
			
			double s = 1.0, mid, take, val;
			int iter = 0;
			for(double ls = 0, ld = 1; iter <= 100; ++iter) {
				mid = (ls + ld) / 2.0;
				take = A[i] + X * mid;
				
				bool ok = 0;
				
				double still = (1.0 - mid);
				for(int j = 1; j <= N; ++j)
					if(j != i && take >= A[j]) {
						int it2 = 0; double mid2, c = still;
						
						for(double ls2 = 0, ld2 = still;  it2 <= 100; ++it2) {
							mid2 = (ls2 + ld2) / 2.0;
							val = A[j] + mid2 * X;
							if(take < val) {
								ld2 = mid2; 
								c = mid2;
							} else ls2 = mid2;
						}
						
						if(abs(still-c) < eps) {
							ok = 1; break;
						} still -= c;

					}

				if(!ok) {
					//take >= val
					ls = mid;
				} else ld = mid, s = mid;
			}
			printf("%Lf ", s * 100);	
		}
		printf("\n");
	}
	return 0;
}	
					

			
