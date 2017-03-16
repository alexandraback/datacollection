#include <cstdio>
#include <algorithm>

using namespace std;

double C, F, X;

double time_to_win( size_t n_farms, double lb ) {
	double ttw = 0.0;
	for( size_t k = 0; k < n_farms; ++k ) {
		ttw += C / (2.0 + k*F);
		if( ttw > lb ) return lb + 1;
	}
	ttw += X / (2.0 + n_farms*F);
	return ttw;
}

int main() {
	size_t T; scanf(" %lu", &T);
	for( size_t Case = 1; Case <= T; ++Case ) {
		scanf(" %lf %lf %lf", &C, &F, &X);
		double best_time = X / 2.0;
		for( size_t n_farms = 0; ; ++n_farms ) {
			best_time = min(best_time, time_to_win(n_farms, best_time) );
			if( time_to_win(n_farms, X / 2.0 + 2) > best_time ) break;
		}
		printf("Case #%lu: %.7lf\n", Case, best_time);
	}
	return 0;
}
