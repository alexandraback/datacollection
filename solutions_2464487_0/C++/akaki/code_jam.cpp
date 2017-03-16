#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

long long i,j,k,l,m,n,t,r,init;

int main(){
	freopen("output.txt","w",stdout);
	cin>>t;
	for (i=1;i<=t;i++){
		cin>>r>>init;
		int ans = 0;
		while(init>0){
			init-=(2*r+1);
			if (init>=0) ans++;
			r+=2;
		}
		cout<<"Case #"<<i<<": "<<ans<<"\n";
	}
	return 0;
}
