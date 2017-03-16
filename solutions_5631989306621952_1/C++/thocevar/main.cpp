#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <math.h>
#include <queue>
#include <list>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <ctime>
using namespace std;

#define ALL(c) (c).begin(),(c).end()
#define IN(x,c) (find(c.begin(),c.end(),x) != (c).end())
#define REP(i,n) for (int i=0;i<(int)(n);i++)
#define FOR(i,a,b) for (int i=(a);i<=(b);i++)
#define INIT(a,v) memset(a,v,sizeof(a))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
template<class A, class B> A cvt(B x) { stringstream ss; ss<<x; A y; ss>>y; return y; }

typedef long long int64;
typedef pair<int64,int64> PII;

int tests;

string solve(string s) {
	int n=s.size();
	if (n==0) return "";
	int mc=-1;
	for (char c : s) {
		if (c>mc) mc=c;
	}
	REP (i,n) {
		if (s[i]==mc) {
			string p=solve(s.substr(0,i));
			string q,r;
			FOR (j,i,n-1) {
				if (s[j]==mc) q+=s[j];
				else r+=s[j];
			}
			return q+p+r;
		}
	}
}

int main() {
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","wb",stdout);
	cin >> tests;
	FOR (t,1,tests) {
		printf("Case #%d: ",t);
		string s;
		cin >> s;
		solve(s);
		cout << solve(s) << endl;
	}
	return 0;
}
