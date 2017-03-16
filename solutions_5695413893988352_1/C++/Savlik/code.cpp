#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <queue>
#include <cstring>
#include <string>
#include <complex>
#include <unordered_map>
#include <valarray>

#define vi vector<int>
#define vpii vector< pair<int,int> >
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define FOREACH(it,x) for (auto it = (x).begin(); it!=(x).end(); ++it) 
#define sz(x) (int)(x).size()
#define FOR(i,n) for (ll i = 0; i < ll(n); i++)
#define ROF(i,n) for (ll i = ((ll)n-1); i >= 0; i--)
#define FOR1(i,n) for (ll i = 1; i < ll(n); i++)
#define REP(i,a,b) for (ll i = a; i < ll(b); i++)
#define READ(a) ll a; scanf("%d", &a);
#define READV(v,n) vi v(n);FOR(i,n){scanf("%d", &v[i]);}
#define WRITE(v) FOR(i,sz(v))cout<<v[i]<<" ";
#define gmin(a,b) { if (b < a) a = b; }
#define gmax(a,b) { if (b > a) a = b; }
#define pb push_back
#define ff first
#define ss second
#define oo ((1LL<<62)+((1LL<<31)-1))
#define MOD 1000000007ll
const double PI = std::atan(1.0)*4;

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

//#include <windows.h>
//#include <thread>
//#include <chrono>
int n;
string s, r;
ll x, y;
string sx, sy;

vector<pair<string, string> > fill2(string s, string r){
	vector<pair<string, string> > res;
	string ss=s;
	string rr=r;
	FOR(i, s.length()){
		if(ss[i]=='?' && rr[i]=='?'){
			ss[i]=rr[i]='0';
		}else if(ss[i]=='?'){
			ss[i]=rr[i];
		}else if(rr[i]=='?'){
			rr[i]=ss[i];
		}
	}
	res.pb(mp(ss, rr));
	string sss=ss;
	string rrr=rr;
	bool a, b;
	a = false; b=false;
	ROF(i, s.length()){
		if(s[i]=='?' && ss[i]>'0' & !a){
			sss=ss;
			rrr=rr;
			sss[i]--;
			for(int k = i+1;k<s.length();k++){
				if(s[k]=='?') sss[k]='9';
				if(r[k]=='?') rrr[k]='0';
			}
			res.pb(mp(sss, rrr));
			a = true;
		}
		if(r[i]=='?' && rr[i]<'9' && !b){
			sss=ss;
			rrr=rr;
			rrr[i]++;
			for(int k = i+1;k<s.length();k++){
				if(s[k]=='?') sss[k]='9';
				if(r[k]=='?') rrr[k]='0';
			}
			res.pb(mp(sss, rrr));
			b= true;
		}
	}
next:
	a = false; b=false;
	ROF(i, s.length()){
		if(r[i]=='?' && rr[i]>'0' && !a){
			sss=ss;
			rrr=rr;
			rrr[i]--;
			for(int k = i+1;k<s.length();k++){
				if(s[k]=='?') sss[k]='0';
				if(r[k]=='?') rrr[k]='9';
			}
			res.pb(mp(sss, rrr));
			a=true;
		}
		if(s[i]=='?' && ss[i]<'9' && !b){
			sss=ss;
			rrr=rr;
			sss[i]++;
			for(int k = i+1;k<s.length();k++){
				if(s[k]=='?') sss[k]='0';
				if(r[k]=='?') rrr[k]='9';
			}
			res.pb(mp(sss, rrr));
			b=true;
		}
		
	}
	next2:
	return res;
}

