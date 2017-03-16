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

int r, c, x;

bool proc() {
	if (x == 1) return 1;
	if (x == 2) return ((r*c)%2) == 0;
	if (x == 3) {
		if (r == 1) return 0;
		if (c < x) return 0;
		return ((r*c)%3) == 0;
	} else if (x == 4) {
		if (r <= 2) return 0;
		if (c < x) return 0;
		return ((r*c)%4) == 0;
	}
	return 0;
}

int main() {
	int t, cn = 1;
	sc(t); while (t--) {
		sc3(x, r, c);
		if (r > c) swap(r, c);
		printf("Case #%d: %s\n", cn++, proc()? "GABRIEL": "RICHARD");
	}
	return 0;
}

