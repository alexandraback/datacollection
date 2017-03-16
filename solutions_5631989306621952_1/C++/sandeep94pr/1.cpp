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
	int t ;cin>>t;
	fr(k,1,t)
	{
		string s;
		cin>>s;
		int n=s.size();
		string a,b;
		a+=s[0];
		int st=0,ed=-1;
		fr(i,1,n-1)
		{
			if(s[i]>=a[st])a+=s[i],st++;
			else b+=s[i],ed++;
		}
		reverse(a.begin(),a.end());
		cout<<"Case #"<<k<<": "<<a<<b<<endl;

	}
	return 0;
}