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

int tests;
string s;

int main() {
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","wb",stdout);
	cin >> tests;
	FOR (t,1,tests) {
		//cerr << t << endl;
		printf("Case #%d: ",t);
		cin >> s;
		s+='+';
		int k=0;
		REP (i,s.size()-1) {
			if (s[i]!=s[i+1]) k++;
		}
		printf("%d\n",k);
	}
	return 0;
}
