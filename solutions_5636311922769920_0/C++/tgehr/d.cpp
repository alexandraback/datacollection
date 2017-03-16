#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(int k,int c,int s){
	for(int i=1;i<=k;i++)
		cout<<i<<(i==k?"\n":" ");
}

main(){
	int T;
	cin>>T;
	for(int t=1,k,c,s;t<=T;t++){
		cin>>k>>c>>s;
		cout<<"Case #"<<t<<": ";
		solve(k,c,s);
	}
}


