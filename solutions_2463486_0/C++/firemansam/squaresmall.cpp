#include <cstdio>
#include <algorithm>
using namespace std;
int n, a, b, psquare[] = {1, 4, 9, 121, 484, 676, 10000000};
int main(){
	scanf("%i", &n);
	for(int tc=1;tc<=n;tc++){
		scanf("%i%i", &a, &b);
		int c = upper_bound(psquare, psquare + 6, b) - lower_bound(psquare, psquare + 6, a);
		printf("Case #%i: %i\n", tc, c - (c>0 && b >= 676));
	}
}