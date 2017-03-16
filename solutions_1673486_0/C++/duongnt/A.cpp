#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const double eps = 1e-7;
double p[1000000];
int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-out.out", "w", stdout);
	int T, A, B;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		scanf("%d %d", &A, &B);
		for(int i = 0; i < A; i++){
			cin >> p[i];
		}

		for(int i = 1; i < A; i++){
			p[i] *= p[i-1];
		}

		//give up case
		double ans = (double)B+2.0;
		//case1
		double tmp = (B-A+1)*p[A-1]+(2.0*B-A+2)*(1-p[A-1]);
		if(tmp < ans+eps) ans = tmp;


		//delete all A characters
		tmp = (double)A+B+1;
		if(tmp < ans+eps) ans = tmp;
		for(int i = 1; i <= A-1; i++){
			tmp = 2.0*i+2*B-A+2-(B+1)*p[A-i-1];
			if(tmp < ans+eps) ans = tmp;
		}

		printf("Case #%d: %.6f", t, ans);
		if(t < T) cout << endl;


	}

	return 0;

}
