#include<iostream>
using namespace std;

int tt, x, l;
string S;

int a(char c){
	if (c=='i') return 2;
	if (c=='j') return 3;
	if (c=='k') return 4;
	return -1;
}

int z3(int x, int y){
	if (x==1) return y;
	if (y==1) return x;
	if (x==y) return -1;
	if (x==2){
		if (y==3) return 4;
		return -3;
	}
	if (x==3){
		if (y==2) return -4;
		return 2;
	}
	if (y==2) return 3;
	return -2;
}

int z2(int x, int y){
	if (x>0 && y>0) return z3(x, y);
	if (x<0 && y>0) return -z3(-x, y);
	if (x>0 && y<0) return -z3(x, -y);
	return z3(-x, -y);
}	

int main(){
	cin >> tt;
	for (int _t=0 ; _t<tt ; _t++){
		int x, l;
		cin >> x >> l;
		string s;
		cin >> s;
		S = "";
		for (int i=0 ; i<l ; i++)
			S += s;
		int n = x*l;
		int J = 1;
		int c = 1;
		int I = 0;
		while(c!=2 && I<n)
			c = z2(c, a(S[I++]));
		if (c!=2) J = 0;	
		c = 1;
		while(c!=3 && I<n)
			c = z2(c, a(S[I++]));
		if (c!=3) J = 0;
		c = 1;
		while(I<n)
			c = z2(c, a(S[I++]));
		if (c!=4) J = 0;	
		
		cout << "Case #" << _t+1 << ": " << (J?"YES":"NO") << endl;
	}
}
