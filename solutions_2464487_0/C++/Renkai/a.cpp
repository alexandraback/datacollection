#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<algorithm>
#include <cstdlib>
using namespace std;
#define ll long long
const double eps=1e-8;
int T;
ll r;
ll t;
double erfen(ll rad,ll cap){
	double l=0,r=cap;
	while(r-l>eps){
		double mid=(r+l)/2;
		if(	((2*rad+1)*mid+(2*mid-2)*mid)>cap ){
			r=mid;
		}else l=mid;
	}
	return l;
}
int main(){
#ifdef LOCAL
	freopen("a.txt","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin>>T;
	int cc=1;
	while(T>=cc){
		cin>>r>>t;
		double tans=erfen(r,t);
		ll ans=max(0.20,tans-5);
		//cout<<"ans "<<ans<<endl;
		ll tt=ans+1;
		while((r*2+1)*tt+(2*tt-2)*tt<=t && ((r*2+1)*tt+(2*tt-2)*tt)>0 ){
			ans=tt;
			tt++;
			//cout<<tt<<endl;
			//cout<<(r*2+1)*tt+(2*tt-2)*tt<<" "<<t<<endl;
		}
		cout<<"Case #"<<cc++<<": "<<ans<<endl;
	}
}
