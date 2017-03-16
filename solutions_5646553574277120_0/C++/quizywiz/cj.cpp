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
int a[100];
int main() {
	// your code goes here
	int t,c,d,v;
	cin>>t;
	repi(i,1,t+1)
	{
		cin>>c>>d>>v;
		repi(j,0,d)cin>>a[j];

		int cur = 0;
		int add = 0;
		int j = 0;
		while(cur<v)
		{
			if(j<d && cur>=a[j]-1){cur+=a[j];++j;}
			else
			{
				++add;
				cur += cur+1;
			}
		}
		cout<<"Case #"<<i<<": ";
		cout<<add;
		cout<<endl;
	}
	return 0;

}