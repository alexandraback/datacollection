#include <iostream>
#include <bits/stdc++.h>

using namespace::std;

int main(){
	long long int t;
	cin>>t;
	long long int k=1;
	while(t){
		t--;
		string s;
		cin>>s;
		long long int counter=0;
		long long int i=0;
		while(i<s.length()){
			if(s[i]=='-'){
				if(i==0){
					counter+=1;
				}else{
					counter+=2;
				}
			}
			while(s[i]=='-'){
				i++;
			}
			i++;
		}
		cout<<"Case #"<<k<<": "<<counter<<endl;
		k++;
	}
	return 0;
}
