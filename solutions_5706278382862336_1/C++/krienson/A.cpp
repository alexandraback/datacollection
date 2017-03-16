#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<utility>

using namespace std;

#define PB push_back
#define LE length()
#define SZ size()
#define MP make_pair
#define X first
#define Y second



long long gcd(long long a, long long b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

bool isPowerOf2(long long q){
	int c = 0;
	while(q){
		c += (q&1); q>>=1;
	}
	return c==1;
}

int calc(long long p, long long q){
	//cout<<p<<" "<<q<<endl;
	int res = 1;
	while(2*p < q){ q/=2; res++;}
	return res;
}

int main(){
	int kases; cin>>kases;
	char c;
	for(int kase = 1; kase <= kases;kase++){
		long long P, Q; cin>>P>>c>>Q;
		long long g = gcd(P,Q);
		P/=g; Q/=g;
		if(!isPowerOf2(Q) || calc(P,Q) > 40) cout<<"Case #"<<kase<<": impossible"<<endl;
		else cout<<"Case #"<<kase<<": "<<calc(P,Q)<<endl;
	}
}