void fill(string s, string r, int i){
	if(i==n){
		ll xx=0;
		ll yy=0;
		FOR(j, n){
			xx*=10;
			xx+=s[j]-'0';
			yy*=10;
			yy+=r[j]-'0';
		}
		if(abs(xx-yy)<abs(x-y) || abs(xx-yy)==abs(x-y) && xx<x || abs(xx-yy)==abs(x-y) && xx==x && yy<y){
			x=xx;
			y=yy;
			sx = s;
			sy = r;
		}
		return;
	}
	if(s[i]=='?' && r[i]=='?'){
		s[i]='0'; r[i]='0';
		fill(s, r, i+1);
		if(i+1<n && (s[i+1]!='?' || r[i+1]!='?')){
			s[i]='1'; r[i]='0';
			fill(s, r, i+1);
			s[i]='0'; r[i]='1';
			fill(s, r, i+1);
		}
		s[i]='9'; r[i]='0';
		fill(s, r, i+1);
		s[i]='0'; r[i]='9';
		fill(s, r, i+1);
		return;
	}

	if(s[i]=='?'){
		s[i]='0';
		fill(s, r, i+1);
		s[i]='9';
		fill(s, r, i+1);
		if(r[i]!='0' && r[i]!='9'){
			s[i]=r[i];
			fill(s, r, i+1);
		}
		if(r[i]-1!='0'  && r[i]!='0'){
			s[i]=r[i]-1;
			fill(s, r, i+1);
		}
		if(r[i]+1!='9' && r[i]!='9'){
			s[i]=r[i]+1;
			fill(s, r, i+1);
		}
		return;
	}

	if(r[i]=='?'){
		r[i]='0';
		fill(s, r, i+1);
		r[i]='9';
		fill(s, r, i+1);
		if(s[i]!='0' && s[i]!='9'){
			r[i]=s[i];
			fill(s, r, i+1);
		}
		if(s[i]-1!='0' && s[i]!='0'){
			r[i]=s[i]-1;
			fill(s, r, i+1);
		}
		if(s[i]+1!='9' && s[i]!='9'){
			r[i]=s[i]+1;
			fill(s, r, i+1);
		}
		return;
	}
	fill(s, r, i+1);
}

bool bigger(string &s, string &r){
	FOR(i, sz(s)){
		if(s[i]>r[i]) return true;
		if(s[i]<r[i]) return false;
	}
	return true;
}

string mini(string s){
	string res = s;
	FOR(i, s.length()){
		if(res[i]=='?') res[i]='0';
	}
	return res;
}

string maxi(string s){
	string res = s;
	FOR(i, s.length()){
		if(res[i]=='?') res[i]='9';
	}
	return res;
}


void solve(string s, string r){
	cerr<<s<<" "<<r<<endl;
	string ss, rr;
	if(bigger(s, r)){
		s = mini(s);
		r = maxi(r);
	}else{
		s = maxi(s);
		r = mini(r);
	}
	
	ll xx=0;
	ll yy=0;
	FOR(j, n){
		xx*=10;
		xx+=s[j]-'0';
		yy*=10;
		yy+=r[j]-'0';
	}
	if(abs(xx-yy)<abs(x-y) || abs(xx-yy)==abs(x-y) && xx<x || abs(xx-yy)==abs(x-y) && xx==x && yy<y){
		x=xx;
		y=yy;
		sx = s;
		sy = r;
	}
	return;
	

}

int main(int argc, char *argv[]){
	int T;
	cin>>T;
	FOR(t, T){
		cin>>s>>r;
		n = s.length();
		x=0;
		y=oo;
		
		vector<pair<string, string> > res;
		FOR(k, n){
			if(s[k]!='?' && r[k]!='?' && s[k]!=r[k]){
				goto next;
			}
		}
		res = fill2(s, r);
		cout<<"Case #"<<(t+1)<<": "<<res[0].ff<<" "<<res[0].ss<<endl;
		continue;

		next:
		FOR(k, n){
			if(s[k]!='?' && r[k]!='?' && s[k]!=r[k]){
				auto pos = fill2(s.substr(0,k), r.substr(0,k));
				FOR(i, sz(pos)){
					string ss = pos[i].ff + s.substr(k);
					string rr = pos[i].ss + r.substr(k);
					solve(ss, rr);
				}
			}
		}
		//solve(s, r, 0);
		cout<<"Case #"<<(t+1)<<": "<<sx<<" "<<sy<<endl;
		
	}
	return 0;
}