#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define F first
#define S second
map<int ,int > cnt;
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	rep(tc,t){
		int n;
		cnt.clear();
		vector<int>v;
		cin>>n;
		rep(i,2*n-1){
			rep(j,n){
				int x;
				cin>>x;
				cnt[x]++;
			}
		}
		for(auto i:cnt){
			if(i.S%2){
				v.pb(i.F);
			}
		}
          sort(v.begin(), v.end());
		cout<<"Case #"<<tc+1<<": ";
		for(auto i:v)cout<<i<<" ";cout<<"\n";
	}

	return 0;
}
