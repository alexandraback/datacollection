#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cctype>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <complex>
#include <numeric>
#include <valarray>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

#define inf 1061109567
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define mem(x,a) memset(x,a,sizeof(x))
#define rep(i,n) for(int i(0),_n(n);i<_n;++i)
#define repi(i,a,b) for(int i(a),_b(b);i<_b;++i)
#define repe(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define len(x) ((int)(x.size()))


string tostr(long long  a){if(a==0) return "0";string ret;for(long long  i=a; i>0; i=i/10) ret.push_back((i%10)+48);reverse(ret.begin(),ret.end());return ret;}


void fun(ll n){
	
	string s=tostr(n);
	string t=s;
	
	reverse(all(t));
	
	if(t!=s)return;
	
	n=n*n;
	
	s=tostr(n);
	t=s;
	
	reverse(all(t));
	
	if(t!=s)return;
	
	cout<<s<<" ,";
	
}


ll arr[]={0 ,1 ,4 ,9 ,121 ,484 ,10201 ,12321 ,14641 ,40804 ,44944 ,1002001 ,1234321 ,4008004 ,100020001 ,102030201 ,104060401 ,121242121 ,123454321 ,125686521 ,400080004 ,404090404 ,10000200001 ,10221412201 ,12102420121 ,12345654321 ,40000800004 ,1000002000001 ,1002003002001 ,1004006004001 ,1020304030201 ,1022325232201 ,1024348434201 ,1210024200121 ,1212225222121 ,1214428244121 ,1232346432321 ,1234567654321 ,4000008000004 ,4004009004004 ,100000020000001};

ll n,t1;


int main(){
	ios_base::sync_with_stdio(0);
	
	//freopen("list", "w", stdout);
	
	freopen("in", "r", stdin);
	
	freopen("out", "w", stdout);
	
	
	//rep(i,10000011)fun(i);
	
	
	vi v(arr,arr+sizeof(arr)/sizeof(ll));
	
	int tests;
	cin>>tests;
	for(int t=1;t<=tests;t++){
		cout<<"Case #"<<t<<": ";
		
		cin>>t1>>n;
		t1--;
		cout<<(upper_bound(all(v),n)-v.begin())-(upper_bound(all(v),t1)-v.begin())<<endl;
		
	}
	
	
	
}









