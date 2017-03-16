#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
#define fo(i,n) for(int i=0,_n=(n); i<_n; ++i)

double C, F, X;
int T;

int main() {
	cin >> T;
	cout << setprecision(20);
	fo(t,T) {
		cout << "Case #" << t + 1 << ": ";
		cin >> C >> F >> X;
		if(C >= X) {
			cout << X * 0.5 << '\n';
		} else {
			double rate = 2.0, elapsed = 0.0;
			while(true) {
				elapsed += C / rate;
				double left1 = (X - C) / rate, left2 = X / (rate + F);
				rate += F;
				if(left1 <= left2) {
					elapsed += left1;
					break;
				}
			}
			cout << elapsed << '\n';
		}
	}
}