#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define f first
#define s second
#define mod 1000000007
#define inf 1e8

#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define f first
#define mp make_pair
#define s second
#define rep(i,n) for(int i=0;i<n;i++)
#define M 360360
double a,b;
int calc(double e){
	int r=a/e;
	int l=b/=e;
	return l+r;
}
int main(){
freopen("C-small-1-attempt0.in","r",stdin);
freopen("output.txt","w",stdout);
int t;
cin>>t;
int cnt=0;
while(t--){
cnt++;
int n,d,h,m;
cin>>n;
vector<pi>v;
rep(i,n){
	cin>>d>>h>>m;
	if(h==1){
		v.pb({d,m});
	}
	else if(h==1){
		v.pb({d,m});
		v.pb({d,m+1});
	}
}
// case 1
cout<<"Case #"<<cnt<<": "<<1<<"\n";
}
}
