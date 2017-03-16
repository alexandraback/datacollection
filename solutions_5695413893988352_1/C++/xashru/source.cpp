#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <fstream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <numeric>
#include <ratio>
#include <regex>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <valarray>

using namespace std;

#define sz(v) (int)v.size()
#define eps 1e-10
#define all(v) v.begin(), v.end() 
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define chk(a,k) ((bool)(a&(1<<(k))))
#define set0(a,k) (a&(~(1<<(k))))
#define set1(a,k) (a|(1<<(k)))
#define in(v, x) (find(all(v),x) != v.end()) 
#define re return
#define sum(v) accumulate(v.begin(),v.end(),(ld)0)
#define tr(v,it) for(auto it=v.begin();it != v.end();it++)
#define asrt(v) sort(v.begin(),v.end())
#define dsrt(v) sort(v.rbegin(),v.rend())
#define rev(v) reverse(v.begin(),v.end())
#define pi 3.1415926535897932384626433832795
#define MOD 1000000007
#define print(v) for (auto& i:v) cout<<i<<endl 
#define endl '\n'

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<string> vs;
typedef vector<vi> vvi;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<string> vs;
typedef vector<vi> vvi;

#define print "Case #"+to_string(t1)+": " 

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;

struct node{
	ll p, q;
};

bool operator<(node a, node b) {
	ll d1=abs(a.p-a.q), d2=abs(b.p-b.q);
	if(d1<d2) re 1;
	if(d1>d2) re 0;
	if(a.p<b.p) re 1;
	if(a.p>b.p) re 0;
	if(a.q<b.q) re 1;
	re 0;
}

node foo(string &x, string &y, ll pos, ll a, ll b) {

	if(pos==sz(x)) {
		re {a, b};
	}


	if(x[pos]=='?' && y[pos]=='?') {


		if(a<b) {
			a=a*10LL+9LL, b=b*10LL+0;
			re foo(x, y, pos+1, a, b);
		} else if(a>b) {
			a=a*10LL+0, b=b*10LL+9LL;
			re foo(x, y, pos+1, a, b);
		} else{

			vector<node> v;

			for(ll d1=0; d1<=1; d1++) {
				for(ll d2=0; d2<=1; d2++) {
					if(d1+d2==2) continue;
					node n=foo(x, y, pos+1, a*10LL+d1, b*10LL+d2);
					v.push_back(n);
				}
			}

			asrt(v);
			re v[0];
		}


	} else if(x[pos]!='?' && y[pos]!='?') {
		ll da=x[pos]-'0', db=y[pos]-'0';
		a=a*10LL+da, b=b*10LL+db;
		re foo(x, y, pos+1, a, b);
	} else if(x[pos]=='?' && y[pos]!='?') {
		ll db=y[pos]-'0';
		if(a<b) {
			a=a*10LL+9, b=b*10LL+db;
			re foo(x, y, pos+1, a, b);
		} else if(a>b) {
			a=a*10LL+0, b=b*10LL+db;
			re foo(x, y, pos+1, a, b);
		} else{


			vector<node> v;

			for(ll d1=0; d1<=9; d1++) {
				node n=foo(x, y, pos+1, a*10LL+d1, b*10LL+db);
				v.push_back(n);
			}

			asrt(v);
			re v[0];

		}
	} else if(x[pos]!='?' && y[pos]=='?') {



		ll da=x[pos]-'0';
		if(a<b) {
			a=a*10LL+da, b=b*10LL+0;
			re foo(x, y, pos+1, a, b);
		} else if(a>b) {
			a=a*10LL+da, b=b*10LL+9LL;
			re foo(x, y, pos+1, a, b);
		} else{
	
			vector<node> v;

			for(ll d2=0; d2<=9; d2++) {
				node n=foo(x, y, pos+1, a*10LL+da, b*10LL+d2);
				v.push_back(n);
			}

			asrt(v);
			re v[0];

		}

	}

}

void foo(string x, string y, int t1) {
	node res=foo(x, y, 0, 0, 0);
	cout<<print;
	string a=to_string(res.p), b=to_string(res.q);
	while(sz(a)!=sz(x)) {
		string s="0";
		s+=a;
		a=s;
	}

	while(sz(b)!=sz(x)) {
		string s="0";
		s+=b;
		b=s;
	}
	cout<<a<<" "<<b<<endl;
}

int main() {
	freopen("Data/in.txt", "r", stdin);
	freopen("Data/out.txt", "w", stdout);
	int T;
	cin>>T;
	for(int t1=1; t1<=T; t1++) {
		string x, y;
		cin>>x>>y;
		foo(x, y, t1);
	}
	getchar();
	return 0;
}
