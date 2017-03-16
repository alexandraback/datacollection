#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(){
	ifstream inp("A-small-attempt0.in");
	cin.rdbuf(inp.rdbuf());
	ofstream out("output.txt");
	cout.rdbuf(out.rdbuf());
	int n; cin>>n;
	for(int i=1;i<=n;i++){
		vector<string> ms(4);
		for(int j=0;j<4;j++){
			cin>>ms[j];
		}
		int x,o,t,p,res=0;
		for(int j=0;j<4;j++){
			x=o=t=p=0;
			for(int k=0;k<4;k++){
				switch(ms[j][k]){
				case '.': p++; break;
				case 'O': o++; break;
				case 'X': x++; break;
				case 'T': t++; break;
				}
			}
			if (p!=0 || (x!=0 && o!=0)) continue;
			if (t+x==4) {res=1; goto end;}
			else {res=2; goto end;}
		}

		for(int j=0;j<4;j++){
			x=o=t=p=0;
			for(int k=0;k<4;k++){
				switch(ms[k][j]){
				case '.': p++; break;
				case 'O': o++; break;
				case 'X': x++; break;
				case 'T': t++; break;
				}
			}
			if (p!=0 || (x!=0 && o!=0)) continue;
			if (t+x==4) {res=1; goto end;}
			else {res=2; goto end;}
		}

			x=o=t=p=0;
			for(int k=0;k<4;k++){
				switch(ms[k][k]){
				case '.': p++; break;
				case 'O': o++; break;
				case 'X': x++; break;
				case 'T': t++; break;
				}
			}
			if (p==0 && (x==0 || o==0)){
			if (t+x==4) {res=1; goto end;}
			else {res=2; goto end;}}

			x=o=t=p=0;
			for(int k=0;k<4;k++){
				switch(ms[k][3-k]){
				case '.': p++; break;
				case 'O': o++; break;
				case 'X': x++; break;
				case 'T': t++; break;
				}
			}
			if (p==0 && (x==0 || o==0)){
			if (t+x==4) {res=1; goto end;}
			else {res=2; goto end;}}

		p=0;
		for(int j=0;j<4;j++)
			for(int k=0;k<4;k++)
				if (ms[j][k]=='.') p++;
		if (p==0) res=3;

end:
		cout<<"Case #"<<i<<": ";
		switch(res){
		case 0: cout<<"Game has not completed"<<endl;break;
		case 1: cout<<"X won"<<endl;break;
		case 2: cout<<"O won"<<endl;break;
		case 3: cout<<"Draw"<<endl;break;
		}
	}
	return 0;
}