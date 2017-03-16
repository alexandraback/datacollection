#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef set<int> se;
typedef pair<int,int> pii;
typedef long long int tint;
typedef vector<tint> vt;

#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define decl(v, c) typeof(c) v = c
#define forall(i, c) for(decl(i, c.begin()); i!=c.end(); ++i)
#define rall(c) (c).rbegin(), (c).rend()
#define all(c) (c).begin(), (c).end()
#define D(a) << #a << "=" << a << " "


#define si(a) int((a).size())
#define pb push_back
#define mp make_pair

tint T,K,C,S;

tint kpot[110];

tint get_pos(tint j) {
	tint x = j * C;
	tint res = 0;
	forn(i,C) {
		if (x >= K) break;
		tint off = x * kpot[C-1-i];
		  
		res += off;
		x++;   
	}
	
	return res+1;
}

void init() {
	kpot[0] = 1;
	forn(i,C) kpot[i+1] = K * kpot[i];
}

int main () {
	freopen("D-large.in","r",stdin);
	freopen("out.txt","w",stdout);
		
	cin >> T;
	
	forsn(cas,1,T+1) {
		cin >> K >> C >> S;
		
		init();
		
		if (S * C < K) {
			cout << "Case #" << cas << ": IMPOSSIBLE" << endl;
			continue;
		} 
		
		cout << "Case #" << cas << ":";
		
		forn(i, (K + C - 1) / C) {
			cout << " " << get_pos(i);
		}
		
		cout << endl;
		
	}		

  return 0;

}


