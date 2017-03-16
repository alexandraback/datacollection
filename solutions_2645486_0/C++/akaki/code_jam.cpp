#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int i,j,k,l,m,n,t,r,e;

int v[10];

int rec(int pos, int cur_e){

	//cout<<pos<<" aaaaaa       "<<cur_e<<"\n";
	int i;	
	int ans=-1;
	if (cur_e>e) cur_e=e;
	if (pos==n-1) return cur_e*v[pos];
	for (i=0;i<=cur_e;i++){
		ans = max(ans, i*v[pos]+rec(pos+1, cur_e-i+r));
	}
	return ans;
}

int main(){
	freopen("output.txt","w",stdout);
	cin>>t;
	for (i=1;i<=t;i++){
		cin>>e>>r>>n;
		for (j=0;j<n;j++)
			cin>>v[j];
		int ans = rec(0,e);
		cout<<"Case #"<<i<<": "<<ans<<"\n";
	}
	return 0;
}
