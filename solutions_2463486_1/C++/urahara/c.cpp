#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<ctime>
#include<climits>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<complex>
#include<set>
#include<bitset>
#include<utility>
#include<valarray>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<pair<int,int> > vpii;

#define pb push_back
#define mp make_pair
#define PI acos(-1)
#define all(a) (a).begin(),(a).end()
#define len(a) ((int)(a).size())
#define mem(a,n) memset(a,n,sizeof(a))
#define eps 1e-9
#define rep(i,n) for(int i=0;i<(n);i++)
#define repi(i,a,n) for(int i=(a);i<(n);i++)
#define repr(i,a,n) for(int i=(n);i>=(a);i--)

vll v;

bool chk(ll n){
	string s="";
	while(n){
		s.pb(n%10);
		n/=10;
	}
	string t=s;
	reverse(all(t));
	return t==s;
}

void pre(){
	rep(i,10000001){
		if(chk(i) && chk((ll)i*i))v.pb((ll)i*i);
	}
	v.pb(999999999999999LL);
}

int main(void){
	freopen("in2.txt","r",stdin);
	freopen("out2.txt","w",stdout);
	
	ios_base::sync_with_stdio(0);
	pre();
	int t;
	cin>>t;
	rep(k,t){
		ll l,r;
		cin>>l>>r;
		cout<<"Case #"<<k+1<<": "<<int(lower_bound(all(v),r)-lower_bound(all(v),l))+binary_search(all(v),r)<<endl;
	}
	return 0;
}
