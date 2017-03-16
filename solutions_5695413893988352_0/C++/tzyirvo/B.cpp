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
#include <string>
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
vs C, J;

void process(string s, int pos = 0, int arr = 0) {
	if(pos == s.S) {
		if(arr == 0) C.PB(s);
		else J.PB(s);
		return;
	}
	if(s[pos] != '?') {
		process(s, pos + 1, arr);
		return;
	}
	F(i, 10) {
		s[pos] = (char)('0' + i);
		process(s, pos + 1, arr);
	}
}

LL stoi(string s) {
	LL res = 0LL;
	int len  = s.S;
	for(int i=0; i<len; i++){
		res = res * 10LL + (LL)( s[i] - '0' );
	}
	return res;
}

void run() {
	string c, j;
	cin >> c >> j;
	C.clear();
	J.clear();
	process(c);
	process(j, 0, 1);
	sort(ALL(C));
	sort(ALL(J));
	LL _max = INF_LL;
	string ans1, ans2;
	F(a, C.S) {
		LL cc = stoi(C[a]);
		if (a == 0) {
			ans1 = C[0];
		}
		F(b, J.S) {
			LL jj = stoi(J[b]);
			if (a == 0  && b == 0) {
				ans2 = J[0];
				_max = abs(cc-jj);
			}
			
			if (abs(jj-cc) < _max) {
				ans1 = C[a];
				ans2 = J[b];
				_max = abs(jj-cc);
			}
		}
	}
			cout << ans1 << " " << ans2 << endl;
}

int main() {
	freopen("B-small.in","r",stdin);
	freopen("B-small.out","w",stdout);
	int n = in();
	FOR(i, 1, n+1) {
		printf("Case #%d: ", i);
		run();
	}
	return 0;
}