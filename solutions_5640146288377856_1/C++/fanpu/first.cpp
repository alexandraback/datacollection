#include<bits/stdc++.h>
using namespace std;
int main(){
	
	ifstream cin;
	cin.open("alarge.in");
	ofstream cout;
	cout.open("alarge.o");
	
	int tc; cin >> tc;
	for(int a = 1; a <= tc; a++){
		int r,c,w; cin >> r >> c >> w;
		int hitColOrig = c/w;
		int hitMoved;
		if(c != w && c%w != 0) hitMoved = 1;
		else hitMoved = 0;
		int hitRemaining = w - 1;
		int multRows = (hitColOrig + hitMoved) * r;
		multRows += hitRemaining;
		/*
		cout << "Hitcolorig is " << hitColOrig << endl;
		cout << "hitmoved is " << hitMoved << endl;
		cout << "hitremaining is " << hitRemaining << endl;
		*/
		cout << "Case #" << a << ": " << multRows << "\n";
	}
}
