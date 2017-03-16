#include<iostream>
#include<string>
using namespace std;

char b[6][6];

bool h4(char c){
	int y=true,z=true;
	for(int i=1;i<=4;++i){
		bool x=true;
		for(int j=1;j<=4;++j)
		x&= (b[i][j]==c||b[i][j]=='T');
		if(x)return true;
		x=true;
		for(int j=1;j<=4;++j)
		x&= (b[j][i]==c||b[j][i]=='T');
		if(x)return true;
		y&=(b[i][i]==c || b[i][i]=='T');
		z&=(b[i][5-i]==c || b[i][5-i]=='T');
	}
	return y||z;
}
string solve(){
	for(int i=1;i<=4;++i)
		for(int j=1;j<=4;++j)
			cin >> b[i][j];
	if(h4('X'))return "X won";
	if(h4('O'))return "O won";
	for(int i=1;i<=4;++i)
	for(int j=1;j<=4;++j)
		if(b[i][j]=='.')return"Game has not completed";
	return"Draw";
}
int main(){
	int Tc=1,T;
	for(cin>>T;Tc<=T;++Tc){
		cout << "Case #"<<Tc<<": "
		<< solve() << endl;
	}
}
