#include<iostream>
#include<cstdio>
#define loop(i, c) for(int i = 0; i < c; i++)

using namespace std;

int main() {
	int T;
	cin >> T;
	loop(t, T) {
		double F, C, X, f = 2, s = 0;
		cin >> C >> F >> X;
		while(1) {
			if(X*f < (X-C)*(f+F)) {
				s += C/f;
				f += F;
			}
			else {
				s += X/f;
				break;
			}
		}
		printf("Case #%d: %.7f\n", t+1, s);
	}
}