#include <iostream>
#include <map>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long int uint64;
#define MAXN 110

int A, B;
int pow_ten[10];
map<pair<int, int>, bool > mapping;


int countDigit( int n ){
	int d = 0;
	while(n){
		d++;
		n = n / 10;
	}
	return d;
}

int main() {

	int cases;
	int caseindex = 0;

	pow_ten[0] = 1;
	for( int i = 1; i < 10; i++ ){
		pow_ten[i] = pow_ten[i - 1] * 10;
	}


	freopen("input", "r", stdin);
	freopen("output", "w", stdout);

	scanf("%d", &cases);
	//gets(s);
	while (cases--) {
		scanf("%d%d", &A, &B);
		mapping.clear();
		int ans = 0;
		for( int i = A; i <= B; i++ ){
			int digit = countDigit(i);
			if( digit == 1 ) continue;

			for( int j = 1; j < digit; j++ ){

				int m = ( i % pow_ten[j] ) * pow_ten[digit - j] + i / pow_ten[j];

				//printf("%d %d [%d]\n", i, m, pow_ten[j]);

				if( m >= A && m <= B && m != i ){
//					ans++;
					int min_val = min(i, m);
					int max_val = max(i, m);
					pair<int, int> p = make_pair(min_val, max_val);
					if( mapping[p] == false ){
						ans++;
						mapping[p] = true;
					}

				}
			}
			//printf("%d\n", digit);
		}

		caseindex++;
		printf("Case #%d: %d\n", caseindex, ans);
		fflush(stdout);
	}

	return 0;
}
