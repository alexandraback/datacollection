#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>
#include <unordered_set>
#include <cassert>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
#define prev PREV
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

/////////////////////////////////////////////////////////////////////////

int top;

struct node {
	int v, step, use;
};


int main (int argc, char *argv[])
{
	int T, Q;
	scanf("%d", &T);
	for (Q=1;Q<=T;Q++) {
		static int C, D, V, X[105], bag[105];
		scanf("%d%d%d", &C, &D, &V);
		int tot=1, us=0;
		top=(1<<V+1)-1;
		for (int i=0;i<D;i++) {
			scanf("%d", X+i);
			if (X[i]<=V)
				tot=(tot|(tot<<X[i])|1), us|=(1<<X[i]);
		}
		printf("Case #%d: ", Q);
		//printf("(%d)", tot);
		tot&=top;
		if (tot==top) {
			puts("0");
			continue;
		}
		queue<node> q;
		unordered_set<long long> vis;
		q.push({tot, 0, us});
		vis.insert(tot);
		int ans=-1;
		while (!q.empty()) {
			node f=q.front();
			q.pop();
			for (int i=1;i<=V;i++) {
				if ((f.use&(1<<i))==0) {
					node b={(f.v|(f.v<<i)|1)&top, f.step+1, f.use|(1<<i)};
					if (b.v==top) {
						ans=b.step;
						goto out;
					}
					if (vis.find(b.v)==vis.end()) {
						vis.insert(b.v);
						q.push(b);
						//printf("!! %x %d %x\n", b.use, b.step, b.v);
					}
				}
			}
		}
		out:
		printf("%d\n", ans);
		;
	}
}

