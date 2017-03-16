#include<bits/stdc++.h>

using namespace std;

inline long long int gi(){
	long long int ret = 0;
	char ch = ' ';
	while(ch < '0' || ch > '9'){
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		ret *= 10;
		ret += ch - '0';
		ch = getchar();
	}
	return ret;
}

inline long long int gcd(long long int a, long long int b){
	if(a < b){
		return gcd(b, a);
	}
	if(b == 0){
		return a;
	}
	else{
		return gcd(b, a % b);
	}
}

inline void solve(){
	long long int p, q, g, a, c;
	p = gi();
	q = gi();
	g = gcd(p, q);
	p /= g;
	q /= g;
	a = q;
	while(a > 1){
		if(a & 1){
			break;
		}
		a /= 2;
	}
	//cout<<a<<endl;
	if(a != 1){
		cout<<"impossible"<<endl;
	}
	else{
		c = 1;
		while(p < q / 2){
			q /= 2;
			c++;
		}
		cout<<c<<endl;
	}
}

int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	long long int t, i = 0;
	t = gi();
	while(t--){
		i++;
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
