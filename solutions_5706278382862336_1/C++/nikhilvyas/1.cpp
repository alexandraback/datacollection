#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib> 
//cout<<"Case #"<<q+1<<": "<<
using namespace std;

long long gcd(long long a,long long b){
	if(a == 0) return b;
	return gcd(b % a,a);
}

bool is(long long q){
	if(q==1) return true;
	if(q%2==1) return false;
	return is(q/2);
}
	

int main(){
	int t;
	cin>>t;
	for(int qq=0;qq<t;qq++){
		long long p,q;
		string a,b;
		getline(cin,a,'/');
		//cout<<a<<endl;
		p=atoll(a.c_str());
		//cout<<p<<endl;
		getline(cin,b);
		q=atoll(b.c_str());
		//cout<<q<<endl;
		long long z=gcd(p,q);
		//cout<<z<<endl;
		p=p/z;
		q=q/z;
		if(!is(q)){
			cout<<"Case #"<<qq+1<<": Impossible"<<endl;
			continue;
		}
		double ww=q;
		double sa=p;
		double d =ww/sa;
		//cout<<d<<endl;
		long long r;
		long long h=2;
		for(r=1;;r++){
			if(h>=d) break;
			h=h*2;
		}
		cout<<"Case #"<<qq+1<<": "<<r<<endl;
	}
}
