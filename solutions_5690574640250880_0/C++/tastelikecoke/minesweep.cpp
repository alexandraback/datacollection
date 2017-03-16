#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int r, c, mines;
bool failcond = false;
bool plunder(vector<vector<char> > & mines, int i, int j){
	if(0 <= i and i < r and 0 <= j and j < c and mines[i][j]!='*'){
		mines[i][j] = '1';
		return true;
	}
	else return false;
}
bool radiate(vector<vector<char> > & mines, int i, int j){
	if(0 <= i and i < r and 0 <= j and j < c and mines[i][j]!='*' and mines[i][j]!='X'){
		
		if(mines[i][j] == '.'){
			mines[i][j] = 'X';
			radiate(mines,i-1,j);
			radiate(mines,i,j-1);
			radiate(mines,i-1,j-1);
			
			radiate(mines,i+1,j-1);
			radiate(mines,i-1,j+1);
			
			radiate(mines,i+1,j);
			radiate(mines,i,j+1);
			radiate(mines,i+1,j+1);
		}mines[i][j] = 'X';
		return true;
	}
	else return false;
}
bool spotcheck(vector<vector<char> > & mines){
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(mines[i][j] == '*'){
				plunder(mines,i-1,j);
				plunder(mines,i,j-1);
				plunder(mines,i-1,j-1);
				
				plunder(mines,i+1,j-1);
				plunder(mines,i-1,j+1);
				
				plunder(mines,i+1,j);
				plunder(mines,i,j+1);
				plunder(mines,i+1,j+1);
			}
		}
	}
	/*for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout << mines[i][j];
		}
		cout << endl;
	}*/
	int cui = 0, cuj = 0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(mines[i][j] == '.'){
				cui = i; cuj = j;
				radiate(mines,i,j);
				goto end;
			}
		}
	}
	end:
	/*
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout << mines[i][j];
		}
		cout << endl;
	}
	cout << endl;
	*/
	mines[cui][cuj] = 'c';
	bool ret = true;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(mines[i][j] == 'X'){
				mines[i][j] = '.';
			}
			else if(mines[i][j] == '*' or mines[i][j] == 'c'){
			}
			else{
				mines[i][j] = '.';
				ret = false;
			}
		}
	}
	return ret;
}
int backtrack(vector<vector<char> > & mines, int left, int pos){
	if(failcond) return 0;
	if(left <= 0 or pos > r*c){
		vector<vector<char> > mines2 = mines;
		if(left <= 0 and spotcheck(mines2)){
			int minesd = 0;
			for(int i=0;i<r;i++){
				for(int j=0;j<c;j++){
					cout << mines2[i][j];
					if(mines[i][j]=='*') minesd++;
				}
				cout << endl;
			}
			//cout << left << " " << r <<" "<< c <<" "<< minesd << endl; 
			failcond = true;
		}
		return 0;
	}
	for(int i=pos/c;i<r;i++){
		int j=0;
		if(i==pos/c){
			j =pos%c;
		}
		for(;j<c;j++){
			//cout << i << j << "MARKED" << endl;
			if(mines[i][j] == '*') continue;
			mines[i][j] = '*';
			backtrack(mines, left-1, i*c+j+1);
			//cout << i << j << "UNMARKED" << endl;
			mines[i][j] = '.';
		}
	}
	return 0;
}
int main(){
	int cases=0;
	cin >> cases;
	for(int ca=0;ca<cases;ca++){
		r=0,c=0, mines =0;
		failcond = false;
		cin >> r >> c >> mines;
		cout << "Case #"<<ca+1<<":"<<endl;
		if(mines+1 == r*c){
			cout << "c";
			for(int i=0;i<r;i++){
				for(int j=0;j<c;j++){
					if(i == 0 and j == 0) continue;
					cout << "*";
				}
				cout << endl;
			}
		}
		else{
			vector<vector<char> > minefield(r,vector<char>(c,'.'));		
			backtrack(minefield,mines,0);
			if(not failcond) cout << "Impossible" << endl;
		}
	}
}