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
    int N;
    cin>>N;
    map<int,int>m;
    rep(i,0,(2*N-1)*N){
            int temp;
            cin>>temp;
            m[temp]++;
    }
    vector<int>ans;
    for(auto i:m){
        if((i.second)%2==1){ans.pb(i.first);}
    }
    sort(all(ans));
    for(int i:ans)cout<<i<<" ";
    cout<<endl;
}
int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int t;
	cin>>t;
	rep(i,1,t+1)solve(i);
	return 0;
}
