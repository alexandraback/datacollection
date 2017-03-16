#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long int ll;
vector<ll> num;
bool ispl(ll n,int digit){
	if(digit<1) return true;
	int a=n%10;
	ll hoge=1;
	for(int i=0;i<digit;i++) hoge*=10;
	int b=n/hoge;
	if(a!=b) return false;
	return ispl((n%hoge)/10,digit-2);
}
int main(){
	ll n;
//	cin >> n;
	for(ll i=1;i<=10000000;i++){
		if(!ispl(i,log10(i))) continue;
		if(!ispl(i*i,log10(i*i))) continue;
//		cout << i << " " << i*i << endl;
		num.push_back(i*i);
	}
	int t;
	cin >> t;
	for(int i=1;i<=t;i++){
		ll a,b;
		cin >> a >> b;
		b++;
		cout << "Case #" << i << ": " << lower_bound(num.begin(),num.end(),b)-lower_bound(num.begin(),num.end(),a) << endl;
	}
	return 0;
}