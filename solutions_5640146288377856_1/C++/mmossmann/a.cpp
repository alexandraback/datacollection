#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define for2(x, n) for(unsigned x = 0; x < n; ++x)

using namespace std;

int main(){
	unsigned T, R, C, W, res;

	scanf("%u", &T);

	for2(x, T){
		res = 0;
		scanf("%d %d %d", &R, &C, &W);
		if(R > C){
			swap(R, C);
		}

		res = (C / W) * R + W - (C % W == 0 ? 1 : 0);

		printf("Case #%u: %u\n", x + 1, res);

	}


	return 0;
}
