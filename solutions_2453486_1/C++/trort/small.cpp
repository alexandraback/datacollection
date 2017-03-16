#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

using namespace std;

const double PI=3.14159265358979323846264338327950288;
ifstream fin;
ofstream fout;

string _main(){
	int i,j,k;
	char board[4][4];
	char lord;
	bool line;
	for(i=0; i<4; i++) for(j=0; j<4; j++){
		fin>>board[i][j];
	}
	//cross
	lord = board[0][0];
	if(lord == 'T') lord = board[1][1];
	if(lord != '.'){
		line = true;
		for(i=1; i<4; i++){
			if(board[i][i] != lord && board[i][i] != 'T') line = false;
		}
		if(line){
			if(lord == 'X') return "X won";
			else return "O won";
		}
	}
	//conter cross
	lord = board[0][3];
	if(lord == 'T') lord = board[1][2];
	if(lord != '.'){
		line = true;
		for(i=1; i<4; i++){
			if(board[i][3-i] != lord && board[i][3-i] != 'T') line = false;
		}
		if(line){
			if(lord == 'X') return "X won";
			else return "O won";
		}
	}
	
	//row
	for(j=0; j<4; j++){
		lord = board[j][0];
		if(lord == 'T') lord = board[j][1];
		if(lord != '.'){
			line = true;
			for(i=1; i<4; i++){
				if(board[j][i] != lord && board[j][i] != 'T') line = false;
			}
			if(line){
				if(lord == 'X') return "X won";
				else return "O won";
			}
		}
	}
	//col
	for(j=0; j<4; j++){
		lord = board[0][j];
		if(lord == 'T') lord = board[1][j];
		if(lord != '.'){
			line = true;
			for(i=1; i<4; i++){
				if(board[i][j] != lord && board[i][j] != 'T') line = false;
			}
			if(line){
				if(lord == 'X') return "X won";
				else return "O won";
			}
		}
	}
	
	//no winner
	int count=0;
	for(i=0; i<4; i++) for(j=0; j<4; j++){
		if(board[i][j] == '.') count ++;
	}
	if(count == 0) return "Draw";
	else return "Game has not completed";
}

int main(){
    fin.open("sample.in");
    fout.open("result.out");
    int T;
    fin>>T;
    for(int i=0;i<T;i++){
            fout<<"Case #"<<i+1<<": ";
            cout<<"Case #"<<i+1<<" is runing"<<endl;
            fout<<_main();
            fout<<endl;
    }
}
