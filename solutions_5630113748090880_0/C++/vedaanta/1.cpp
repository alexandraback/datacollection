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
int cnt[2501];
int main(){

	int t;
	cin>>t;
	rep(tc,t){
		cout<<"Case #"<<tc+1<<": ";
		int n;
		set<int>s;
		memset(cnt,0,sizeof cnt);
		cin>>n;
		rep(i,2*n-1){
			rep(j,n){
				int x;
				cin>>x;
				cnt[x]++;
			}
		}
		for(int i=1;i<=2500;i++){
			if(cnt[i]%2){
				s.insert(i);
			}
		}
		for(auto i:s)cout<<i<<" ";cout<<"\n";
	}
	

	return 0;
}

// cout<<"Case #"<<tc+1<<": ";