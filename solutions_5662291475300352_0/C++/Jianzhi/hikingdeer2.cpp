#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	
	freopen("C-small-1-attempt1.in", "r", stdin);
	freopen("C-small-1-attempt1.out", "w", stdout);
	
	int t, n;
	long double d[2];
	long double h[2];
	long double m[2];
	long double hikers = 0;
	long double velocity1;
	long double velocity2;
	
	cin >> t;
	
	for (int i = 0; i < t; i++){
		hikers = 0;
		cin >> n;
		for (int j = 0; j < n; j++){
			cin >> d[j] >> h[j] >> m[j];
			hikers = hikers + h[j];
		}
		if (hikers == 1){
			cout << "Case #" << i + 1 << ": " << 0 << endl;
			continue;
		}
		if (n == 1){
			velocity1 = 360/m[0];
			velocity2 = 360/(m[0] + 1);
			if ((360*velocity2)/(velocity1 - velocity2) > (360 - d[0])){
				cout << "Case #" << i + 1 << ": " << 0 << endl;
				continue;
			} else {
				cout << "Case #" << i + 1 << ": " << 1 << endl;
				continue;
			}
		}
		
		if (n == 2){
			velocity1 = 360/m[0];
			velocity2 = 360/m[1];
			if (velocity1 >= velocity2){
				
				if (((360 - d[0] + d[1])*velocity2)/(velocity1 - velocity2) > (360 - d[1])){
					cout << "Case #" << i + 1 << ": " << 0 << endl;
					continue;
				} else {
					cout << "Case #" << i + 1 << ": " << 1 << endl;
					continue;
				}
				
				
			} else {
				
				if ((360 - d[1] + d[0])*velocity1/(velocity2 - velocity1) > (360 - d[0])){
					cout << "Case #" << i + 1 << ": " << 0 << endl;
					continue;
				} else {
					cout << "Case #" << i + 1 << ": " << 1 << endl;
					continue;
				}
			}
		}
		
		
		
		
		
		
	}
	
	
	
}
