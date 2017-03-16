#include <iostream>
using namespace std;
int solve();
int main(){
	int T,i;
	cin>>T;
	for(i=1;i<=T;i++)
		cout<<"Case #"<<i<<": "<<solve()<<endl;
	return 0;
}
int solve(){
	int a,b,k,ans,i,j;
	cin>>a>>b>>k;
	ans=0;
	for(i=0;i<a;i++)
		for(j=0;j<b;j++)
			if((i&j)<k) ans++;
	return ans;
}
