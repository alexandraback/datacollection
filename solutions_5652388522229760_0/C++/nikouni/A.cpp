#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef set<int> se;
typedef pair<int,int> pii;
typedef long long int tint;

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

vector<bool> seen;

void add(tint x) {
	while (x > 0) {
		tint d = x % 10;
		seen[d] = true;
		x /= 10; 
	}
}

bool done() {
	forn(i,10) if (!seen[i]) return false;
	return true;
}

int main () {
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
    
	ios_base::sync_with_stdio(false);
	
	tint T,N; 
	
	cin >> T;
	
	forsn(cas,1,T+1) {
		seen = vector<bool>(10,false);		
		cin >> N;
		if (N == 0) { cout << "Case #" << cas << ": INSOMNIA" << endl; continue;}
		for(tint x = N ; ; x += N) {
			add(x);
			if (done()) { cout << "Case #" << cas << ": " << x << endl; break;}
		}
	}
	

  return 0;

}


