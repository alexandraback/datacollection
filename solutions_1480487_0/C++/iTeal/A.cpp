#include <iostream>
#include <iomanip>

using namespace std;

int main (int argc, char const *argv[])
{
	int t;
	cin >> t;
	for(int ii = 1; ii <= t; ii++) {
		int n;
		double a[200];
		cin >> n;
		double sum = 0;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		double avg = (sum*2)/n;
		double sum2 = sum;
		int tot = n;
		for(int i = 0; i < n; i++) {
			if (a[i] >= avg) {
				sum2 -= a[i];
				tot--;
			}
		}
		double target = (sum+sum2)/(double)tot;
		cout << "Case #" << ii << ":";
		cout << fixed << setprecision(6);
		for(int i = 0; i < n; i++) {
			double ans = ((target-a[i])/sum)*100;
			if (ans < 0) ans = 0;
			cout << " " << ans;
		}
		cout << endl;
	}
	return 0;
}