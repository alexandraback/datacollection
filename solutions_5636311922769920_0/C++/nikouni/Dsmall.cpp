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


int main () {
	freopen("D-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	
	int T,K,C,S;
	
	cin >> T;
	
	forsn(cas,1,T+1) {
		cin >> K >> C >> S;
		
		cout << "Case #" << cas << ":";
		
		forn(i,S) cout << " " << i+1;
		cout << endl;
		
	}		

  return 0;

}


