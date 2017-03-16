#include <iostream>
#include <string>
using namespace std;
int main(){
	int t;
	cin >> t;
	for(int i=1;i<=t;i++){
		int ans=0;
		string s[4];
		for(int j=0;j<4;j++) cin >> s[j];
		for(int j=0;j<4;j++){
			int sumx=0,sumo=0;
			for(int k=0;k<4;k++){
				if(s[j][k]=='X') sumx++;
				if(s[j][k]=='O') sumo++;
				if(s[j][k]=='T'){
					sumx++;
					sumo++;
				}
			}
			if(sumx==4) ans=1;
			if(sumo==4) ans=2;
		}
		for(int j=0;j<4;j++){
			int sumx=0,sumo=0;
			for(int k=0;k<4;k++){
				if(s[k][j]=='X') sumx++;
				if(s[k][j]=='O') sumo++;
				if(s[k][j]=='T'){
					sumx++;
					sumo++;
				}
			}
			if(sumx==4) ans=1;
			if(sumo==4) ans=2;
		}
		int sumx=0,sumo=0;
		for(int j=0;j<4;j++){
			if(s[j][j]=='X') sumx++;
			if(s[j][j]=='O') sumo++;
			if(s[j][j]=='T'){
				sumx++;
				sumo++;
			}
			if(sumx==4) ans=1;
			if(sumo==4) ans=2;
		}
		sumx=0;
		sumo=0;
		for(int j=0;j<4;j++){
			if(s[j][3-j]=='X') sumx++;
			if(s[j][3-j]=='O') sumo++;
			if(s[j][3-j]=='T'){
				sumx++;
				sumo++;
			}
			if(sumx==4) ans=1;
			if(sumo==4) ans=2;
		}
		cout << "Case #" << i <<": ";
		if(ans==1) cout << "X won";
		if(ans==2) cout << "O won";
		if(ans==0){
			bool flag=false;
			for(int j=0;j<4;j++){
				for(int k=0;k<4;k++){
					if(s[j][k]=='.') flag=true;
				}
			}
			if(flag) cout << "Game has not completed";
			else cout << "Draw";
		}
		cout << endl;
	}
	return 0;
}