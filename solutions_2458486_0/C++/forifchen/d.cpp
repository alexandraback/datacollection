#include <bits/stdc++.h>
#define f(i,x,y) for (int i = x; i < y; i++)
#define fd(i,x,y) for(int i = x; i>= y; i--)
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define vint vector<int>
#define ll long long
#define clr(A,x) memset(A, x, sizeof A)
#define pb push_back
#define pii pair<int,int>
#define fst first
#define snd second
#define ones(x) __builtin_popcount(x)
#define cua(x) (x)*(x)
#define eps (1e-9)
#define oo (1<<30)
#define debug(x) cout <<#x << " = " << x << endl
#define adebug(x,n) cout <<#x<<endl; f(i,0,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; f(i,0,m)f(j,0,n)cout<<x[i][j]<<char(j+1==n?10:32)
#define N 1
using namespace std;
template<class T> inline void mini(T &a,T b){if(b<a) a=b;}
template<class T> inline void maxi(T &a,T b){if(b>a) a=b;}
int caso;

int tc;
int k,n;
vint Llaves;
vint contiene[25];
int need[25];
int memo[1<<20];

int dp(vint llaves, int mask) {
	if (mask == 0) return 1;
	int &res = memo[mask];
	if (~res) return res;

	f(i,0,n) if (mask&(1<<i)) {
//		debug(need[i]);
		vector<int>::iterator it = find(all(llaves), need[i]);
		if (it != llaves.end()) {
			vint copia = llaves;
			llaves.erase(it);
			FOR(j, contiene[i]) llaves.pb(*j);
			if (dp(llaves, mask ^ (1<<i))) res = 1;
			llaves = copia;
			if(res == 1) return res;
		}
	}
	return res = 0;
}

int main(){
	int tc;
	cin >> tc;
	while (tc--) {
		Llaves.clear();
		f(i,0,n) contiene[i].clear();
		cin >> k >> n;
		f(i,0,k) {
			int x; cin >> x; Llaves.pb(x-1);
		}
		f(i,0,n) {
			int len;
			cin >> need[i] >> len;
			need[i]--;
			f(j,0,len) {
				int x; cin >> x;
				contiene[i].pb(x-1);
			}
		}

		clr(memo, -1);
		int puede = dp(Llaves, (1<<n) - 1);
		printf("Case #%d: ", ++caso);
		if (!puede) {
			puts("IMPOSSIBLE");
		} else {
			vint res(n,-1);
			int mask = (1<<n) - 1;
			f(i,0,n) {
				f(j,0,n) if (mask & (1<<j)) {
					vint::iterator it = find(all(Llaves), need[j]);
					if (it != Llaves.end()) {
						vint copia = Llaves;
						Llaves.erase(it);
						FOR(jj,contiene[j]) Llaves.pb(*jj);
						if (dp(Llaves, mask^(1<<j))) res[i] = j;
						if (~res[i]) {
							mask = mask^(1<<j);
							break;
						}else Llaves = copia;
					}
				}
			}
			f(i,0,n) cout << res[i]+1 << char(i+1==n? 10 : 32);
		}


	}
}

