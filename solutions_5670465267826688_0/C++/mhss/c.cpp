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

#define N 200009

int table[4][4] = {
{1, 2, 3, 4},
{2, -1, 4, -3},
{3, -4, -1, 2},
{4, 3, -2, -1}};

inline int _abs(int a) { return a < 0? -a: a; }

inline int mult(int a, int b) {
	int sig = (a<0)^(b<0);
	int mod = table[_abs(a)-1][_abs(b)-1];
	return sig? -mod: mod;
}

inline int f(int a) {
	return (a > 0)? a-1: a + 8;
}

ll n, x;
char s[N];

int rev[N];
int m1[N][8], m2[N][8], tempo;

int proc2(int i, int act) {
	if (i == n) return 0;
	if (m2[i][f(act)] == tempo) return 0;
	m2[i][f(act)] = tempo;
	
	if (act == 3 && rev[i] == 4) return 1;
	if (proc2(i+1, mult(act, s[i]))) return 1;
	
	return 0;
}

int proc1(int i, int act) {
	if (i > n-2) return 0;
	if (m1[i][f(act)] == tempo) return 0;
	m1[i][f(act)] = tempo;
	
	if (act == 2 && proc2(i+1, s[i])) return 1;
	if (proc1(i+1, mult(act, s[i]))) return 1;
	
	return 0;
}

int main() {
	cl(m1, 0);
	cl(m2, 0);
	tempo = 0;
	int t, cn = 1;
	sc(t); while (t--) {
		scanf("%lld%lld", &n, &x);
		scs(s);
		
		if (x > 14ll) {
			x -= 11ll;
			x %= 4ll;
			x += 11ll;
		}
		
		rp(i, n) s[i] = tolower(s[i])-'g';
		fr(i, 1, x) strncpy(s+i*n, s, n);
		n *= x;
		
		rev[n-1] = s[n-1];
		for(int i = n-2; i >= 0; i--) rev[i] = mult(s[i], rev[i+1]);
		
		tempo++;
		printf("Case #%d: %s\n", cn++, proc1(1, s[0])? "YES": "NO");
	}
	return 0;
}

