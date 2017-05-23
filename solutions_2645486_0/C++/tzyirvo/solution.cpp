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
#include <malloc.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <stdint.h>
#include <unistd.h>
#include <ctime>
#include <climits>
using namespace std;
#define EPS 		1e-8
#define FOR(i,a,b)  for(int i=(a);i<(b);i++)
#define F(i,a)      FOR(i,0,a)
#define PB          push_back
#define S           size()
#define MP          make_pair
#define ALL(v)      v.begin(),v.end()
#define LLA(v)      v.rbegin(),v.rend()
#define fi          first
#define se          second
#define NL 			printf("\n")
#define SP 			system("pause")
#define foreach(IT,C) for(typeof(C.begin())IT=C.begin();IT!=C.end();IT++)
const double PI = acos(-1.0);
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<string> vstr;
typedef long long   LL;
//#define DEBUG
int ee, r, nn, cnt = 0;
vi vv;

int solve(int e, const vi& v, int pos = 0) {
	int len = v.S;
	if(pos == len) return 0;
	int res = 0, gain;
	F(i, e+1) {
		gain = v[pos] * i;
		int aux = (e+r-i)%(ee+1);
		gain += solve(aux, v, pos+1);
		res = max(res, gain);
		/*if(!pos) {
			cout << "res: " << res << endl;
			SP;
		}*/
	}
	return res;
}

void run() {
	ee = in(), r = in(), nn = in();
	vv.clear();
	while(nn--) vv.PB(in());
	int ans = solve(ee, vv);
	printf("Case #%d: %d\n", ++cnt, ans);
}

int main(){
	#ifdef DEBUG
		freopen("bsmall.in","r",stdin);
		freopen("bsmallout.in","w",stdout);
		time_t st=clock();
	#endif
	int t = in();
	while(t--)
	run();
	#ifdef DEBUG
		//printf("=============\n");
		//printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
	#endif
	return 0;
}




























//Author: Gabriel Menacho                      Nickname: tzyirvo.
