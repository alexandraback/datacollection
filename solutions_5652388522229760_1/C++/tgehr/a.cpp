#include <bits/stdc++.h>
using namespace std;

void solve(int x){
	if(!x){
		cout<<"INSOMNIA\n";
		return;
	}
	bool dig[10]={0};
	bool done=false;
	int k=0;
	while(!done){
		k+=x;
		for(int y=k;y;y/=10)
			dig[y%10]=true;
		done=true;
		for(int i=0;i<10;i++)
			done&=dig[i];
	}
	cout<<k<<'\n';
}

int main(){
	int T;
	cin>>T;
	for(int t=1,x;t<=T;t++){
		cin>>x;
		cout<<"Case #"<<t<<": ";
		solve(x);
	}
}
