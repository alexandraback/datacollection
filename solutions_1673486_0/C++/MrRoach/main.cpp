#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

int t;
double p[100010];

int main(){
	cin >> t;
	for (int time = 0; time < t; ++time) {
		int A, B;
		cin>>A>>B;

		for (int i = 0; i < A; ++i){
			cin>>p[i];
		}
		double expect = B+2;
		double prodp = 1;
		for (int k = A; k > 0; --k){
			prodp *= p[A-k];
			double tmpe = B-A +1 + 2*(k-1) + (B+1)*(1-prodp);
			if (tmpe < expect) {
				expect = tmpe;
			}
		}
		printf("Case #%d: %10lf\n", time + 1, expect);
	}
	return 0;

}