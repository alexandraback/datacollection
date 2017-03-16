#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <cassert>
#include <iomanip>
using namespace std;
static const double EPS = 1e-9;
typedef long long ll;
ll mod=1777777777;

int buf[100000];
void init(){
	for(int i=0;i<100000;i++){
		buf[i]=i*(2*i-1);
	}
}

//ƒ‚ƒWƒ…ƒ‰‹t”
// res * a % m == 1
// a‚Æm‚ÍŒÝ‚¢‚É‘f‚Å‚ ‚é•K—v‚ª‚ ‚é
inline ll mod_inverse(ll a,ll m){
	return pow(a,m-2);
}

//c=n!/(n-m)!m!
ll comb(ll n,ll m){
	ll res=1;
	m=min(m,n-m);
	for(ll i=0;i<m;i++) res = res * ((n-i) % mod) % mod;
	for(ll i=0;i<m;i++) res = res * mod_inverse(i+1,mod) % mod;
	return res;
}

int main() {
	// freopen ("input.txt", "r", stdin);
	// freopen ("output.txt", "w", stdout);

	init();

	int t,n,x,y;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>x>>y;
		x=abs(x);
		int minx=0,maxx=100000-1;
		while(minx+1<maxx){
			int mid=(maxx+minx)/2;
			if(buf[mid]<n)minx=mid;
			else maxx=mid;
		}
		int a=minx;
		int z=n-buf[a];
		if(x+y==0)cout<<"Case #"<<(i+1)<<": 1.0"<<endl;
		else if(x+y<=2*(a-1))cout<<"Case #"<<(i+1)<<": 1.0"<<endl;
		else if(x+y>2*a)cout<<"Case #"<<(i+1)<<": 0.0"<<endl;
		else if(x==0)cout<<"Case #"<<(i+1)<<": 0.0"<<endl;
		else{
			ll sum=0;
			if(y+1>z){
				cout<<"Case #"<<(i+1)<<": 0.0"<<endl;
				continue;
			}
			for(int j=y+1;j<=z;j++){
				sum+=comb(z,j);
			}
			cout << setprecision(10);
			cout<<"Case #"<<(i+1)<<": "<<(double)sum/pow(2.0,z)<<endl;
		}
	}
}