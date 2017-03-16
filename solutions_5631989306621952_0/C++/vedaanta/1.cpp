#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int
#define pb push_back
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%I64d",&x)
#define F first
#define S second
#define maxn 100005
#define mod 1000000007

int main(){

	int t;
	cin>>t;
	rep(tc,t){
		cout<<"Case #"<<tc+1<<": ";
		string s;
		cin>>s;
		string a="a";
		a[0]=s[0];
		rep(i,s.size()){
			if(i){
				if(s[i]>=a[0])a=s[i]+a;
				else a=a+s[i];
			}
		}
		cout<<a<<"\n";
	}
	

	return 0;
}

// cout<<"Case #"<<tc+1<<": ";