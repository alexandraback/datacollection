#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
	int T;
	cin >> T;
	for(int t=0; t<T; t++){
		printf("Case #%d: ", t+1);
		double C, F, X;
		cin >> C >> F >> X;
		double ans = X/2;
		double grow = 2;
		double tF = 0;
		while (true){
			tF += C/grow;
			if (tF > ans)
				break;
			grow += F;
			double t2 = X/grow;
			if (tF+t2 < ans)
				ans = tF+t2;
		}
		printf("%.7lf\n", ans);
	}
}

