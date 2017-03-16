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
		long long int po=pow(x,c);
		cout<<"Case #"<<k<<": ";
		long long int f=1;
		/*if(x!=1)
			if(po%(x-1)==0)
				f=(po/(x-1))-1;
			else
				f=(po/(x-1));*/
		//small
		if(c!=1){
			if(s==x){		
				for(long long int i=1;i<=x;i++){
					cout<<i<<" ";
				}
			}
			//large
			else if(s==x-1){
				for(long long int i=2;i<=x;i++){
					cout<<i<<" ";
				}
			}else{
				cout<<"IMPOSSIBLE";
			}
		}else{
			if(s!=x){
				cout<<"IMPOSSIBLE";	
			}else{
				for(long long int i=1;i<=x;i++){
					cout<<i<<" ";
				}
			}
		}
		cout<<endl;
		k++;
	}
	return 0;
}