#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
vector <lint> ka;
string moji(int a){
	string ret="";string r="";int amari;
	if(a==0) return "0";if(a<0) return "-"+moji(-a);
	while(a>0){
		amari=a%10;r+=(amari+'0');a/=10;
	}
	for(int i=0;i<r.size();i++) ret+=r[r.size()-(i+1)];
	return ret;
}
int kazu(string a){
	int ret=0;
	rep(i,a.size()) ret=ret*10+(a[i]-'0');
	return ret;
}
bool kai(lint a){
	string s="";
	while(a>0){s+=((a%10)+'0');a/=10;}
	string t=s;reverse(All(t));
	if(s==t) return true;return false;
}
int main()
{
	lint a,b;int t;
	REP(i,1,10000){
		string s=moji(i),t=s;reverse(All(t));
		a=kazu(s+t);b=kazu(s+t.substr(1));
		//cout<<a<<' '<<b<<endl;
		if(i<1000) if(kai(a*a)) ka.pb(a);
		if(kai(b*b)) ka.pb(b);
	}
	//rep(i,ka.size()) cout<<ka[i]<<endl;
	cin>>t;
	rep(i,t){
		int ret=0;cin>>a>>b;
		rep(j,ka.size()){
			if(a<=ka[j]*ka[j] && ka[j]*ka[j]<=b) ret++;
		}
		cout<<"Case #"<<i+1<<": "<<ret<<endl;
	}
	return 0;
}
