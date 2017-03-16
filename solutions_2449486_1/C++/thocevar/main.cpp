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

int tests;
int n,m;
int x[100][100];
int row[100],col[100];

int main() {
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);

	scanf("%d",&tests);
	REP (test,tests) {
		scanf("%d %d",&n,&m);
		REP (i,n) {
			REP (j,m) scanf("%d",&x[i][j]);
		}
		REP (i,n) {
			row[i]=0;
			REP (j,m) row[i]=max(row[i],x[i][j]);
		}
		REP (j,m) {
			col[j]=0;
			REP (i,n) col[j]=max(col[j],x[i][j]);
		}
		int ok=1;
		REP (i,n) {
			REP (j,m) {
				if (x[i][j]!=min(row[i],col[j])) ok=0;
			}
		}
		printf("Case #%d: %s\n", test+1, ok?"YES":"NO");
	}
	return 0;
}
