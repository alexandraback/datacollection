#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

long long o[1001000];

int main(){
	int tc, tcn;
	scanf("%d", &tcn);
	for(tc=0; tc<tcn; ++tc){
		printf("Case #%d: ", tc+1);
		long long a, n;
		scanf("%lld %lld", &a, &n);
		for(int i=0; i<n; ++i)
			scanf("%lld", &o[i]);
		sort(o, o+n);
		long long best = n;
		long long current = 0;
		for(int i=0; i<n; ++i){
			if(a <= 1 && o[i] >= 1)
				break;
			for(; a <= o[i]; ++current)
				a += a-1;
			a += o[i];
			best = min(best, current + n-i-1);
		}
		printf("%lld\n", best);
	}
}
