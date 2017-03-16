#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <queue>
#include <cmath>
#include <cstdio>

using namespace std;

int A,B;
double p[100099];

void solve()
{
	double correct = 1.0;
	double incorrect;
	for (int i=0; i<A; i++) correct *= p[i];
	incorrect = 1.0 - correct;

	//step1
	double ans1 = 0.0;
	ans1 = correct * (B-A+1) + incorrect * (B-A+1+B+1);

	//ans2;
	double ans2 = 9999999999;
	
	for (int i=0; i<A; i++) {
		double ansi = 1.0;
		double cor = 1.0;
		for (int j=0; j<i; j++) cor *= p[j];
		double incor = 1.0 - cor;
		ansi = (double)A-1-i+1 + B-1-i+1 + 1 + incor * (B+1);
		//cout << i << ": " << ansi << endl;
		ans2 = min(ansi,ans2);
	}
	
	//cout << total_c << endl;
	
	//ans3;
	double ans3 = 1 + B + 1;

	double ans = 99999999;
	ans = min(ans, ans1);
	ans = min(ans, ans2);
	ans = min(ans, ans3);
	//cout << ans << endl;
	printf("%.7f\n", ans);
	//cout << ans1 << endl;
	//cout << ans2 << endl;
	//cout << ans3 << endl;



}


int main()
{
	int case_num;
	cin >> case_num;

	for (int t=1; t<=case_num; t++) {
		// initialization, IO
		cin >> A;
		cin >> B;
		for (int i=0; i<A; i++) cin >> p[i];

		cout << "Case #" << t << ": ";
		solve();

	}
}
