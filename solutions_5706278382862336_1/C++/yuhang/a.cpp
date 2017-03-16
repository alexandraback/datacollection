#include<iostream>
using namespace std;

long long gcd(long long x,long long y){
	if(x)while((x%=y)&&(y%=x));
	return x+y;
}

int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		long long p,q;char ch;
		cin>>p>>ch>>q;
		long long d=gcd(p,q);
		p/=d;q/=d;
		cout<<"Case #"<<i<<": ";
		if(q!=(q&-q))
			cout<<"impossible"<<endl;
		else{
			while(p){
				p>>=1;
				q>>=1;
			}
			int i=0;
			while(q){
				q>>=1;
				i++;
			}
			cout<<i<<endl;
		}
	}
	return 0;
}
