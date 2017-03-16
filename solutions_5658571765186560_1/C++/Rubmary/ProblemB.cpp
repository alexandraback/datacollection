#include <iostream>
using namespace std;

int main () {
	int T;
	int X, R, C;
	string winner;
	
	cin >> T;
	
	for (int i=1; i<=T; i++) {
		cin >> X >> R >> C;
		
		winner = "RICHARD";
		
		if (X==1)
			winner = "GABRIEL";
		else if (X==2 && (R*C)%2==0)
				winner = "GABRIEL";
		else if (X==3 && R>1 && C>1 && (C*R)%3==0)
				winner = "GABRIEL";
		else if (X==4 && R>2 && C>2 && (C*R)%4==0)
				winner = "GABRIEL";
		else if (X==5) {
			if ((R==3 && C%5==0 && C>5) || (C==3 && R%5==0 && R>5))
				winner = "GABRIEL";
			else if (R>3 && C>3 && (R*C)%5==0)
				winner = "GABRIEL";
		}
		else if (X==6 && R>3 && C>3 && (R*C)%6==0)
			winner = "GABRIEL";
		
		cout << "Case #" << i << ": " << winner << endl;	
	}
	
	return 0;
}
