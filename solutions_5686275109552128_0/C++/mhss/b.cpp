#include <bits/stdc++.h>

using namespace std;

#define fr(a,b,c) for(int (a) = (b); (a) < (c); ++(a))
#define rp(a,b) fr(a,0,b)
#define fre(a,b) for(int a = adj[b]; ~a; a = ant[a])
#define cl(a,b) memset((a), (b), sizeof(a))
#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d%d", &a, &b)
#define sc3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define scs(s) scanf("%s", s)
#define pri(x) printf("%d\n", x)

#define iter(a) __typeof((a).begin())
#define fore(a,b) for(iter(b) a = (b).begin(); a != (b).end(); ++a)

#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

const int oo = 0x3f3f3f3f;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vi > vii;

#define N 2009

int n, a[N], ans;

int top(int mx) {
	int ret = 0;
	rp(j, n) {
		if (a[j] <= mx) break;
		ret += ((a[j]+mx-1)/mx)-1;
	}
	return ret;
}

int main() {
	int t, cn = 1;
	sc(t); while (t--) {
		sc(n);
		rp(i, n) sc(a[i]);
		sort(a, a+n);
		reverse(a, a+n);
		ans = a[0];
		fr(i, 1, a[0]) ans = min(ans, i + top(i));
		printf("Case #%d: %d\n", cn++, ans);
	}
	return 0;
}

