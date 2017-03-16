// By Aman Jain(jainaman224)
// 16/4/16

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	string ans,inp;
	char fir;
	int i,t,j;
	cin >> t;
	for(i=1;i<=t;i++){
		cin >> inp;
		if(inp=="\n" || inp == "\0")
			cin >> inp;
		//cout << inp;
		ans="";
		fir = inp[0];
		for(j=0;j<inp.length();j++){
			if(inp[j]>=fir){
				ans=inp[j]+ans;
				fir=inp[j];
			}
			else{
				ans=ans+inp[j];
			}
		}
		cout << "Case #" << i << ": " << ans << endl;
	}
	return 0;
}