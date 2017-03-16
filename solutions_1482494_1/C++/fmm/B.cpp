#include <bits/stdc++.h>
#define rep(x,n) for(int x = 0; x < n; ++x)
#define print(x) cout << x << endl
#define dbg(x) cerr << #x << " == " << x << endl
#define _ << " , " <<
#define mp make_pair
#define X first
#define Y second
using namespace std;

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1<<10;
int a[maxn];
pair<int,int> b[maxn];
int done[maxn], n;

int main() {
	int T;
	cin >> T;
	for(int caso=1;caso<=T;caso++){
  	cin >> n;
  	rep(i,n) cin >> a[i] >> b[i].X, b[i].Y = i;
  	sort(b,b+n);
  	rep(i,n) done[i] = 0;
  	int have = 0, need = 0;
  	rep(k,2*n) {
  		int update = 0;
  		rep(i,n) {
				if(done[ b[i].Y ] < 2 && have >= b[i].X) {
					have += 2 - done[ b[i].Y ];
					done[ b[i].Y ] = 2;
					need++;
					update = 1;
				}
			}
			if(!update) for(int i = n-1; i >= 0; i--) {
				if(done[ b[i].Y ] == 0 && have >= a[ b[i].Y ]) {
					have += 1;
					done[ b[i].Y ] = 1;
					need++;
					break;
				}
			}
		}
		int ok = 1;
		rep(i,n) if(done[i] != 2) ok = 0;
		printf("Case #%d: ",caso);
		if(ok) printf("%d\n",need);
		else puts("Too Bad");
  }
  return 0;
}

