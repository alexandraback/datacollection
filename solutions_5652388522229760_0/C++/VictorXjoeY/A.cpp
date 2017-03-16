#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

set <int> s;
// ull counter;
// ull maxCounter;
// ull maxN;

void getDigits(ull x){
	while (x > 0){
		s.insert(x % 10);
		x /= 10;
		// counter++;
	}
}

int main(void){
	ull t, n, i, j;

	scanf("%llu", &t);

	for (i = 0; i < t; i++){
		scanf("%llu", &n);

		if (n == 0){
			printf("Case #%llu: INSOMNIA\n", i + 1);
			continue;
		}

		for (j = n; s.size() < 10; j += n){
			getDigits(j);
		}

		printf("Case #%llu: %llu\n", i + 1, j - n);

		s.clear();
	}

	return 0;
}