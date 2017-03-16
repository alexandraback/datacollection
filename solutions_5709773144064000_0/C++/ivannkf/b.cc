#include <iostream>
#include <iomanip>
using namespace std;

double calc(double c, double f, double x, double production, double ttime, double bestime) {
	double left = x/production;
	if(bestime != -1 and left+ttime >= bestime) return bestime;
	double tofarm = c/production;
	return calc(c,f,x,production+f,ttime+tofarm, ttime+left);
}

int main() {
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i) {
		double c,f,x;
		cin >> c >> f >> x;
		cout << "Case #" << i+1 << ": ";
		cout << setprecision(7) << std::fixed << calc(c,f,x,2,0,-1) << endl;
	}
}