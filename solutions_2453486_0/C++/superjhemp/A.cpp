#include<iostream>
using namespace std;

void solve(){
	string s;
	int p[10][2];
	bool done;
	for (int i=0; i<10; i++)
		p[i][0]=p[i][1]=0;
	done=true;
	for (int r=0; r<4; r++){
		cin>>s;
		for (int c=0; c<4; c++){
			if (s[c]=='X' || s[c]=='T'){
				p[c+0][0]++;
				p[r+4][0]++;
				if (r-c==0) p[8][0]++;
				if (r+c==3) p[9][0]++;
			}
			if (s[c]=='O' || s[c]=='T'){
				p[c+0][1]++;
				p[r+4][1]++;
				if (r-c==0) p[8][1]++;
				if (r+c==3) p[9][1]++;
			}
			if (s[c]=='.') done=false;
		}
	}
	for (int i=0; i<10; i++){
		if (p[i][0]==4){
			cout<<"X won"<<endl;
			return;
		}
		if (p[i][1]==4){
			cout<<"O won"<<endl;
			return;
		}
	}
	if (!done){
		cout<<"Game has not completed"<<endl;
		return;
	}
	cout<<"Draw"<<endl;
}

int main(){
	int T;
	cin>>T;
	for (int t=0; t<T; t++){
		cout<<"Case #"<<t+1<<": ";
		solve();
	}
	return 0;
}
