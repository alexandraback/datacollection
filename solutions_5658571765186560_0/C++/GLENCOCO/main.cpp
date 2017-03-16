#include <iostream>
using namespace std;

void main(){
	int T, X, R, C;
	int winner;
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> X;
		cin >> R;
		cin >> C;
		cout << "Case #" << t << ": ";
		winner = 0;
		if (R < C){ //Flip the board so R is always largest
			int temp = R;
			R = C;
			C = temp;
		}
		//EZ wins for Richard
		if ((R*C) % X)winner=1;  //Area not divisible by X
		if ((X>R) && (X > C))winner = 1;
		if (X >= (C + C + 1))winner = 1;
		if (X>(R + C - 1))winner = 1; //I think this one's redundant, but whatevs
		if (X >= 7)winner = 1; //just play a piece that has an encircled empty square.
		if ((X == 4) && (R == 4) && (C == 2))winner = 1;
		if (winner == 1){
			cout << "Richard" << endl;
			continue;
		}
		//If the other things arent true, gabriel can always win a 3 or 4 omino
		cout << "Gabriel" << endl;
	}
}