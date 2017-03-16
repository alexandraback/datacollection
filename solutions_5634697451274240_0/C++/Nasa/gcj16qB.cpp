#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int t,u,i,x; char s[1000];
	cin>>t; for (u=0; u<t; u++){
		cin>>s; 
		for (i=0; s[i]; i++); s[i++]='+'; s[i]=0; 
		for (x=0,i=1; s[i]; i++) x+=(s[i]!=s[i-1]?1:0); 
		cout<<"Case #"<<(u+1)<<": "<<x<<endl;
	}
	return 0;
}
