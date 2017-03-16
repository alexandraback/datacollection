#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
#include <queue>
#include <limits>
#include <map>

using namespace std;

void solve();

int main(){
	int cases;
	scanf("%d", &cases);

	for(int i=1; i<=cases; i++){
		printf("Case #%d: ", i);
		solve();
	}

	return 0;
}

void solve(){
	int A, B, K, count=0;
	scanf("%d %d %d", &A, &B, &K);

	for(int i=0; i<A; i++){
		for(int j=0; j<B; j++){
			if( (i&j) < K){
				count++;
			}
		}
	}
	printf("%d\n", count);
}