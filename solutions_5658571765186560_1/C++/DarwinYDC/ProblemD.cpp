#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>

using namespace std;

string winner(int X, int R, int C){
	if (R>C) swap(R, C);
	if ((R*C)%X!=0) return "RICHARD";
	if (X>=7) return "RICHARD";
	if (C<X) return "RICHARD";
	if (R<(X+1)/2) return "RICHARD";
	bool dividable = true;
	if (R<X){
		for (size_t i=1; i<=(X-R); i++){
			bool d = false;
			for (size_t j=0; j<=C-X+R-1; j++){ 
				if ((R*(j+i)-i)%X==0){
					d = true;
					break;
				}
			}
			dividable = dividable && d;
		}
	}
	return dividable?"GABRIEL":"RICHARD";
}

int main(){
	int T;
	cin>>T;
	for (size_t i=0; i<T; i++){
		int R,C,X;
		cin>>X>>R>>C;
		cout<<"Case #"<<i+1<<": "<<winner(X,R,C)<<endl;
	}
}