#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstdio>
#include<string.h>
#include<set>
using namespace std;

typedef long long Int;
#define FOR(i,a,b)  for(int i=(a);i<=(b);++i)
#define sz(s) (int)(s).size()
#define mp make_pair
#define pb push_back
void assert(bool x){if(!x)throw -1;}
const int inf = 1000000000;
const int MOD = 1000000007;
#define sqr(x) (x)*(x)
const double PI = acos(-1.0);


bool pal(Int n){
	bool ans = true;
	vector<int>a;
	while(n){
		a.pb(n%10);
		n/=10;
	}
	vector<int> b=a;
	reverse(b.begin(),b.end());
	return a==b;
}

/*void check(int n){
	if(!pal(n))return;
	Int s = n*1LL*n;
	if(!pal(s))return;
	cout<<n<<" "<<s<<endl;
}
void doit(){
	for(int i = 1;i<=1000000;++i)check(i);
}*/

/*struct LongInt{
	vector<int> d;
	LongInt(int n = 0){
		d.clear();
		while(n){
			d.pb(n%10);
			n/=10;
		}
		reverse(d.begin(),d.end());
		if(sz(d)==0)d.pb(0);
	}
	bool operator<(const LongInt b)const{
		return sz(d) < sz(b.d) || (sz(d)==sz(b.d) && d<b.d);
	}
	LongInt operator*(const LongInt b)const {
		LongInt ans;
		ans.d.assign(sz(d)+sz(b.d),0);	
	}
};*/

set<Int> good;
int main()
{
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	//freopen("B-small-attempt0.in","r",stdin);freopen("output.txt","w",stdout);
	//freopen("B-large.in","r",stdin);freopen("output.txt","w",stdout);

	for(int i=1;i<=10000000;++i)if(pal(i)){
		Int s = i*1LL*i;
		if(pal(s))good.insert(s);
	}

	cerr<<"done"<<endl;
	int tests;scanf("%d\n",&tests);
	for(int test = 1; test <= tests; ++ test) {
		Int l,r;
		cin>>l>>r;
		int ans=0;
		for(set<Int>::iterator it = good.begin();it!=good.end();++it)
			ans+=bool((*it)>=l && (*it)<=r);
		cout<<"Case #"<<test<<": "<<ans<<endl;
	}
}