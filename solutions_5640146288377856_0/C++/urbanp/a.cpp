#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
#include <queue>
#include <limits>
#include <map>
#include <math.h> 
#include <iostream>
#include <set>

#define CAP 1
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void solve();

int main(){
	int N;
	scanf("%d", &N);

	for(int i=0; i<N; i++){
		printf("Case #%d: ", i+1);
		solve();
	}
	return 0;
}

void solve(){
	int R, C, W, offsetr=0, offsetl, base=0;
	scanf("%d %d %d", &R, &C, &W);

	base = C/W;
	offsetr+= C%W; //number of squares on the right
	offsetl = max(0, W-1); //squares on the left

	int sum = max(0, offsetl+(offsetr?1:0));
	printf("%d\n", base*R+sum);
}
