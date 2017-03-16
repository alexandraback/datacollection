#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

int main(){
	int T; cin >> T;
	int A, B;
	double p[100000];
	double cor[100001];
	for(int test=1;test<=T;test++){
		scanf("%d %d", &A, &B);
		for(int i=0;i<A;i++) scanf("%lf", &p[i]);
		double res = B+2;
		double correct = 1.0;
		for(int i=0;i<A;i++){
			correct *= p[i];
			res = min(res, correct*(A-(i+1)+B-(i+1)+1) + (1-correct)*(A-(i+1)+B-(i+1)+1+B+1));
		}
		printf("Case #%d: %.8lf\n", test, res);
	}
}