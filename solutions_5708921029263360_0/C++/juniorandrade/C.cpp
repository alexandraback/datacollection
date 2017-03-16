#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s)) //LASTBIT
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second
#define PI 2*acos(0)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

//////////////////////
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
//////////////////////

void arquivo() {
  freopen("","r",stdin);
  freopen("","w",stdout);
}

int j, p, s, k;

struct triple {
	int S, F, T;
	triple(){};
	triple(int a, int b, int c) {
		F = a;
		S = b;
		T = c;
	}
};

vector<triple>just;

vector<triple>backAux;
vector<triple>ans;

int jp[11][11], js[11][11], ps[11][11];

void back(int id) {
	if(backAux.size() > ans.size()) ans = backAux;
	if(id == just.size()) return;
	back(id + 1);
	backAux.pb(just[id]);
	jp[just[id].F][just[id].S]++;
	js[just[id].F][just[id].T]++;
	ps[just[id].S][just[id].T]++;
	if(jp[just[id].F][just[id].S] <= k && js[just[id].F][just[id].T] <= k && ps[just[id].S][just[id].T] <= k) {
		back(id + 1);
	}
	jp[just[id].F][just[id].S]--;
	js[just[id].F][just[id].T]--;
	ps[just[id].S][just[id].T]--;
	backAux.pop_back();
}

inline void main2() {
	scanf("%d %d %d %d", &j, &p, &s, &k);  
	just.clear();
	backAux.clear();
	ans.clear();
	memset(jp, 0, sizeof jp);
	memset(js, 0, sizeof js);
	memset(ps, 0, sizeof ps);
	for(int i = 1; i <= j; ++i) for(int z = 1; z <= p; ++z) for(int w = 1; w <= s; ++w) just.pb(triple(i, z, w));
	back(0);
	printf("%d\n", (int)ans.size());
	for(int i = 0; i < (int)ans.size(); ++i) {
		printf("%d %d %d\n", ans[i].F, ans[i].S, ans[i].T);
	}
}

int main() {

  int t; scanf("%d", &t);
  for(int i = 1; i <= t; ++i) {
    printf("Case #%d: ", i);
    main2();
  }
  return 0;
}