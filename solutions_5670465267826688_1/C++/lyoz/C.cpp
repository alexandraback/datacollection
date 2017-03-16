#include <bits/stdc++.h>
using namespace std;

#define dump(...) cout<<"# "<<#__VA_ARGS__<<'='<<(__VA_ARGS__)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define peri(i,a,b) for(int i=int(b);i-->int(a);)
#define rep(i,n) repi(i,0,n)
#define per(i,n) peri(i,0,n)
#define all(c) begin(c),end(c)
#define mp make_pair
#define mt make_tuple

using uint=unsigned int;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using vd=vector<double>;
using vvd=vector<vd>;
using vs=vector<string>;

template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& p){
	return os<<'('<<p.first<<','<<p.second<<')';
}

template<typename Tuple>
void print_tuple(ostream&,const Tuple&){}
template<typename Car,typename... Cdr,typename Tuple>
void print_tuple(ostream& os,const Tuple& t){
	print_tuple<Cdr...>(os,t);
	os<<(sizeof...(Cdr)?",":"")<<get<sizeof...(Cdr)>(t);
}
template<typename... Args>
ostream& operator<<(ostream& os,const tuple<Args...>& t){
	print_tuple<Args...>(os<<'(',t);
	return os<<')';
}

template<typename Ch,typename Tr,typename C>
basic_ostream<Ch,Tr>& operator<<(basic_ostream<Ch,Tr>& os,const C& c){
	os<<'[';
	for(auto i=begin(c);i!=end(c);++i)
		os<<(i==begin(c)?"":" ")<<*i;
	return os<<']';
}

constexpr int INF=1e9;
constexpr int MOD=1e9+7;
constexpr double EPS=1e-9;

char mul(char a,char b)
{
	int sign=a*b<0?-1:1;
	a=abs(a),b=abs(b);
	char x;
	if(a=='1') x=b;
	else if(b=='1') x=a;
	else if(a==b) x=-'1';
	else if(a=='i' && b=='j') x= 'k';
	else if(a=='j' && b=='k') x= 'i';
	else if(a=='k' && b=='i') x= 'j';
	else if(a=='i' && b=='k') x=-'j';
	else if(a=='j' && b=='i') x=-'k';
	else if(a=='k' && b=='j') x=-'i';
	else assert(0);
	return sign*x;
}

char eval(string s)
{
	char x='1';
	for(char c:s) x=mul(x,c);
	return x;
}

char pow(char a,ll r)
{
	char x='1';
	for(;r;r>>=1){
		if(r&1) x=mul(x,a);
		a=mul(a,a);
	}
	return x;
}

char pow(string s,ll r)
{
	return pow(eval(s),r);
}

string calc_small(string s)
{
	char x;
	int i=0;
	for(x='1';i<s.size() && x!='i';i++) x=mul(x,s[i]);
	if(x!='i') return "NO";
	for(x='1';i<s.size() && x!='j';i++) x=mul(x,s[i]);
	if(x!='j') return "NO";
	for(x='1';i<s.size();i++) x=mul(x,s[i]);
	if(x!='k') return "NO";
	return "YES";
}

void solve_small()
{
	int n,r; cin>>n>>r;
	string s; cin>>s;
	
	string t; rep(i,r) t+=s;
	cout<<calc_small(t)<<endl;
}

string calc(string s,ll r)
{
	if(pow(s,r)!=-'1') return "NO";
	ll len=min<ll>(s.size()*r,100000);
	char x;
	int i=0;
	for(x='1';i<len && x!='i';i++) x=mul(x,s[i%s.size()]);
	if(x!='i') return "NO";
	for(x='1';i<len && x!='j';i++) x=mul(x,s[i%s.size()]);
	if(x!='j') return "NO";
	return "YES";
}

void solve()
{
	ll n,r; cin>>n>>r;
	string s; cin>>s;
	cout<<calc(s,r)<<endl;
}

int main()
{
	int tc; cin>>tc;
	rep(i,tc){
		cout<<"Case #"<<i+1<<": ";
		//solve_small();
		solve();
	}
}
