#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
#include <random>
#include <cassert>
#include <cstdio>
#include <cstring>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define allof(v) v.begin(),v.end()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<bool> vb;
typedef long double ld;
typedef pair<string,string> pss;
typedef pair<ll,pair<string,string> > pls;

int main(){
	srand(5);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	rep(t,1,T+1){
		cout << "Case #" << t << ": ";
		string c,j;
		cin >> c >> j;
		int n = c.size();
		bool same = 1;
		rep(i,0,n) if(c[i] != j[i] && c[i] != '?' && j[i] != '?') same = 0;
		if(same){
			rep(i,0,n) if(c[i] == '?') c[i] = j[i] == '?' ? '0' : j[i];
			cout << c << ' ' << c << endl;
			continue;
		}
		vector<vl> mnmx(n+1,vl(2));
		rrep(i,0,n) rep(t,0,2){
			int cc = c[i]=='?' ? t*9 : c[i]-'0',
			    jj = j[i]=='?' ? (!t)*9 : j[i]-'0';
			mnmx[i][t] = mnmx[i+1][t] + (cc-jj)*pow(10,n-i-1);
		}
		ll ans = 5e18;
		string cres, jres;
		rep(i,0,n){
			if(c[i] == j[i] && c[i] != '?') continue;
			if(c[i] != '?' && j[i] != '?'){
				int cnd = abs((c[i]-j[i])*ll(pow(10,n-i-1)) + mnmx[i+1][c[i]<j[i]]);
				string ccnd=c, jcnd=j;
				rep(ii,0,i){
					if(ccnd[ii]=='?')ccnd[ii]=j[ii]=='?'?'0':j[ii];
					if(jcnd[ii]=='?')jcnd[ii]=ccnd[ii];
				}
				rep(ii,i+1,n){
					if(ccnd[ii] == '?') ccnd[ii] ='0'+ 9*(c[i]<j[i]);
					if(jcnd[ii] == '?') jcnd[ii] ='0'+ 9*(c[i]>j[i]);
				}
				if(pls(ans,pss(cres,jres)) > pls(cnd,pss(ccnd,jcnd))){
					ans = cnd;
					cres = ccnd;
					jres = jcnd;
				}
				break;
			} else {
				if((j[i] != '?' && j[i] >= '1') || c[i]==j[i] || (c[i]!='?'&&c[i]<'9')){
					ll cnd = abs(ll(pow(10,n-i-1)) - mnmx[i+1][1]);
					string ccnd=c, jcnd=j;
					rep(ii,0,i){
						if(ccnd[ii]=='?')ccnd[ii]=j[ii]=='?'?'0':j[ii];
						if(jcnd[ii]=='?')jcnd[ii]=ccnd[ii];
					}
					if(c[i]==j[i]){
						ccnd[i] = '0';
						jcnd[i] = '1';
					} else {
						ccnd[i] = j[i]-1;
					}
					rep(ii,i+1,n){
						if(ccnd[ii] == '?') ccnd[ii] = '9';
						if(jcnd[ii] == '?') jcnd[ii] = '0';
					}
					if(pls(ans,pss(cres,jres)) > pls(cnd,pss(ccnd,jcnd))){
						ans = cnd;
						cres = ccnd;
						jres = jcnd;
					}
				}
				if((c[i] != '?' && c[i] >= '1') || c[i]==j[i] || (j[i]!='?'&&j[i]<'9')){
					ll cnd = abs(ll(pow(10,n-i-1)) + mnmx[i+1][0]);
					string ccnd=c, jcnd=j;
					rep(ii,0,i){
						if(ccnd[ii]=='?')ccnd[ii]=j[ii]=='?'?'0':j[ii];
						if(jcnd[ii]=='?')jcnd[ii]=ccnd[ii];
					}
					if(c[i]==j[i]){
						ccnd[i] = '1';
						jcnd[i] = '0';
					} else if(c[i] != '?'){
						jcnd[i] = c[i]-1;
					} else {
						ccnd[i] = j[i]+1;
					}
					rep(ii,i+1,n){
						if(c[ii] == '?') ccnd[ii] = '0';
						if(j[ii] == '?') jcnd[ii] = '9';
					}
					if(pls(ans,pss(cres,jres)) > pls(cnd,pss(ccnd,jcnd))){
						ans = cnd;
						cres = ccnd;
						jres = jcnd;
					}
				}
			}
		}
		cout << cres << ' ' << jres << endl;
	}
}