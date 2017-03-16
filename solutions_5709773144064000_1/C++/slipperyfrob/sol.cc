#include <cstdio>
#include <algorithm>

using namespace std;


int main() {
	size_t T; scanf(" %lu", &T);
	for( size_t Case = 1; Case <= T; ++Case ) {
		double C, F, X;
		scanf(" %lf %lf %lf", &C, &F, &X);
		double best_time = X / 2.0;
		double build_time = 0.0;
		for( size_t n_farms = 1; n_farms < X / C; ++n_farms ) {
			build_time += C / (2.0 + (n_farms-1)*F);
			best_time = min(best_time, build_time + X / (2.0 + n_farms*F) );
		}
		printf("Case #%lu: %.7lf\n", Case, best_time);
	}
	return 0;
}
