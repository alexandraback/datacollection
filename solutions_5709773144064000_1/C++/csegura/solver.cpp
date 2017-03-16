#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(){
	int T;
	cin >> T;
	for (int i = 0; i < T; i++){
		double C, F, X;
		cin >> C >> F >> X;
		double currentRate = 2;
		double requiredTime = 0;
		while(true){
			double opt1 = X / currentRate;
			double opt2 = C / currentRate + X / (currentRate + F);
			if (opt2 > opt1){
				requiredTime += opt1;
				break;
			} else {
				requiredTime += C / currentRate;
				currentRate += F;
			}
		}
		cout << "Case #" << (i + 1) << ": " << fixed << setprecision(7) << requiredTime << endl; 
	}
}
