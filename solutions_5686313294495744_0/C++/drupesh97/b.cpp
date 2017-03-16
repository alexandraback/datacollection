#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;
ll to(string s){
	ll ans = 0;
	for(int i = 0;i < s.length(); i++){
		ans = ans*10 + (s[i] - '0');
	}
	return ans;
}
void solve(){
	int n;
	cin>>n;
	vector<pair<string,string> > v(n);
	for(int i = 0;i < n; i++){
		cin>>v[i].X>>v[i].Y;
	}
	int i = 1;
	int ans =0;
	while(i<(1<<n)){
		//vector<int> one,two;
		int cnt =0;
		for(int j = 0;j < n; j++){
			if((i&(1<<j)) == 0 ){
				//cout<<i<<endl;
				int f1=0,f2=0;
				for(int l = 0;l < n; l++){
					if(i&(1<<l)){
						if(v[l].X == v[j].X )
							f1 = 1;
						if(v[l].Y == v[j].Y )
							f2 = 1;
					}
				}
				if(f1 && f2)cnt++;
			}
		}
		if(cnt == (n-__builtin_popcount(i)))
			ans = max(ans,cnt);
		i++;
	}
	cout<<ans<<endl;
}
int main(int argc, char const *argv[])
{
	freopen("./input.txt","r",stdin);
	freopen("./output.txt","w",stdout);
	int t;
	cin>>t;
	for(int i = 1;i <=t; i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}	