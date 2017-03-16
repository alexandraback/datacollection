#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <queue>
#include <cmath>
#include <functional>

using namespace std;

int iMax(int a, int b){
	return a > b ? a : b;
}

int iMin(int a, int b){
	return a > b ? b : a;
}

int main(){
		int T;
	cin >> T;
	
	for (int t=1; t <= T; ++t){
		cout << "Case #" << t << ": ";
		int X,R,C;
		cin >> X >> R >> C;
		bool GabrielWin = true;
		//If X >= 7, Richard can always choose the piece with one hole inside
		if (X >= 7) GabrielWin = false;
		int minMaxLength = X;
		int minMinLength =  (X+1)/2;
		int big = iMax(R,C), small = iMin(R,C);
		//These condition make sure that Richard can choose a piece that can't fit into the rectangle
		if (big < minMaxLength || small < minMinLength) GabrielWin = false;
		//These condition make sure that the area of rectangle is multiplicity of X
		if (R*C % X != 0) GabrielWin = false;
		//Some special condition due to asymettric case
		if (X == 4 && small == 2) GabrielWin = false;
		if (X == 5 && small == 3) GabrielWin = false;
		if (X == 6 && small == 3) GabrielWin = false;
		
		if (GabrielWin) cout << "GABRIEL" << endl;
		else cout << "RICHARD" << endl;
		
	}
	return 0;
}
