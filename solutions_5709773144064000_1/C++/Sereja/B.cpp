#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	freopen("b2.in", "r", stdin);
	freopen("b2.out", "w", stdout);
	int T;
	cin >> T;
	cout << fixed << setprecision(15);
	for (int tst = 1; tst <= T; tst++){
		printf("Case #%d: ", tst);
		double c, f, x, d, time;
		cin >> c >> f >> x;
		time = 0;
		d = 2;
		double ans = 1000000000;
		for (int i = 0; i <= 200000; i++){
			ans = min(ans, time + x / d);
			time += c / d;
			d += f;
		}
		cout << ans << endl;
	}
	return 0;
}
