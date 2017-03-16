#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	for(int t=0;t<T;t++){
		string st;
		cin>>st;
		string result = "a";
		result[0] = st[0];
		for(int i=1;i<st.length();i++){
			if(st[i]>=result[0]){
				result = st[i] + result;
			} else{
				result.push_back(st[i]);
			}
		}
		cout<<"Case #"<<t+1<<": "<<result<<endl;
		
	}
	
	return 0;
}