#include <iostream>
#include <string>
#include <vector>

using namespace std;

int t;

void main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);


	cin>>t;
	for (int i = 0; i<t; i++){
		int r,c,w;
		cin>>r>>c>>w;

		int ans = 0;
		ans+=(c/w)*r;
		ans+=(w-1);
		if (c%w!=0) ans++;

		cout<<"Case #"<<i+1<<": "<<ans<<endl;
	}
}
