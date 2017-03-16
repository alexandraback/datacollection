#include <string>
#include <iostream>

using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string s[4];
	int test;
	cin >>test;
	for (int i=0; i<test; ++i){
		cout <<"Case #" <<i+1 <<": ";
		for (int j=0; j<4; ++j)
			cin >>s[j];
		bool f=false;
		for (int j=0; j<4; ++j){
			int k;
			for (k=0; k<4; ++k)
				if (s[j][k]=='.' || s[j][k]=='O')
					break;
			if (k==4){
				cout <<"X won" <<endl;
				f=true;
				break;
			}
			for (k=0; k<4; ++k)
				if (s[j][k]=='.' || s[j][k]=='X')
					break;
			if (k==4){
				cout <<"O won" <<endl;
				f=true;
				break;
			}
		}
		if (!f)
			for (int j=0; j<4; ++j){
				int k;
				for (k=0; k<4; ++k)
					if (s[k][j]=='.' || s[k][j]=='O')
						break;
				if (k==4){
					cout <<"X won" <<endl;
					f=true;
					break;
				}
				for (k=0; k<4; ++k)
					if (s[k][j]=='.' || s[k][j]=='X')
						break;
				if (k==4){
					cout <<"O won" <<endl;
					f=true;
					break;
				}
			}
		if (!f){
			int k;
			for (k=0; k<4; ++k)
				if (s[k][k]=='.' || s[k][k]=='O')
					break;
			if (k==4){
				cout <<"X won" <<endl;
				f=true;
				break;
			}
			for (k=0; k<4; ++k)
				if (s[k][k]=='.' || s[k][k]=='X')
					break;
			if (k==4){
				cout <<"O won" <<endl;
				f=true;
			}
		}
		if (!f){
			int k;
			for (k=0; k<4; ++k)
				if (s[k][3-k]=='.' || s[k][3-k]=='O')
					break;
			if (k==4){
				cout <<"X won" <<endl;
				f=true;
				break;
			}
			for (k=0; k<4; ++k)
				if (s[k][3-k]=='.' || s[k][3-k]=='X')
					break;
			if (k==4){
				cout <<"O won" <<endl;
				f=true;
			}
		}
		if (f)
			continue;
		int kol=0;
		for (int j=0; j<4; ++j)
			for (int k=0; k<4; ++k)
				kol+=(s[j][k]!='.');
		if (kol==16)
			cout <<"Draw" <<endl;
		else
			cout <<"Game has not completed" <<endl;
	}
	return 0;
}