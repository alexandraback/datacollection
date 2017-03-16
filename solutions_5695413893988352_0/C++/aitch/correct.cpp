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
		
		ll ans = 5e18;
		string cres, jres;
		rep(cc,0,pow(10,n)){
			string cs = to_string(cc);
			while(cs.size() < n) cs = '0'+cs;
			bool go = 1;
			rep(i,0,n) if(c[i]!='?'&&c[i]!=cs[i]) go = 0;
			if(go){
				rep(jj,0,pow(10,n)){
					string js = to_string(jj);
			while(js.size() < n) js = '0'+js;
					go = 1;
					rep(i,0,n) if(j[i]!='?'&&j[i]!=js[i]) go = 0;
					if(go){
						ll cnd = abs(cc-jj);
						if(pls(ans,pss(cres,jres)) > pls(cnd,pss(cs,js))){
							ans = cnd;
							cres = cs;
							jres = js;
						}
					}
				}
			}
		}
		cout << cres << ' ' << jres << endl;
	}
}