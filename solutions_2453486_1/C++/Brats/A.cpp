#include<iostream>
using namespace std;

int main()
{
    char game[4][5];
	int T;
	
	cin >> T;
	int C = 0;
	int i,j;
	
	while(T--) {
	    C++;
		cout << "Case #" << C << ": ";
		
		for (i=0; i<4; i++) {
		    cin >> game[i];
		}
		
		bool won = false;
		char who;
		
		for (i=0; i<4; i++) {
		    who = game[i][0];
			if (who == 'T') {
			    who = game[i][1];
			}
			if (who == '.') {
			    continue;
			}
			
		    for (j=0; j<4; j++) {
			    if (game[i][j] != who && game[i][j] != 'T') {
				    break;
				}
			}
			if (j==4) {
			    won = true;
				break;
			}
		}
		
		if (won != true) {
		    
			for (i=0; i<4; i++) {
			    who = game[0][i];
				if (who == 'T') who = game[1][i];
				if (who == '.') continue;
				
				for (j=0; j<4; j++) {
				    if (game[j][i] != who && game[j][i] != 'T') {
					    break;
					}
				}
				if (j==4) {
				    won = true;
					break;
				}
			}
		}
		
		if (won != true) {
		    who = game[0][0];
			if (who == 'T') who = game[1][1];
			if (who != '.') {
			    if ((game[1][1] == 'T' || game[1][1] == who)
				    && (game[2][2] == 'T' || game[2][2] == who)
					&& (game[3][3] == 'T' || game[3][3] == who)
					) {
					won = true;
				}
			}
		}
		
		if (won != true) {
		    who = game[0][3];
			if (who == 'T') who = game[1][2];
			if (who != '.') {
			    if ((game[1][2] == 'T' || game[1][2] == who)
				    && (game[2][1] == 'T' || game[2][1] == who)
					&& (game[3][0] == 'T' || game[3][0] == who)
					) {
					won = true;
				}
			}
		}
		
		if (won == true) {
		    cout << who << " won\n";
		} else {
		    for (i=0; i<4; i++) {
			    for (j=0; j<4; j++) {
				    if (game[i][j] == '.') break;
				}
				if (j!=4) break;
			}
			
			if (i==4) {
			    cout << "Draw\n";
			} else {
			    cout << "Game has not completed\n";
			}
		}
		
		cin.get();
	}
	
	return 0;
}
