#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define MP make_pair
#define PB push_back
typedef long long ll;
int main(){
	int r,c,t,w;
	cin>>t;
	for(int times=1;times<=t;times++){
		cin>>r>>c>>w;
		int ans=0;
		for(int i=w;i<=c;i+=w){
			ans+=r;
		}
		ans+=w;
		if(c%w==0)ans--;
		cout<<"Case #"<<times<<": "<<ans<<endl;
	}
}
