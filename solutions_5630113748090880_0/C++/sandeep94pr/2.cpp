#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define _ ios::sync_with_stdio(false);
#define mem(x,a) memset(x,(a),(int)(sizeof(x)))
#define pii pair<int,int>
#define fr(i,a,n) for(int i=(a);i<=(n);i++)
#define frd(i,a,n) for(int i=(a);i>=(n);i--)
#define nl printf("\n")
#define pb push_back
#define mp make_pair 
#define F first 
#define S second
#define V vector
ll mod=1e9+7;
int main() {_
	int t;cin>>t;
	fr(k,1,t)
	{
		int n,x;
		map<int,int> m;
		cin>>n;
		//cout<<n<<endl;
		//cout<<((2*n)-1)<<endl;
		fr(j,1,((2*n) -1))fr(i,1,n)cin>>x,m[x]++;
		V<int> v;
		for(auto i:m)
		{
			if(i.S%2==1)v.pb(i.F);
		}
		cout<<"Case #"<<k<<": ";
		for(auto i:v)cout<<i<<" ";
		cout<<endl;
	}
	return 0;
}