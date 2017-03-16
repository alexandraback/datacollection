#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstdlib>

using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)


int mod1 = int(1e9) + 7;

pair<char, bool> prod(char lc, bool lp, char rc, bool rp) {
	char nc;

	bool npos = !(lp ^ rp);
	if(lc == 1) {
		nc = rc;
	} else if(rc == 1) {
		nc = lc;
	} else if(lc == rc) {
		nc = 1;
		npos ^= true;
	} else {
		nc = 'i' + 'j' + 'k' - lc - rc;
		if(lc=='i' && rc=='k' 
			|| lc=='j' && rc=='i'
			|| lc=='k' && rc=='j') {
			npos ^= true;
		}
	}

	return mp(nc, npos);
}

void printout(int cas, bool ok) {
	cout << "Case #" << cas << ": " << (ok? "YES" : "NO") << endl;
}

int main(){
    cout.precision(9);

	int T;
	cin >> T;
	for (int cas = 1; cas <= T; ++cas) {

		ll l,x;
		cin >> l >> x;

		string s;
		cin >> s;

		if(l*x < 3) {
			printout(cas, false);
			continue;
		}

		char pc = 1;
		bool pp = true;

		forn(i,l) {
			pair<char, bool> next;
			next = prod(pc, pp, s[i], true);
			pc = next.first;
			pp = next.second;
		}

		char ac = 1;
		bool ap = true;

		ll nx = x%4;

		forn(i,nx) {
			pair<char, bool> next;
			next = prod(ac, ap, pc, pp);
			ac = next.first;
			ap = next.second;			
		}

		if(!(ac==1 && ap==false)) {
			printout(cas, false);
			continue;
		}

		int pi = 0;
		int iit = 0;

		char ic = 1;
		bool ip = true;
		while(pi<4) {
			pair<char, bool> next;
			next = prod(ic, ip, s[iit], true);
			ic = next.first;
			ip = next.second;

			if(ic=='i' && ip) 
				break;
			iit++;
			if(iit==l) {
				iit=0;
				pi++;
			}
		}

		if(pi==4){
			printout(cas, false);
			continue;
		}

		int pk = 0;
		int kit = l-1;

		char kc = 1;
		bool kp = true;
		while(pk<4) {
			pair<char, bool> next;
			next = prod(s[kit], true, kc, kp);
			kc = next.first;
			kp = next.second;

			if(kc=='k' && kp) 
				break;
			kit--;
			if(kit<0) {
				kit=l-1;
				pk++;
			}
		}

		if(pk==4){
			printout(cas, false);
			continue;
		}

		ll ilen = pi * l + iit;
		ll klen = pk * l + l - kit;

		if(ilen + klen > x*l) 
			printout(cas, false);
		else
			printout(cas, true);
	}

	return 0;
}
