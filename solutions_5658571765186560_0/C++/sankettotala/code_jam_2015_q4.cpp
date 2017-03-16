#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
//#define debug 1

int main(){
	int t;
	cin>>t;
	for(int iiii = 1; iiii<=t; iiii++){
		int x, r, c;
		cin>>x>>r>>c;
		bool ans = true;
		if(x == 1) ans = true;
		else if(x == 2){
			if((r>=2 || c>=2) && (r*c%2 == 0)) ans = true;
			else ans = false;
		}
		else if(x == 3){
			if(((r>=3 && c>=2) || (r>=2 && c>=3)) && (r*c%3 == 0)) ans = true;
			else ans = false;
		}
		else if(x == 4){
			if(((r>=3 && c>=4) || (r>=4 && c>=3)) && (r*c%4 == 0)) ans = true;
			else ans = false;
		}
		else if(x == 5){
			if(((r>=5 && c>=4) || (r>=4 && c>=5)) && (r*c%5 == 0)) ans = true;
			else ans = false;
		}
		else if(x == 6){
			if(((r>=6 && c>=4) || (r>=4 && c>=6)) && (r*c%6 == 0)) ans = true;
			else ans = false;
		}
		else ans = false;
		if(ans) cout<<"Case #"<<iiii<<": GABRIEL"<<endl;
		else cout<<"Case #"<<iiii<<": RICHARD"<<endl;
	}
}
