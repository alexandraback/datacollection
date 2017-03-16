#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <deque>
#include <vector>
#include <map>
#include <cmath>
#include <cstdlib>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <climits>
#include <cctype>
#include <utility>
#include <cassert>
#include <ctime>
using namespace std;

#define ft first
#define sd second
#define pb push_back
#define endl '\n'
#define buli(x) __builtin_popcountll(x)
#define cpy(a,e) memcpy(a,e,sizeof(e))
#define clr(a,e) memset(a,e,sizeof(a))
#define iter(c) __typeof((c).begin())
#define tr(c,i) for (iter(c) i=(c).begin();i!=(c).end();i++)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define rep(i,n) for (int (i)=0;(i)<(n);i++)
#define repd(i,n) for (int (i)=(n)-1;(i)>=0;i--)
#define reps(i,s,e) for (int (i)=(s);(i)<=(e);i++)
#define repds(i,s,e) for (int (i)=(s);(i)>=(e);i--)
#define repl(i,s,e) for (int (i)=(s);(i);i=e[i])

#define TASK "A-small-attempt1"

char c[2055];
map<char, int> d;
     
bool f(string s) {
 	map<char, int> e;

	for (auto u : s) e[u]++;

	for (auto u : e) {
	 	if (u.sd > d[u.ft]) {
	 	 	return false;
		}
	}

	for (auto u : e) d[u.ft] -= u.sd;

	return true;
}
string go(string s) {
 	string res = "";

	d.clear();

	for (auto u : s) d[u]++;


	while(f("SIX"))  res += "6";
	while(f("EIGHT")) res += "8";
	while(f("ZERO")) res += "0";
	while(f("FIVE")) res += "5";
	while(f("NINE")) res += "9";
	while(f("FOUR")) res += "4";
	while(f("SEVEN")) res += "7";
	while(f("TWO")) res += "2";
	while(f("ONE")) res += "1";
	while(f("THREE")) res += "3";

	sort(res.begin(), res.end());

	return res;
}                                                              
int main() {
	#ifdef home
		freopen(TASK".in","r",stdin);
		freopen(TASK".out","w",stdout);
	#endif 

	int t;

	scanf("%d", &t);

	for (int _ = 0; _ < t; _++) {
		scanf("%s", c);

		string s(c);

		string res = "";

		res = go(s);		

	 	cout << "Case #" << _ + 1 << ": " << res << endl;
	}
           
	#ifdef home
		eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
	#endif                                                                          
	return 0;
}