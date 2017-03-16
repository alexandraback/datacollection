#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int solveSmall(int A, int B, int K){
	int res = 0;
	for(int i=0;i<A;i++){
		for(int j=0;j<B;j++){
			if((i&j) < K) res++;
		}
	}
	return res;
}

int main(){
	int T; cin >> T;
	for(int test=1;test<=T;test++){
		int A, B, K; cin >> A >> B >> K;
		printf("Case #%d: %d\n", test, solveSmall(A, B, K));
	}
}
