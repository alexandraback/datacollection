#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vvi vector<vi>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define all(a) a.begin(),a.end()
#define sum(a) accumulate(all(a),0)
#define endl '\n'
#define hell 1000000007
#define pii pair<int,int>

using namespace std;
template <class X>
void input(vector<X>&a,int N){
    X temp;
    rep(i,0,N){
        cin>>temp;
        a.push_back(temp);
    }
}
void solve(int t){
    cout<<"Case #"<<t<<": ";
    string s;
    cin>>s;
    vector<char>ans;
    ans.pb(s[0]);
    rep(i,1,s.length()){
        if(s[i]>=ans[0])ans.insert(ans.begin(),s[i]);
        else ans.pb(s[i]);
    }
    for(char i:ans)cout<<i;
    cout<<endl;
}
int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int t;
	cin>>t;
	rep(i,1,t+1)solve(i);
	return 0;
}
