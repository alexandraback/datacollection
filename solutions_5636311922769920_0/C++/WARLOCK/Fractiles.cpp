#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D.txt","w",stdout);
	int t,k,c,s;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>k>>c>>s;
		cout<<"Case #"<<i<<": ";
		if(s==k){
			for(int j=1;j<=s;j++)
				cout<<j<<" ";
			cout<<"\n";
		}
	}
	return 0;
}