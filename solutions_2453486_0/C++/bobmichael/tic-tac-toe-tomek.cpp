//#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

ifstream cin("A-small-attempt0.in");
ofstream cout("mik.txt");

vector<string> X,O;

int main(){
	int T; cin>>T;
	for(int t=1;t<=T;t++){
		vector<string> board;
		for(int i=0;i<4;i++){ string s; cin>>s; board.push_back(s);	}
		X=O=board;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				if(board[i][j]=='T'){
					X[i][j]='X'; O[i][j]='O';
				}
		string state="";
		for(int i=0;i<4;i++)
			if(X[i].find("XXXX")!=string::npos) state="X won";
		for(int i=0;i<4;i++)
			if(O[i].find("OOOO")!=string::npos) state="O won";

		for(int i=0;i<4;i++){
			string s;
			for(int j=0;j<4;j++) s+=X[j][i];
			if(s=="XXXX") state="X won";
		}

		for(int i=0;i<4;i++){
			string s;
			for(int j=0;j<4;j++) s+=O[j][i];
			if(s=="OOOO") state="O won";
		}

		string d1,d2;
		for(int i=0;i<4;i++){
			d1+=X[i][i];
			d2+=X[i][3-i];
		}
		if(d1=="XXXX" || d2=="XXXX") state="X won";

		d1.clear(); d2.clear();
		for(int i=0;i<4;i++){
			d1+=O[i][i];
			d2+=O[i][3-i];
		}
		if(d1=="OOOO" || d2=="OOOO") state="O won";

		if(state==""){
			bool full=true;
			for(int i=0;i<4;i++) for(int j=0;j<4;j++) if(X[i][j]=='.') full=false;
			if(full) state="Draw";
			else state="Game has not completed";
		}

		cout<<"Case #"<<t<<": "<<state<<endl;
	}
}