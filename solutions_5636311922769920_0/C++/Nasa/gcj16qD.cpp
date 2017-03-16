#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
	int K,C,S,t,u,i,j; ll x;
	cin>>t; for (u=0; u<t; u++){
		cin>>K>>C>>S;
		cout<<"Case #"<<(u+1)<<": ";
		if (S<(K+C-1)/C) cout<<"IMPOSSIBLE"<<endl;
		for (i=j=0, x=0; i<K || (j && j<C); i++){ 
			x=x*K+(i>=K?0:i); 
			j++; 
			if (j==C){
				cout<<" "<<(x+1);
				x=0;
				j=0;
			}
		}
		cout<<endl;
	}
	return 0;
}
