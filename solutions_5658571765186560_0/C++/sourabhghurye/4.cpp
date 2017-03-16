#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main(){
	int t;cin>>t;
	for(int qq=1;qq<=t;qq++){
		int x,r,c; cin>>x>>r>>c;
		bool ans=0;
		
		if(x==1) ans=true;
		
		if(r<c) { int t=r;r=c;c=t; }
		
		if(r==4 && (c==1 && x==2 || c==2 && x==2 || c==3 || c==4 && x!=3) ) ans=1;
		if(r==3 && (c==2 && x!=4 || c==3 && x==3 ) ) ans=1;
		if(r==2 && x==2 ) ans=1;
		
		if(ans) cout<<"Case #"<<qq<<": GABRIEL"<<endl;
		else cout<<"Case #"<<qq<<": RICHARD"<<endl;
	}
}
