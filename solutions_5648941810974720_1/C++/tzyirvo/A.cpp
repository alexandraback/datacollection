/*
 * Problem: 
 * Link: 
 * Author: 
 * Handle: 
 * State: 
 * Date: 
 * Comments: 
 */
#include <vector>
#include <list>
#include <queue>
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
#include <cstring>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;
#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define INF_LL 9223372036854775807LL
#define INF 2000000000
#define EPS 		1e-8
#define FOR(i,a,b)  for(int i=(a);i<(b);i++)
#define F(i,a)      FOR(i,0,a)
#define PB          push_back
#define S           size()
#define MP          make_pair
#define MS(v, x)	memset(v, x, sizeof v)
#define ALL(v)      v.begin(),v.end()
#define LLA(v)      v.rbegin(),v.rend()
#define fi          first
#define se          second
#define NL 			printf("\n")
#define SP 			system("pause")
#define foreach(IT,C) for(typeof(C.begin())IT=C.begin();IT!=C.end();IT++)
const double PI = acos(-1.0);
#define BitSet(arg,posn) ((arg) | (1L << (posn)))
#define BitClr(arg,posn) ((arg) & ~(1L << (posn)))
#define BitTst(arg,posn) bool((arg) & (1L << (posn)))
#define BitFlp(arg,posn) ((arg) ^ (1L << (posn)))
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef long long   LL;

int let[30];

void run() {
	string s;
	cin >> s;
	MS(let, 0);
	F(i, s.S) {
		char ch = s[i];
		let[ch - 'A']++;
	}
	string ans;
	while(let['Z'-'A']--) {
		let['E'-'A']--;
		let['R'-'A']--;
		let['O'-'A']--;
		ans += '0';
	}
	// cout << ans << endl;
	while(let['W'-'A']--) {
		let['T'-'A']--;
		let['O'-'A']--;
		ans += '2';
	}
	while(let['G'-'A']--) {
		let['E'-'A']--;
		let['I'-'A']--;
		let['H'-'A']--;
		let['T'-'A']--;
		ans += '8';
	}
	while(let['X'-'A']--) {
		let['S'-'A']--;
		let['I'-'A']--;
		ans += '6';
	}
	// cout << ans << endl;
	while(let['T'-'A']--) {
		let['H'-'A']--;
		let['R'-'A']--;
		let['E'-'A']--;
		let['E'-'A']--;
		ans += '3';
	}
	// cout << ans << endl;
	
	
	while(let['R'-'A']--) {
		let['F'-'A']--;
		let['O'-'A']--;
		let['U'-'A']--;
		ans += '4';
	}
	while(let['F'-'A']--) {
		let['I'-'A']--;
		let['V'-'A']--;
		let['E'-'A']--;
		ans += '5';
	}
	while(let['V'-'A']--) {
		let['S'-'A']--;
		let['E'-'A']--;
		let['E'-'A']--;
		let['N'-'A']--;
		ans += '7';
	}
	while(let['O'-'A']--) {
		let['N'-'A']--;
		let['E'-'A']--;
		ans += '1';
	}
	while(let['N'-'A']--) {
		let['I'-'A']--;
		let['N'-'A']--;
		let['E'-'A']--;
		ans += '9';
	}
	sort(ALL(ans));
	cout << ans << endl;
}

int main() {
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int n = in();
	FOR(i, 1, n+1) {
		printf("Case #%d: ", i);
		run();
	}
	return 0;
}