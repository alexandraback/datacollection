
#include <iostream>

using namespace std;

double p[100000];

// 1. is (B-A+1)*p + (B-A+1+B+1) * (1-p)
// 2. is (k+k+B-A+1)*p + (k+k+B-A+1+B+1)*(1-p)
// 3. is always 1+B+1

double ok(double p[], int m, int n){
	double r = 1;
	for(int i=m; i<n; ++i){
		r *= p[i];
	}
	return r;
}

double solve(double p[], int A, int B){
	double one = (B-A+1)*ok(p,0,A) + (B-A+1+B+1) * (1-ok(p,0,A));
	double three = 1+B+1;
	double two=2000000;
	for(int k=0; k<A; ++k){
		double kth = (k+k+B-A+1)*ok(p,0,A-k) + (k+k+B-A+1+B+1)*(1-ok(p,0,A-k));
		two = min(two, kth);
	}
	return min(min(one, two), three);
}

int main(){
	ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	for(int t=1; t<=T; ++t){
		int A, B;
		cin >> A >> B;
		for(int i=0; i<A; ++i){
			cin >> p[i];
		}
		cout.precision(6);
		cout.setf(ios::fixed,ios::floatfield);
		cout << "Case #" << t << ": " << solve(p,A,B) << endl;
	}
	return 0;
}

