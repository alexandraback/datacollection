#include <iostream>
#include <iomanip>

using namespace std;

int main (int argc, char const *argv[])
{
	int t;
	cin >> t;
	for(int ii = 1; ii <= t; ii++) {
		int a,b;
		double correct[100000];
		double aggr[100000];
		cin >> a >> b;
		for(int i = 0; i < a; i++) {
			cin >> correct[i];
			if (i == 0) aggr[i] = correct[i];
			else aggr[i] = aggr[i-1] * correct[i];
		}
		double ans = b+2;
		for(int i = 0; i < a; i++) {
			double p = aggr[a-i-1];
			double np = 1-p;
			double temp = (double)(b-a+1+2*i) * p + (double)(b-a+1+2*i+b+1) * np;
			// cout << i << " " << temp << endl;
			if (temp < ans) ans =temp;
		}
		cout << setprecision(6) << fixed;
		cout << "Case #" << ii << ": " << ans << endl;
	}
	return 0;
}