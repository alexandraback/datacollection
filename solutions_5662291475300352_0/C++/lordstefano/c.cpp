#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i = x; i<y; i++ )
#define FORV(it,A) for(vector<int>::iterator it = A.begin(); it!= A.end(); it++)
#define FORS(it,A) for(set<int>::iterator it = A.begin(); it!= A.end(); it++)
#define quad(x) (x) * (x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

struct no{
	ll m, d;
};

no hike[100];

pii solve(no h){
	return pii (h.d*h.m, (h.d*h.m + 360LL*h.m));
}
int n;

int main (){
	int t; cin >> t;
	f (kase, 1, t+1){
		int topo = 0;
		cin >> n;
		vector <pii > H;
		f (i, 0, n){
			int h, m, d; cin >> d >> h >> m;
			d = 360-d;
			f (j, 0, h){
				hike[topo].d = d;
				hike[topo++].m = m+j;
				H.pb(solve(hike[topo-1]));
			}
		}
		//f (i, 0, H.size()) printf("%lld %lld\n", H[i].fst, H[i].snd);
		int ans = 0;
		if (H.size() < 2){
			ans = 0;
		}
		else{
			if (H[0].fst > H[1].fst) swap(H[0], H[1]);
			if (H[0].fst == H[1].fst) ans = 0;
			else if (H[1].fst < H[0].snd) ans = 0;
			else ans = 1;
		}
		printf("Case #%d: %d\n", kase, ans);

		
	}
	return 0;
}

