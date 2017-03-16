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
int n;

map<int,int> d;

int main() {
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","wb",stdout);

	queue<int> q;
	q.push(1);
	d[1]=1;
	int todo=1000000;
	while (!q.empty() && todo) {
		int x=q.front();
		if (x<=1000000) todo--;
		q.pop();
		int y=x+1;
		if (d.count(y)==0) {
			d[y]=d[x]+1;
			q.push(y);
		}
		int z=x;
		y=0;
		while (z!=0) {
			y=y*10+z%10;
			z/=10;
		}
		if (d.count(y)==0) {
			d[y]=d[x]+1;
			q.push(y);
		}
	}
	cin >> tests;
	FOR (test,1,tests) {
		cin >> n;
		printf("Case #%d: %d\n",test,d[n]);
	}
	return 0;
}
