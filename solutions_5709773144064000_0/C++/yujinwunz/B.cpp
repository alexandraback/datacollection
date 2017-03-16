#include <iostream>
#include <cstdio>
#include <utility>
using namespace std;

double price, speed, goal;
int cases;

int main() {
	cin>>cases;
	for (int c = 1; c <= cases; c++) {
		cin>>price>>speed>>goal;
		cout<<"Case #"<<c<<": ";
		double time = goal/2.0, rate = 2.0;
		for (int i = 0; i < 500000; i++) {
			double newTime = time-goal/rate;
			newTime += price/rate;
			rate += speed;
			newTime += goal/rate;
			if (time<newTime) {
				printf("%.7f\n", time);
				break;
			}
			time = newTime;
		}
	}
	return 0;
}