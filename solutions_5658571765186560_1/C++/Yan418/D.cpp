#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	int n;
	ifstream inf("D-large.in");
	ofstream outf("D-large.out");
	inf >> n;
	for (int i = 1; i <= n; i++){
		int X, R, C;
		inf >> X>>R>>C;
		bool canFill = false;
		if (R > C){
			int t = R;
			R = C;
			C = t;
		}

		if (X >= 7)
			canFill = false;
		else if (R * C % X != 0)
			canFill = false;
		else if (R < (X+1)/2 || C < X)
			canFill = false;
		else{
			if (X <= 3)
				canFill = true;
			else{
				if (R <= (X + 1) / 2)
					canFill = false;
				else
					canFill = true;
			}
		}
		outf << "Case #" << i << ": " << (canFill ? "GABRIEL" : "RICHARD" )<< "\n";
	}


	return 0;
}