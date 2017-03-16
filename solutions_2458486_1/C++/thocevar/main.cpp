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
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

#define all(c) (c).begin(),(c).end()
#define present(c,x) (find(c.begin(),c.end(),x) != (c).end())
#define pb push_back
#define mp make_pair
#define INIT(v,x) memset(v,x,sizeof(v))
#define REP(i,n) for (int i=0;i<(int)(n);i++)
#define traverse(v,it) for (typeof(v.begin()) it=v.begin();it!=v.end();it++)

typedef pair<int,int> PII;
typedef long long int64;

int tests;
int k,t;
int sk[400];
int key[200], nk[200];
vector<int> keys[200];
int have[201];
int opened[200];

int ord[200];
int shave[201];
int sopened[201];

int vis[200], root;
int go(int x) {
	vis[x]=1;
	REP (oy,t) {
		int y=ord[oy];
		if (present(keys[x],key[y]) && !sopened[y]) {
			if (!vis[y]) {
				if (go(y)) {
					sopened[y]=1;
					//printf("open cyc %d\n",y+1);
					shave[key[y]]--;
					REP (i,keys[y].size()) shave[keys[y][i]]++;
					return 1;
				}
			} else if (y==root) {
				sopened[y]=1;
				//printf("open cyc %d\n",y+1);
				shave[key[y]]--;
				REP (i,keys[y].size()) shave[keys[y][i]]++;
				return 1;
			}
		}
	}
	return 0;
}

int solve() {
	REP (i,t) ord[i]=i;
	for (int it=1;it<=100;it++) {
		memcpy(shave,have,sizeof(have));
		memcpy(sopened,opened,sizeof(opened));
		int change=1;
		while (change) {
			//printf("\n");
			change=0;
			// cycle
			REP (oi,t) {
				int i=ord[oi];
				if (!sopened[i] && shave[key[i]]) {
					INIT(vis,0);
					root=i;
					//printf("start from %d\n",i+1);
					if (go(i)) {
						change=1;
						break;
					}
				}
			}
			if (change) continue;
			// in-degree 0
			int hidden[201];
			INIT(hidden,0);
			REP (i,t) if (!sopened[i]) {
				REP (j,keys[i].size()) {
					hidden[keys[i][j]]++;
				}
			}
			REP (i,t) if (!sopened[i] && shave[key[i]] && hidden[key[i]]==0) {
				//printf("open %d\n",i+1);
				sopened[i]=1;
				shave[key[i]]--;
				REP (j,keys[i].size()) shave[keys[i][j]]++;
				change=1;
				break;
			}
		}
		int all=1;
		REP (i,t) if (!sopened[i]) all=0;
		if (all) return 1;
		random_shuffle(ord,ord+t);
	}
	return 0;
}

int main() {
	//freopen("treasure.in","r",stdin);
	freopen("D-large.in","r",stdin);
	freopen("D-large.out","w",stdout);
	//freopen("D-small-attempt1.out","w",stdout);

	scanf("%d",&tests);
	REP (test,tests) {
		cerr << test << endl;
		scanf("%d %d",&k,&t);
		INIT(have,0);
		REP (i,k) {
			scanf("%d",&sk[i]);
			have[sk[i]]++;
		}
		REP (i,t) {
			scanf("%d %d",&key[i],&nk[i]);
			keys[i].clear();
			REP (j,nk[i]) {
				int x;
				scanf("%d",&x);
				keys[i].push_back(x);
			}
		}
		INIT(opened,0);

		printf("Case #%d:", test+1);
		if (!solve()) {
			printf(" IMPOSSIBLE");
		} else {
			//printf("aha\n");
			REP (nop,t) {
				REP (i,t) {
					//printf("cand %d\n",i,opened[i],have[key[i]]);
					if (!opened[i] && have[key[i]]) {
						//printf("try %d\n",i);
						opened[i]=1;
						have[key[i]]--;
						REP (j,keys[i].size()) have[keys[i][j]]++;
						if (solve()) {
							printf(" %d",i+1);
							break;
						}
						opened[i]=0;
						have[key[i]]++;
						REP (j,keys[i].size()) have[keys[i][j]]--;
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}
