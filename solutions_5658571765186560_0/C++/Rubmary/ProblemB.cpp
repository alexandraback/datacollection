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
		else if (X==2 && (R%2==0 || C%2==0))
				winner = "GABRIEL";
		else if (X==3 && ((R==3 && C>1) || (C==3 && R>1)) )
				winner = "GABRIEL";
		else if (X==4 && ((R==4 && C>2) || (C==4 && R>2)) )
				winner = "GABRIEL";
		
		cout << "Case #" << i << ": " << winner << endl;	
	}
	
	return 0;
}
