#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("out.txt","w",stdout);
	int t;
	cin>>t;
	for(int T=1;T<=t;T++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		int ans=(a-1)*(b/c);
		ans+=b/c -1 +((b%c==0)?c:c+1); 
		cout<<"Case #"<<T<<": "<<ans<<endl;
	}
	return 0;
}