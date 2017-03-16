#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
int main(){
	int t,r,c,w,p=1;
	cin>>t;
	
	while(t--){
		cin>>r>>c>>w;
		int ans=(c/w)*(r-1)+max(0,c/w-1);
		if(c%w==0){
			ans+=w;
		}else{
			ans+=w+1;
		}
		
		
		
		cout<<"Case #"<<p<<": "<<ans<<endl; 
		p++;
	}
	
	return 0;
}