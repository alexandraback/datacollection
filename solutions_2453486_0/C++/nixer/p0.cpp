#include <iostream>
#include <string>
using namespace std;

int main(){
	int t;
	cin>>t;
	cout<<t<<endl;
	for(int k = 1; k <= t; k++){
		string game[4];
		cin>>game[0];
		cin>>game[1];
		cin>>game[2];
		cin>>game[3];

		bool done = false;
		/* check if O won */
		for(int i=0; i<4; i++){
			if((game[i][0] == 'T' || game[i][0] == 'O') && 
				(game[i][1] == 'T' || game[i][1] == 'O') &&
				(game[i][2] == 'T' || game[i][2] == 'O') &&
				(game[i][3] == 'T' || game[i][3] == 'O'))
			{	
				cout<<"Case #"<<k<<": O won"<<endl;
				done = true; break;
			}	
		}

		if(done) continue;

		/* check if X won */
		for(int i=0; i<4; i++){
			if((game[i][0] == 'T' || game[i][0] == 'X') && 
				(game[i][1] == 'T' || game[i][1] == 'X') &&
				(game[i][2] == 'T' || game[i][2] == 'X') &&
				(game[i][3] == 'T' || game[i][3] == 'X'))
			{	
				cout<<"Case #"<<k<<": X won"<<endl;
								done = true; break;

			}	
		}
				if(done) continue;

		/* check if X won */
		for(int i=0; i<4; i++){
			if((game[0][i] == 'T' || game[0][i] == 'X') && 
				(game[1][i] == 'T' || game[1][i] == 'X') &&
				(game[2][i] == 'T' || game[2][i] == 'X') &&
				(game[3][i] == 'T' || game[3][i] == 'X'))
			{	
				cout<<"Case #"<<k<<": X won"<<endl;
								done = true; break;

			}	
		}
		if(done) continue;

		/* check if O won */
		for(int i=0; i<4; i++){
			if((game[0][i] == 'T' || game[0][i] == 'O') && 
				(game[1][i] == 'T' || game[1][i] == 'O') &&
				(game[2][i] == 'T' || game[2][i] == 'O') &&
				(game[3][i] == 'T' || game[3][i] == 'O'))
			{	
				cout<<"Case #"<<k<<": O won"<<endl;
								done = true; break;
			}	
		}
		if(done) continue;

		if((game[0][0] == 'T' || game[0][0] == 'X') && 
			(game[1][1] == 'T' || game[1][1] == 'X') &&
			(game[2][2] == 'T' || game[2][2] == 'X') &&
			(game[3][3] == 'T' || game[3][3] == 'X'))
		{	
			cout<<"Case #"<<k<<": X won"<<endl;
							done = true; 
		}	
		if(done) continue;

		if((game[0][0] == 'T' || game[0][0] == 'O') && 
			(game[1][1] == 'T' || game[1][1] == 'O') &&
			(game[2][2] == 'T' || game[2][2] == 'O') &&
			(game[3][3] == 'T' || game[3][3] == 'O'))
		{	
			cout<<"Case #"<<k<<": O won"<<endl;
							done = true; 
		}
		if(done) continue;

		if((game[3][0] == 'T' || game[3][0] == 'O') && 
			(game[2][1] == 'T' || game[2][1] == 'O') &&
			(game[1][2] == 'T' || game[1][2] == 'O') &&
			(game[0][3] == 'T' || game[0][3] == 'O'))
		{	
			cout<<"Case #"<<k<<": O won"<<endl;
			done = true; 
		}
		if(done) continue;

		if((game[3][0] == 'T' || game[3][0] == 'X') && 
			(game[2][1] == 'T' || game[2][1] == 'X') &&
			(game[1][2] == 'T' || game[1][2] == 'X') &&
			(game[0][3] == 'T' || game[0][3] == 'X'))
		{	
			cout<<"Case #"<<k<<": X won"<<endl;
			done = true; 
		}
		if(done) continue;

		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				if(game[i][j] == '.'){
								cout<<"Case #"<<k<<": Game has not completed"<<endl;
							done = true; break;
				}
			}
			if(done) break;
		}
		if(done) continue;

		cout<<"Case #"<<k<<": Draw"<<endl;
	}
	return 0;
}