#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;++i)
#define repi(i,a,b) for(int i=a;i<b;++i)
#define F first
#define S second
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define ppp pair<pii,pii>
#define vi vector<int>
#define sc(a) scanf("%d",&a)
#define pb(a) push_back(a)
int main() {
	// your code goes here
	int t,r,c,w;
	cin>>t;
	repi(i,1,t+1)
	{
		cin>>r>>c>>w;
		cout<<"Case #"<<i<<": ";
		if(c%w == 0)
		{
			cout<<(c/w)*r + w - 1;
		}
		else
		{
			cout<<(c/w)*r + w;
		}
		cout<<endl;
	}
	return 0;

}