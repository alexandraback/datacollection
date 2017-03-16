#include <iostream>
#include <bits/stdc++.h>

using namespace::std;

int main(){
	long long int t;
	cin>>t;
	long long int k=1;
	while(t){
		t--;
		long long int n;
		cin>>n;
		int dig[10]={0};
		int count=0;
		long long int fac;
		if(n==0){
			cout<<"Case #"<<k<<": "<<"INSOMNIA"<<endl;
			k++;
			continue;
		}else{
			fac=1;
			while(count!=10){
				long long int name=n*fac;
				while(name>0){
					long long int d=name%10;
					name=name/10;
					if(dig[d]==0){
						//cout<<d<<endl;
						dig[d]=1;
						count++;
					}
				}
				fac++;
			}
		}
		cout<<"Case #"<<k<<": "<<n*(fac-1)<<endl;
		k++;
	}
	return 0;
}
