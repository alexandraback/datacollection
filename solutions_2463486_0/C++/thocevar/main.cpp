#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cctype>
#include <climits>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

#define all(c) (c).begin(),(c).end()
#define present(c,x) (find(c.begin(),c.end(),x) != (c).end())
#define pb push_back
#define mp make_pair
#define INIT(v,x) memset(v,x,sizeof(v))
#define REP(i,n) for (int i=0;i<(n);i++)
#define traverse(v,it) for (typeof(v.begin()) it=v.begin();it!=v.end();it++)

typedef pair<int,int> PII;
typedef long long int64;

int ispal(int64 a) {
	if (a==0) return 1;
	int d[20], n=0;
	while (a>0) {
		d[n++]=a%10;
		a/=10;
	}
	REP (i,n) if (d[i]!=d[n-1-i]) return 0;
	return 1;
}

int p[10000001];

int solve(int64 a) {
	if (a==0) return 0;
	int st=0;
	for (int64 n=1;n*n<=a;n++) if (p[n]) {
		if (ispal(n*n)) st++;
	}
	return st;
}

int main() {
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);

	for (int n=1;n<=10000000;n++) p[n]=ispal(n);
	int tests;
	cin >> tests;
	REP (test,tests) {
		int64 a,b;
		cin >> a >> b;
		printf("Case #%d: %d\n", test+1, solve(b)-solve(a-1));
	}
	return 0;
}
