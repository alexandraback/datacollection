#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		int r,t;
		cin >> r >> t;
		double k;
		k=(  -(2*r-1)+sqrt((2*r-1)*(2*r-1)+8*t)  )/4;
		cout << "Case #" << i << ": " << (int)k << endl;
	}
	return 0;
}