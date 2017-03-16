#include <iostream>

using namespace std;

int executeProgram();
int getRingCost(int);

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cout << "Case #" << i+1 << ": " << executeProgram() << endl;
	}
}

int executeProgram(){
	int r, t;
	cin >> r >> t;
	int total = 0;
	int ringcount = 0;
	int radius = r;
	while(total <= t){
		total += getRingCost(radius);
		radius += 2;
		ringcount++;
	}
	return ringcount - 1;
}

int getRingCost(int innerR){
	return (innerR+1)*(innerR+1)-(innerR*innerR);
}