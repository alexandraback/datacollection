#include <iostream>
using namespace std;
int main(){
	
	freopen("D-large.in", "r", stdin);
	freopen("D-large.out", "w", stdout);
	
	int T;
	cin >> T;
	
	int X, R, C;
	
	for (int i = 0; i < T; i++){
		
		cin >> X >> R >> C;
		
		if (X == 1){
			cout << "Case #" << i + 1 << ": GABRIEL" << endl;
		} else if (X == 2){
			
			if ((R*C)%2 == 0){
				cout << "Case #" << i + 1 << ": GABRIEL" << endl;
			} else {
				cout << "Case #" << i + 1 << ": RICHARD" << endl;
			}
			
		} else if (X == 3){
			
			if (R == 1 || C == 1){
				cout << "Case #" << i + 1 << ": RICHARD" << endl;
			} else if ((R*C)%3 != 0){
				cout << "Case #" << i + 1 << ": RICHARD" << endl;
			} else {
				cout << "Case #" << i + 1 << ": GABRIEL" << endl;
			}
			
		} else if (X == 4){
			
			if (R <= 2 || C <= 2){
				cout << "Case #" << i + 1 << ": RICHARD" << endl;
			} else if ((R*C) %4 != 0){
				cout << "Case #" << i + 1 << ": RICHARD" << endl;
			} else {
				cout << "Case #" << i + 1 << ": GABRIEL" << endl;
			}
			
		} else if (X == 5){
			
			if (R <= 2 || C <= 2){
				cout << "Case #" << i + 1 << ": RICHARD" << endl;
			} else if ((R*C)%5 != 0){
				cout << "Case #" << i + 1 << ": RICHARD" << endl;
			} else if (R == 3 && C == 5) {
				cout << "Case #" << i + 1 << ": RICHARD" << endl;
			} else if (R == 5 && C == 3){
				cout << "Case #" << i + 1 << ": RICHARD" << endl;
			} else {
				cout << "Case #" << i + 1 << ": GABRIEL" << endl;
			}
			
		} else if (X == 6){
			
			if (R <= 2 || C <= 2){
				cout << "Case #" << i + 1 << ": RICHARD" << endl;
			} else if ((R*C)%6 != 0){
				cout << "Case #" << i + 1 << ": RICHARD" << endl;
			} else if (R == 3 && C == 4){
				cout << "Case #" << i + 1 << ": RICHARD" << endl;
			} else if (R == 4 && C == 3){
				cout << "Case #" << i + 1 << ": RICHARD" << endl;
			} else {
				cout << "Case #" << i + 1 << ": GABRIEL" << endl;
			}
			
		} else {
			cout << "Case #" << i + 1 << ": RICHARD" << endl;
		}
		
		
	}
	
	
	
	
	
	
}
