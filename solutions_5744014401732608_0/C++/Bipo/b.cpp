#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<bitset>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<functional> //highest
#include<algorithm>	//sort, heap etc.
#include<utility>	//pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef stack<int> si;
typedef queue<int> qi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> elst;

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define ABS(a,b) ((a) < (b) ? (b)-(a) : (a)-(b))

#define FORN(i,j,n) for(int i=j;i<(int)n;i++)
#define forn(i,n) FORN(i,0,n)
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define sz size()
#define ff first
#define ss second
#define pq priority_queue
#define all(x) (x).begin(),(x).end()
#define mlc(t,n) ((t*)malloc(n*sizeof(t)))
#define mset(m,v) memset(m,v,sizeof(m))

#define INF 1000000000
#define MM 1000000007

//---------------------------------------------//

ll n, p;

void fp(ll M) {
	p = 1;
	n = 0;
	while (p*2 <= M) {
		p *= 2;
		n++;
	}
}
int count() {
	ll B, M;
	cin >> B >> M;


	if (M <= (ll)(1 << (B-2))) {
		cout << "POSSIBLE" << endl;
		fp(M);
		ll b = M - p;

		forn(i, B) {
			forn(j, B) {
				if (j <= i || i == B-1) {
					cout << 0;
				} else {
					if (i <= n && (j <= n || j == B-1)){
						cout << 1;
					} else if(j == n + 1 && (b & (1 << (i-1)))) {
						cout << 1;
					} else if(i == n + 1 && b != 0 && j == B-1) {
						cout << 1;
					} else {
						cout << 0;
					}
				}
			}
			cout << endl;
		}

	} else {
		cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}

int main() {
	//freopen("1C/in.txt", "r", stdin);
	freopen("1C/B-small-attempt0.in", "r", stdin);
//	freopen("1C/B-large.in", "r", stdin);
	freopen("1C/out.txt","w", stdout);

	int T;
	scanf("%d",&T);

	for(int t=1;t<=T;t++) {
		printf("Case #%d: ", t);
		count();
	}
}
