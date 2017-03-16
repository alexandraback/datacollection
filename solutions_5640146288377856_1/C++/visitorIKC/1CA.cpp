#include <iostream>

using namespace std;
int main(){
	int tc;cin>>tc;
	int i=0;
	while(tc-->0){
		i++;
		int r,c,w;cin>>r>>c>>w;
		int ans=1;
		int st=w;
		while(st+w<=c){
			st+=w;
			ans++;
		}
		ans*=(r);
		ans+=1;
		ans+=w-1;
		if(c%w==0)ans--;
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
	return 0;
}
