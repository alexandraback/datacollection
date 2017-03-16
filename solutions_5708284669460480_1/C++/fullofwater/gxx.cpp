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

static char key[105], want[105];
int T, Q, K, L, S;

char poss[10];
double ans;
int cnt, best;

void dfs(int p) {
	if (p>=S) {
		poss[S]=0;
		char *pos=poss, *sit;
		int ins=0;
		while (sit=strstr(pos, want), sit) {
			cnt++;
			ins++;
			pos=sit+1;
		}
		best=max(best, ins);
		return;
	}
	for (int i=0;i<K;i++) {
		poss[p]=key[i];
		dfs(p+1);
	}
}

char putting[105];

int main (int argc, char *argv[]) {
	scanf("%d", &T);
	for (Q=1;Q<=T;Q++) {
		scanf("%d%d%d", &K, &L, &S);
		scanf("%s%s", key, want);
		static double cc['Z'+1];
		static int real['Z'+1];
		memset(cc,0,sizeof(cc));
		memset(real,0,sizeof(real));
		for (int i=0;i<K;i++)
			cc[key[i]]+=1.0, real[key[i]]++;
		for (int i='A';i<='Z';i++)
			cc[i]/=K;
		double maybe=1;
		int act=0;
		for (int i=0;i<L;i++) {
			maybe*=cc[want[i]];
			if (!real[want[i]])
				act=1;
		}
		if (act) {
			printf("Case #%d: 0\n", Q);
			continue;
		}
		int high=0;
		*putting=0;
		for (int i=0;i+L<=S;) {
			strcpy(putting+i, want);
			high++;
			i++;
			while (true) {
				int len=strlen(putting+i);
				if (strncmp(putting+i, want, len))
					i++;
				else
					break;
			}
			// AAAA
			//printf(">>> %s %d\n", putting+i, i);
		}
		//printf("%d!!!\n", high);
		maybe*=(S+1-L);
		ans=high-maybe;
		//printf("%f\n", maybe);
		/*best=cnt=0, dfs(0);
		if (!cnt) {
			printf("Case #%d: 0\n", Q);
			continue;
		}
		int tot=1;
		for (int i=0;i<S;i++)
			tot*=K;
		ans=best-cnt/double(tot);*/
		printf("Case #%d: %.8lf\n", Q, ans);
	}
}

