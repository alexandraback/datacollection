#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int t,n,x,r,c;
	cin >> t;
	n = 0;
	while (n++ < t){
		cin >> x >> r >> c;
		if (x == 1){
			cout << "Case #" << n <<": " << "GABRIEL" << endl;

		}
		else if (x == 2){
			if (r * c % 2 == 0)
				cout << "Case #" << n <<": " << "GABRIEL" << endl;
			else
				cout << "Case #" << n <<": " << "RICHARD" << endl;
		}
		else if (x == 3){
			if ((r + c >= 5) && (r* c % 3== 0))
				cout << "Case #" << n <<": " << "GABRIEL" << endl;
			else 
				cout << "Case #" << n <<": " << "RICHARD" << endl;
		}
		else if (x == 4){
			if ((r + c>=7) && (r*c%4 == 0))
				cout << "Case #" << n <<": " << "GABRIEL" << endl;
			else 
				cout << "Case #" << n <<": " << "RICHARD" << endl;
		}
		else if (x == 5){
			if ((r + c>=9) && (r*c%5 == 0))
				cout << "Case #" << n <<": " << "GABRIEL" << endl;
			else 
				cout << "Case #" << n <<": " << "RICHARD" << endl;
		}
		else if (x == 6){
			if ((r + c>=11) && (r*c%6 == 0))
				cout << "Case #" << n <<": " << "GABRIEL" << endl;
			else 
				cout << "Case #" << n <<": " << "RICHARD" << endl;
		}
		else
				cout << "Case #" << n <<": " << "RICHARD" << endl;
	}
	return 0;
}