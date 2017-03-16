//C
#include <iostream>
#include <vector>
using namespace std;
int main(){	
	int t,t1;	
	cin>>t;
	t1=t;
	while(t--){
		int r,c,w;
		cin>>r>>c>>w;
		cout<<"Case #"<<t1-t<<": "<<(c/w*r+(c%w?w:w-1))<<endl;
	}
	return 0;
}
