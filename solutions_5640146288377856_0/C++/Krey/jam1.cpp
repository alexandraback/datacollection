#include<bits/stdc++.h>
#define ft first
#define sd second
#define mp make_pair
#define pb push_back
using namespace std;

typedef long long ll;
const ll N = 1001000 , INF = 1e9;

int t,r,c,w,wyn;

int main(){
	cin>>t;
	for(int test=1;test<=t;test++){
		cin>>r>>c>>w;
		wyn=(r-1)*(c/w);
		wyn+=(c/w)+w-(c%w==0);
		cout<<"Case #"<<test<<": "<<wyn<<"\n";
	}
}
