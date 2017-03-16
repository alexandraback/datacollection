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

typedef pair<int,int> PII;
typedef long long int64;

string d="1ijk";
int f[4][4] = {
	{1,2,3,4},
	{2,-1,4,-3},
	{3,-4,-1,2},
	{4,3,-2,-1}
};

int num(char c) {
	if (c=='1') return 1;
	else return c-'i'+2;
}

int mul(int x, int y) {
	int s = (x*y<0)?-1:1;
	return s*f[abs(x)-1][abs(y)-1];
}

int pot(int p, int64 x) {
	if (x==1) return p;
	else if (x%2==0) {
		int r = pot(p,x/2);
		return mul(r,r);
	} else {
		int r = pot(p,x-1);
		return mul(r,p);
	}
}

int tests,l;
int64 x;
string s;

int main() {
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","wb",stdout);
	cin >> tests;
	FOR (test,1,tests) {
		cin >> l >> x;
		cin >> s;
		int p=1;
		REP (i,l) {
			p=mul(p,num(s[i]));
		}
		p = pot(p,x);
		int ok=0;
		if (p==-1) {
			int64 pl=1,li=-1;
			set<PII> sl;
			for (int64 i=0;i<l*x;i++) {
				pl=mul(pl,num(s[i%l]));
				if (pl==2) { li=i; break; }
				PII st = {pl,i%l};
				if (sl.count(st)) break;
				else sl.insert(st);
			}
			int64 pr=1,ri=-1;
			set<PII> sr;
			for (int64 i=l*x-1;i>li;i--) {
				pr=mul(num(s[i%l]),pr);
				if (pr==4) { ri=i; break; }
				PII st = {pr,i%l};
				if (sr.count(st)) break;
				else sr.insert(st);
			}
			if (li!=-1 && ri!=-1) ok=1;
			//printf("%I64d %I64d\n",li,ri);
		}
		printf("Case #%d: ",test);
		if (ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
