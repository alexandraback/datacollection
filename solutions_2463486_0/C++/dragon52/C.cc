#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<sstream>
using namespace std;

typedef long long ll;

int maxn = 35;

bool check(ll n){
	stringstream ss;
	ss << n ;
	string s;
	ss >> s;
	bool flag = true;
	for(int i =0 ; i < s.size()/2; i++){
		if(s[i] != s[s.size()-1-i]){
			flag = false;
			break;
		}
	}
	return flag;
}


int main(){
	vector<ll> v;
	for(int i = 1; i < maxn ; i++){
		ll x = i;
		if(check(i) and check(x*x))
			v.push_back(x*x);
	}
	//for(int i =0 ; i < v.size() ; i++) cout << v[i] << endl;
	int t;
	ll a,b;
	scanf("%d",&t);
	for(int cs =1 ; cs <=t ; cs++){
		scanf("%lld%lld",&a,&b);
		int y =upper_bound(v.begin(),v.end(),b) - v.begin();
		int z = upper_bound(v.begin(),v.end(),a-1) - v.begin();
		//cout << y << ' ' << z << endl;
		printf("Case #%d: %d\n",cs,y-z);
	}
}