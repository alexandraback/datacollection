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

vector<tint> P;
set<string> coin_set;

tint primo(tint x) {
	forn(i,si(P)) if (x % P[i] == 0) return P[i];
	return 0;
}

void generate_primes(tint n) {
	for(tint i = 2; si(P) < n ; i++) {
		if (primo(i) == 0) P.pb(i);
	}	
}

vt random_coin(tint n) {
	vt res(n,1);
  
	for(tint i = 1 ; i < n - 1; i++) 
		res[i] = rand() % 2;
    
	return res;
}

void print(vt &coin) {
	forn(i,si(coin)) cout << coin[i];
}

string to_string(vt &coin) {
	stringstream out;
	dforsn(i,0,si(coin)) out << coin[i];
	return out.str();
}

tint value(vt &coin,tint b) {
	tint res = 0;
	tint p = 1;
	forn(i,si(coin)) {
		res += p * coin[i];
		p *= b;		
	}
	return res;
}

bool check(vt &coin) {
	vector<tint> res;
	for(tint b = 2 ; b <= 10 ; b++) {
		tint val = value(coin,b);
		tint prime = primo(val);
		if (prime == 0) return false;
		res.pb(prime);		
	}
	string cc = to_string(coin);
	if (coin_set.count(cc) > 0) { cout << "DUPLICATED" << endl; return false;}
	coin_set.insert(cc);
	cout << cc;
	forn(i,si(res)) cout << " " << res[i]; cout << endl;
	return true;
}

int main () {
	//freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	srand (1234);

	ios_base::sync_with_stdio(false);
	
	tint N = 16, J = 50;
		
	generate_primes(1000);

	tint count = 0;
	
	cout << "Case #1:" << endl;
	
	forn(i,1000) {
		vt coin = random_coin(N);
		if (check(coin)) count++;
		if (count == J) break;
	}
		

  return 0;

}


