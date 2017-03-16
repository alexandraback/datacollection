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
int k,n;
int sk[400];
int key[200], nk[200];
vector<int> keys[200];

int f[1<<20];
int have[201];

int solve(int todo) {
	int &s=f[todo];
	if (s!=-1) return s;
	if (todo==0) return s=1;
	s=0;
	REP (i,n) if (todo&(1<<i)) {
		if (have[key[i]]) {
			have[key[i]]--;
			REP (j,keys[i].size()) have[keys[i][j]]++;
			if (solve(todo^(1<<i))) {
				s=1;
				break;
			}
			REP (j,keys[i].size()) have[keys[i][j]]--;
			have[key[i]]++;
		}
	}
	return s;
}

int main() {
	freopen("D-small-attempt1.in","r",stdin);
	freopen("D-small-attempt1.out","w",stdout);

	scanf("%d",&tests);
	REP (test,tests) {
		scanf("%d %d",&k,&n);
		INIT(have,0);
		REP (i,k) {
			scanf("%d",&sk[i]);
			have[sk[i]]++;
		}
		REP (i,n) {
			scanf("%d %d",&key[i],&nk[i]);
			keys[i].clear();
			REP (j,nk[i]) {
				int x;
				scanf("%d",&x);
				keys[i].push_back(x);
			}
		}
		INIT(f,-1);
		int all=(1<<n)-1;
		solve(all);
		printf("Case #%d:", test+1);
		if (f[all]<=0) {
			printf(" IMPOSSIBLE");
		} else {
			while (all>0) {
				REP (i,n) if (all&(1<<i)) {
					if (f[all^(1<<i)]>0) {
						printf(" %d",i+1);
						all^=(1<<i);
						break;
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}
