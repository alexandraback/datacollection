#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<map>
using namespace std;

/*
Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of 4 lines with 4 characters each, with each character being 'X', 'O', '.' or 'T' (quotes for clarity only). Each test case is followed by an empty line.
Output

For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is one of the statuses given above. Make sure to get the statuses exactly right. When you run your code on the sample input, it should create the sample output exactly, including the "Case #1: ", the capital letter "O" rather than the number "0", and so on. 

*/

string x="X won";
string o="O won";
string t="Draw";
string g="Game has not completed";
string board[4];

void won(int sum){
	switch(sum){
	case 'X'*4:
	case 'X'*3+'T':
		throw "X won";
	case 'O'*4:
	case 'O'*3+'T':
		throw "O won";
	}
}

string solve(){
	int i,j,k;
	i=j=k=4;
	
	while(i--){
		int sum=0, sum1=0;
		j=4;
		while(j--){
			sum += board[i][j];
			sum1 += board[j][i];
		}
		won(sum);
		won(sum1);
	}
	
	i=j=k=4;
	j=0;
	int diag1=0, diag2=0;
	while(i--)
		diag1 += board[i][i], diag2+= board[i][j++];
	
	won(diag1);
	won(diag2);

	i=j=k=4;
	while(j=4,i--)
		while(j--)
			if(board[i][j]=='.')
				throw "Game has not completed";
	throw "Draw";
}

int main(int argc, char** argv){
	ifstream cin(argv[1]);
//	istringstream cin("6 XXXT .... OO.. ....  XOXT XXOO OXOX XXOO  XOX. OX.. .... ....  OOXX OXXX OX.T O..O  XXXO ..O. .O.. T...  OXXX XO.. ..O. ...O");
	ofstream cout("output.txt");
	int t;
	cin>>t;
	for(int i = 0; i<t; i++){
		
		for(int ii=0;ii<4;ii++)
			cin>>board[ii];
		
		cout<<"Case #"<<(i+1)<<": ";
		try{
			solve();
		}catch(char const*const s){
			cout<<s<<endl;
		}catch(...){
			cout<<"unknown error";
		}
	}
	return 0;
}