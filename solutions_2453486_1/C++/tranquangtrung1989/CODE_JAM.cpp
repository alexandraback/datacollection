#include <iostream>
#include<fstream>
#include<vector>
#include<cmath>
using namespace std;
#define cin fin
#define cout fout
ifstream fin("in.txt");
ofstream fout("out.txt");
using namespace std;

int main() {

	int T;
	bool isNotDraw;
	int cntX, cntO;
	char chess[4][4];
	cin >> T;
	for(int t=1;t<=T;t++){
		isNotDraw=false;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++){
				cin>>chess[i][j];
				if(chess[i][j]=='.') isNotDraw=true;
			}
		for(int i=0;i<4;i++){
			cntX=cntO=0;
			for(int j=0;j<4;j++){
				if(chess[i][j]=='X'||chess[i][j]=='T') cntX++;
				if(chess[i][j]=='O'||chess[i][j]=='T') cntO++;
			}
			if(cntX==4||cntO==4) break;
		}
		if(cntX!=4&&cntO!=4){
			for(int j=0;j<4;j++){
						cntX=cntO=0;
						for(int i=0;i<4;i++){
							if(chess[i][j]=='X'||chess[i][j]=='T') cntX++;
							if(chess[i][j]=='O'||chess[i][j]=='T') cntO++;
						}
						if(cntX==4||cntO==4) break;
					}
		}
		if(cntX!=4&&cntO!=4){
			cntX=cntO=0;
			for(int i=0;i<4;i++){
				if(chess[i][i]=='X'||chess[i][i]=='T') cntX++;
				if(chess[i][i]=='O'||chess[i][i]=='T') cntO++;
			}
		}
		if(cntX!=4&&cntO!=4){
			cntX=cntO=0;
			for(int i=0;i<4;i++){
				if(chess[i][3-i]=='X'||chess[i][3-i]=='T') cntX++;
				if(chess[i][3-i]=='O'||chess[i][3-i]=='T') cntO++;
			}
		}
		cout<<"Case #"<<t<<": ";
		if(cntX==4) cout<<"X won";
		else if(cntO==4) cout<<"O won";
		else if(isNotDraw) cout<<"Game has not completed";
		else cout<<"Draw";
		cout<<endl;
	}
	return 0;
}
