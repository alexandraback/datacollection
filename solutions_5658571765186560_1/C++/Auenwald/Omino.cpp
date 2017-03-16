#include <iostream>
#include <string>

using namespace std;

bool check(int X, int R, int C){
	if(X>=7)
		return false;
	if(X>=2*R+1)
		return false;
	if(X>=2*C+1)
		return false;
	if((X>R) && (X>C))
		return false;
	if(R*C % X == 0){
		if((R>=4) && (C>=4))
			return true;
		if((R==1) || (C==1))
			return true;
		if((R==2) || (C==2)){
			if((X==1) || (X==2) || (X==3))
				return true;
		}
		if((R==3) || (C==3)){
			if((X==1) || (X==2) || (X==3) || (X==4) || (X==5))
				return true;
		}
	}
	return false;
}

int main(){
	int T;
	cin>>T;
	for(int i=1; i<=T; i++){
		int x,r,c;
		cin>>x>>r>>c;
		cout<<"Case #"<<i<<": ";
		if(check(x,r,c))
			cout<<"GABRIEL";
		else
			cout<<"RICHARD";
		if(i!=T)
			cout<<"\n";
	}
}