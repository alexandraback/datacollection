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

#define TASK "B-small-attempt1"

string s, t;
long long res;
string c, d;
  
void go(int id) {
//	cerr << s << " " << t << endl;
 	if (id == (int)s.length()) {
 	   	stringstream ss, sss;
		long long a, b;
	        ss << s;
		ss >> a;
		sss << t;
		sss >> b;

		if (abs(a - b) < res || (abs(a - b) == res && s < c) || (abs(a - b) == res && s == c && t < d)) {
		 	res = abs(a - b);
			c = s;
			d = t;
		}

		return;
	}

	if (s[id] != '?') {
	 	if (t[id] == '?')
		for (int j = '0'; j <= '9'; j++) {
		 	if (t[id] == '?') {
				t[id] = j;
				go(id + 1);
				t[id] = '?';
			} else go(id + 1);
		} else go(id + 1);
		return; 
	}	

	for (int i = '0'; i <= '9'; i++) {
		bool flag = false;
	 	if (s[id] == '?') {
	 	 	flag = true;
			s[id] = i;
		}
		if (t[id] == '?')
		for (int j = '0'; j <= '9'; j++) {
		 	if (t[id] == '?') {
				t[id] = j;
				go(id + 1);
				t[id] = '?';
			} else go(id + 1);
		} else go(id + 1);

		if (flag) s[id] = '?';
	}
}                                                                 
int main() {
	#ifdef home
		freopen(TASK".in","r",stdin);
		freopen(TASK".out","w",stdout);
	#endif 

	int tr;

	scanf("%d", &tr);

	for (int _ = 0; _ < tr; _++) {
		cin >> s >> t;
		c.resize(s.length());
		d.resize(t.length());

		for (int i = 0; i < (int)s.length(); i++) c[i] = d[i] = '9';
		res = LLONG_MAX;
		
		go(0);	
		cout << "Case #" << _ + 1 << ": " << c << " " << d << endl;
	}
           
	#ifdef home
		eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
	#endif                                                                          
	return 0;
}