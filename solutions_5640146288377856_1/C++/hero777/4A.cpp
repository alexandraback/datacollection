#include <iostream>
#include <algorithm>
#include <vector>
#include<fstream>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int num (int R,int C,int W){
		if (C == W || C == W+1){
			return C;
			
		}
		if (W == 1){
			return C;
		}
		if ( C == W+2){
			return W+1;
		}
		if ( C <= 2*W){
			return W+1;
		}
		return (1+num(R, C-W, W));
}



int main(){
	int T;
	ifstream input;
	ofstream output;
	input.open("a.txt");
	output.open("output.txt");
	input >> T;
	forn (i, T){
		//printf("break\n");
		output << "Case #"<< i+1 <<": ";
		int R, C, W;
		input >> R >> C >> W;
		int y = C/W;
		int x = num(R,C,W) + y*(R-1);
		output << x << endl;
		
	}
}
