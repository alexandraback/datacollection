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

const int N = 1010;

char s[N];
int n;

inline void main2() {
	scanf(" %s", s);
	n = strlen(s);

	char lft;
	lft = s[0];
	string a, b;
	a.pb(s[0]);
	for(int i = 1; i < n; ++i) {
		if(s[i] >= lft) {
			a.pb(s[i]); 
			lft = s[i];
		}
		else {
			b.pb(s[i]);
		}
	}
	reverse(a.begin(), a.end());
	cout << " " << a << b << endl;
}

int main() {
	int t; scanf("%d", &t);
	for(int tt = 1; tt <= t; ++tt) {
		printf("Case #%d:", tt);
		main2();
	}
  return 0;
}