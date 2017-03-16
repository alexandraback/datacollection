#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define repb(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
#define int long long
#define fi first
#define se second
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

signed main(){
	int t;
	cin>>t;
	rep(x,0,t){
		int j,p,s,k;
		cin>>j>>p>>s>>k;
		vi ans;
		int jp[100]={},ps[100]={},js[100]={};
		rep(a,0,j){
			rep(b,0,p){
				rep(c,0,s){
					if((a+b)%2==0 && c==2) continue;
					if((a+b)%2 && c==0) continue;
					if(jp[a*10+b]<k && ps[10*b+c]<k && js[a*10+c]<k){
						ans.push_back(100*a+10*b+c);
						jp[a*10+b]++; ps[10*b+c]++; js[10*a+c]++;
					}
				}
			}
		}
		cout<<"Case #"<<x+1<<": "<<ans.size()<<endl;
		rep(i,0,ans.size()){
			cout<<ans[i]/100+1<<" "<<(ans[i]%100)/10+1<<" "<<ans[i]%10+1<<endl;
		}
	}
}