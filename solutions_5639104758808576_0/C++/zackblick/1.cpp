#include<iostream>

using namespace std;

int main() {
	int t;
	
	cin >> t;
	
  	for(int k=1;k<=t;k++) {
  	
  		int n;
  		
  		cin >> n;
  		
  		string s;
  		cin >> s;
  		
  		long long int ctr = 0,ans=0;
  		
  		for(int i=0;i<n+1;i++) {
  			if(ctr < i) {
				ans+=i-ctr;
				ctr=i;
			}
  			ctr += s[i]-'0';
  		}
  			
  		cout<<"Case #"<<k<<": "<<ans<<endl;
  	}
  	
  	return 0;
}