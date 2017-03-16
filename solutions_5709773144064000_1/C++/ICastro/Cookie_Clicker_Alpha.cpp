#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
	int T;
	cin >> T;
	for (int k = 0; k < T; ++k){
		double C, F, X;
		cin >> C >> F >> X;
		double cps = 2;
		double tempo = 0;
		while(1) {
			if (X/cps <= C/cps + X/(cps + F)){
				tempo += X/cps;
				break;
			}
			tempo += C/cps;
			cps += F;
		}
		printf("Case #%d: %.7lf\n", k+1, tempo);
	}
	return 0;
}
