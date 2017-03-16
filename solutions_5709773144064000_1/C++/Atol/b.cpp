#include<cstring>
#include<string>
#include<iostream>
#include<set>
#include<string>
#include<sstream>
#include <iomanip>
using namespace std;

void solve() {
	double cost, inc, goal;
	cin >> cost >> inc >> goal;
	double ans = 0;
	double tot_inc = 2;
	while(true) {
		double aux1 = goal / tot_inc;
		double aux2 = cost / tot_inc + (goal / (tot_inc + inc));
		if (aux1 < aux2) {
			cout << fixed;
			cout << setprecision(7) << ans + aux1 << endl;
			break;
		} else {
			ans += (cost / tot_inc);
			tot_inc += inc;
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
}
