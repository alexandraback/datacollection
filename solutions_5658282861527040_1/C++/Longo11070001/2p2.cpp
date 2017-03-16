#include <iostream>
using namespace std;
long long solve();
int main(){
	int T,i;
	cin>>T;
	for(i=1;i<=T;i++)
		cout<<"Case #"<<i<<": "<<solve()<<endl;
	return 0;
}
long long solve(){
	long long a,b,k,ans,i,j;
	cin>>a>>b>>k;
	if(a<k||b<k) return a*b;
	ans=a*k+b*k-k*k;
	for(i=k;i<a;i++)
		for(j=k;j<b;j++)
			if((i&j)<k) ans++;
	return ans;
}
