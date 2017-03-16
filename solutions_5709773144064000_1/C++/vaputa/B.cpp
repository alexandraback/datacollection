#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	int T;
	double C, F, X;
	cin >> T;
	for (int i = 0; i < T; ++i){
		double time = 0;
		double speed = 2;
		cin >> C >> F >> X;

		while ((X / speed) > (C / speed + X / (speed + F))){
			time += C / speed;
			speed += F;
//			cout << time << " " << speed << endl;
		}
		time += X / speed;
		printf("Case #%d: %.10lf\n", i + 1, time);
	}
	return 0;
}