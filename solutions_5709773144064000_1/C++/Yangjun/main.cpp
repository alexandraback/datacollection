#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]){
	int count = 0; 
	cin >> count;
	cout.setf(ios::showpoint);
	cout.precision(7);
	cout.setf(ios::fixed);
	for(int i=0; i<count; i++){
		double C, F, X;
		cin >> C >> F >> X;
		double S = 2; // speed
		double T=0; // total time
		while(C*(S+F)<X*F){
			T += C/S;
			S += F;
		}
		T += X/S;
		cout << T << endl;
	}
	return 0;
}
