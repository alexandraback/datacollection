#include<iostream>
using namespace std;

int tt, x, c, r;

int main(){
	cin >> tt;
	for (int _t=0 ; _t<tt ; _t++){
		cin >> x >> r >> c;
		if (r>c) swap(r, c);
		int J = 0;
		if (x==1){
			J = 1;
		}
		if (x==2){
			if (r%2==0 || c%2==0) J = 1;
		}
		if (x==3){
			if (c==3 && r==2) J = 1;
			if (c==3 && r==3) J = 1;
			if (c==4 && r==3) J = 1;
		}
		if (x==4){
			if (c==4 && r==3) J = 1;
			if (c==4 && r==4) J = 1;
		}
		cout << "Case #" << _t+1 << ": " << (J?"GABRIEL":"RICHARD") << endl;
	}
}
