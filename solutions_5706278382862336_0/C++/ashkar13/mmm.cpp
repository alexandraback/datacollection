#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
long long gcd ( long long  a, long long b )
{
  long long c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}
int main(){
	int T; cin>>T;
	for(int i=0;i<T;++i){
		string s,s1,s2;
		cin>>s;
		auto pos=s.find("/");
		s1=s.substr(pos+1);
		s2=s.substr(0,pos-0);

		long long P=stoll(s2);
		long long Q=stoll(s1);
		long long g=gcd(P,Q);
		long long p=P/g;
		long long q=Q/g;
		int gen=0;
		bool possible=true;
		while(q>1){
			if(q%2) possible=false;
		q/=2; ++gen;
		}
while(p>1){
	p/=2; --gen;
}

		if(possible)
		cout<<"Case #"<<i+1<<": "<<gen<<endl;
		else cout<<"Case #"<<i+1<<": impossible"<<endl;
	}

	return 0;
}
