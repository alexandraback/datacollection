#include <iostream>
#include <cstdio>

using namespace std;

double solve(double C, double F, double X){
	double T = 0.5*X;
	double cur = 0;
	double G = 2.0;
	while(cur < T){
		cur += C/G;
		G += F;
		T = min(cur+X/G, T);
	}
	return T;
}

int main(){
	int T; cin >> T;
	double C, F, X;
	for(int test=1;test<=T;test++){
		cin >> C >> F >> X;
		printf("Case #%d: %.8lf\n", test, solve(C, F, X));
	}
}
