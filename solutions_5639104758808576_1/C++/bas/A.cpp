#include<iostream>
#include<vector>
#include<string>

using namespace std;
	int C, ms;
	string s;
int main(){
	
	cin>>C; 
	for(int j=0; j<C; j++){
		cin>>ms;
		cin>>s;
		int sum = 0; int res=0;
		for(int i=0; i<=ms; i++){
		    if(s[i]!='0'){
			if (sum<i){
			    res+=i-sum; sum=i;
			}
		    }
		    sum+=s[i]-'0';
		}
		cout<<"Case #"<<j+1<<": "<<res<<"\n" ;
	}
	
}
