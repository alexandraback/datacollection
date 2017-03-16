#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int T,x,r,c;
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>x>>r>>c;
		if(c<r) swap(r,c);
		cout<<"Case #"<<t<<": "<<
			(x>=7||r==2&&x>=4||r==3&&x>=6||x>=r+r+1||r*c%x?
			 "RICHARD":"GABRIEL")<<'\n';
	}
}
