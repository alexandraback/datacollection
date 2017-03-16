#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;

ll a[25]={0,0,1,1,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4};

int main(){
	ll z,t,r,c,w;
	
	cin>>t;
	for(z=1;z<=t;z++){
		cin>>r>>c>>w;
		cout<<"Case #"<<z<<": "<<r*(c/w)+w-1+a[c%w+1]<<endl;
	}
	return 0;
}
