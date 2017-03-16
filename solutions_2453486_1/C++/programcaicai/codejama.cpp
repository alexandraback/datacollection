#include <iostream>
#include <stdio.h>
using namespace std;

char s[5][5];
int T;

bool win(char player){
	for(int i=0;i<4;i++){
		bool win=true;
		for(int j=0;j<4;j++) if(s[i][j]!=player && s[i][j]!='T') win=false;
		if(win) return true;
	}
	for(int j=0;j<4;j++){
		bool win=true;
		for(int i=0;i<4;i++) if(s[i][j]!=player && s[i][j]!='T') win=false;
		if(win) return true;
	}
	bool win=true;
	for(int i=0;i<4;i++) {
		if(s[i][i]!=player && s[i][i]!='T') win=false;
	}
	if(win) return true;
	win=true;
	for(int i=0;i<4;i++) {
		if(s[i][3-i]!=player && s[i][3-i]!='T') win=false;
	}
	if(win) return true;
	return false;
}
bool hasempty(){
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++) if(s[i][j]=='.') return true;
	return false;
}

int casno=1;
int main() {
	cin>>T;
	while(T--){
		for(int i=0;i<4;i++) cin>>s[i];
		printf("Case #%d: ",casno++);
		if(win('X')){
			cout<<"X won";
		}else if(win('O')){
			cout<<"O won";
		}else if(hasempty()){
			cout<<"Game has not completed";
		}else{
			cout<<"Draw";
		}
		cout<<endl;

	}
	return 0;
}
