
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	long long E, R, N;
	long long v[20000];

	int cases;
	int casenum = 1;
	freopen("input", "r", stdin);
	//freopen("output", "w", stdout);

	scanf("%d", &cases);
	while(cases--){

		scanf("%lld%lld%lld", &E, &R, &N);
		if(R > E) R = E;

		for(long long i = 0; i < N; i++){
			scanf("%lld", &v[i]);
		}

		long long gain = 0;
		long long now = E;

		for(long long i = 0; i < N; i++){

			bool isNextPeak = false;
			long long fake = R;
			long long need = now;

			for(long long j = i + 1; j < N; j++){

				if( v[i] <= v[j] ){
					isNextPeak = true;
					need = fake + now - E;
					if( need > now ) need = now;
					if( need < 0 ) need = 0;
					break;
				}
				fake += R;
				if( fake > E ) break;
			}

			gain += (need) * v[i];
			now = now - need + R;
		}

		printf("Case #%d: %lld\n", casenum++, gain);
	}
	return 0;
}

