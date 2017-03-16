#include <iostream>
#include <string>
using namespace std;


int main() {
	int n, result, dot;
	bool okx, oko;
	string str;
	int dat[4][4];
	cin >> n;
	for (int i=1; i<=n; i++){
		dot=0;
		// input
		for (int j=0; j<=3; j++){
			cin >> str;
			for (int k=0; k<=3; k++){
				if (str[k]=='X'){
					dat[j][k]=1;
				}
				else if (str[k]=='O'){
					dat[j][k]=2;
				}
				else if (str[k]=='.'){
					dat[j][k]=3;
					dot++;
				}
				else {dat[j][k]=0;}
			}
		}
		//search***************
		result=10;
		//row
		for (int j=0; j<=3; j++){
			if ((dat[j][0]==3)||(dat[j][1]==3)||(dat[j][2]==3)||(dat[j][3]==3)){
				continue;
			}
			okx=false;oko=false;
			for (int k=0; k<=3; k++){
				if (dat[j][k]==1) okx=true;
				if (dat[j][k]==2) oko=true;
			}
			if (okx && oko) continue;
			if (okx && !oko){
				result=1;
				break;
			}
			if (oko && !okx){
				result=2;
				break;
			}
		}

		//column
		if (result == 10){
			for (int j=0; j<=3; j++){
				if ((dat[0][j]==3)||(dat[1][j]==3)||(dat[2][j]==3)||(dat[3][j]==3)){
					continue;
				}
				okx=false;oko=false;
				for (int k=0; k<=3; k++){
					if (dat[k][j]==1) okx=true;
					if (dat[k][j]==2) oko=true;
				}
				if (okx && oko) continue;
				if (okx && !oko){
					result=1;
					break;
				}
				if (oko && !okx){
					result=2;
					break;
				}
			}
		}

		//diagonal
		if (result == 10){
		for (int p=0; p<=0; p++){
			if ((dat[0][0]==3)||(dat[1][1]==3)||(dat[2][2]==3)||(dat[3][3]==3)){
					continue;
			}
			okx=false;oko=false;
			for (int k=0; k<=3; k++){
				if (dat[k][k]==1) okx=true;
				if (dat[k][k]==2) oko=true;
			}
			if (okx && oko) continue;
			if (okx && !oko){
				result=1;
			}
			if (oko && !okx){
				result=2;
			}
		}
		}


		if (result == 10){
		for (int p=0; p<=0; p++){
			if ((dat[0][3]==3)||(dat[1][2]==3)||(dat[2][1]==3)||(dat[3][0]==3)){
					continue;
			}
			okx=false;oko=false;
			for (int k=0; k<=3; k++){
				if (dat[k][3-k]==1) okx=true;
				if (dat[k][3-k]==2) oko=true;
			}
			if (okx && oko) continue;
			if (okx && !oko){
				result=1;
			}
			if (oko && !okx){
				result=2;
			}
		}
		}



		cout << "Case #" << i << ": ";
		if (result==1){
			cout << "X won" << endl;
		}
		else if(result==2){
			cout << "O won" << endl;
		}
		else if ((result==10)&&(dot==0)){
			cout << "Draw" << endl;
		}
		else{
			cout << "Game has not completed" << endl;
		}
		cin;
	}
	return 0;
}
