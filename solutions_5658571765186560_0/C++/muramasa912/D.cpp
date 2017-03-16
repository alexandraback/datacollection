#include <bits/stdc++.h>

using namespace std;
int x,r,c;
void solve(){
	if(x>=7) {cout << "RICHARD" << endl;return;}
	else if(r*c%x) {cout << "RICHARD" << endl;return;}
	else if(r<x && c < x ) {cout << "RICHARD" << endl;return;}
	else if( ((x+1)/2)>min(r,c)) {cout << "RICHARD" << endl;return;}

	if(x==6||x==4){
		if(min(r,c)>(x/2)) {cout << "GABRIEL" << endl;}
		else cout << "RICHARD" << endl; 
		return; 
	}

	else if(x==5){
		if(min(r,c)==3 && max(r,c)==5) cout << "RICHARD" << endl;
		else cout << "GABRIEL" << endl;
		return;
	}
	else if(x<=3){
		cout << "GABRIEL" << endl;
		return;
	}

}

int main(){
	
	int test;
	cin >> test;
	for(int ti=1;ti<=test;++ti){

		cin >> x >> r >> c;
		 printf("Case #%d: ",ti);
		solve();
	}
	return 0;
}