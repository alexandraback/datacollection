#include <iostream>
#include <bits/stdc++.h>

using namespace::std;

int main(){
	long long int t;
	cin>>t;
	long long int k=1;
	while(t){
		t--;
		long long int x,c,s;
		cin>>x>>c>>s;
		//long long int po=pow(x,c);
		cout<<"Case #"<<k<<": ";
		long long int f=1;
		/*if(x!=1)
			if(po%(x-1)==0)
				f=(po/(x-1))-1;
			else
				f=(po/(x-1));*/
		for(long long int i=1;i<=x;i=i+1){
			cout<<i<<" ";
		}
		cout<<endl;
		k++;
	}
	return 0;
}