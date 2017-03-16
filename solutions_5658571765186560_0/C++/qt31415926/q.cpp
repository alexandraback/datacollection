#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
using namespace std;

int simpleCheck(int gridarea, int Xomino){
	if (gridarea%Xomino!=0){
		return -1;
	} else
		return 0;
}

int LCheck(int gridX, int gridY, int Xomino){
	//even/odd xomino
	if (Xomino%2==0){
		for (int i = 1; i <= Xomino/2; i++){
			//both lengths has to be greater than one of the grid axis for RICH to win
			if ((i > gridX && (Xomino+1-i) > gridX) || (i > gridY && (Xomino+1-i) > gridY)){
				return -1;
			}
		}
	}else{
		for (int i = 1; i <= Xomino/2+1; i++){
			//both lengths has to be greater than one of the grid axis for RICH to win
			if ((i > gridX && (Xomino+1-i) > gridX) || (i > gridY && (Xomino+1-i) > gridY)){
				return -1;
			}
		}
	}
	return 0;
}

int hardCoded(int gridX
		, int gridY
		, int Xomino){
	if (Xomino == 4){
		if (gridX == 2 || gridY == 2){
			return -1;
		}
	}
	return 0;
}

int main(){
	int T, X, R, C;
	string answer;
	cin >> T;
	for (int i = 0; i < T; i++){
		answer = "GABRIEL";
		cin >> X;
		cin >> R;
		cin >> C;
		if (LCheck(R, C, X)==-1){
			answer = "RICHARD";
		}
		if (hardCoded(R,C,X)==-1){
			answer = "RICHARD";
		}
		if (simpleCheck(R*C, X)==-1){
			answer = "RICHARD";
		}
		if (X == 1){
			answer = "GABRIEL";
		}
		cout << "Case #" << i + 1 << ": " << answer << endl;
	}
	return 0;
}
