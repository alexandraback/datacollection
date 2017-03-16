#include <iostream>
#include <string>
using namespace std;

int main(){
	cin.sync_with_stdio(false);

	int T;
	cin >> T;

	int X, R, C;

	for (int t = 1; t <= T; t++){
		string result = "RICHARD";
		cin >> X >> R >> C;
		if (R > C){
			swap(R, C);
		}
		if (X == 1){
			result = "GABRIEL";
		}
		else if (X == 2 && (R*C) % 2 == 0){
			result = "GABRIEL";
		}
		else if (X == 3 && (R*C) % 3 == 0){
			if ((R >= 2 && C >= 3)){
				result = "GABRIEL";
			}
		}
		else if (X == 4 && (R*C) % 4 == 0){
			if ((R >= 3 && C >= 4)){
				result = "GABRIEL";
			}
		}
		cout << "Case #" << t << ": " << result << endl;
	}

	return 0;
}
