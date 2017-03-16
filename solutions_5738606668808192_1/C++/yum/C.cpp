#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<int(b);i++)
typedef unsigned int UI;
typedef long long LL;
typedef pair<int,int> PT;
typedef vector<int> VI;
typedef vector<VI> VVI;
template<typename T> ostream& operator<<(ostream& s, vector<T>& v)
{ s << '{'; FOR(i,0,v.size()) s << (i ? "," : "") << v[i]; return s << '}'; }
template<typename S, typename T> ostream& operator<<(ostream &s, pair<S,T> const& p)
{ return s << '(' << p.first << ',' << p.second << ')'; }

const int MAX_P = 70000;
const int N = 32;
const int J = 500;

vector<int> primes;
int sp[MAX_P];

void sieve() {
	for (LL i = 2; i < MAX_P; i++) {
		if (sp[i]) continue;
		sp[i] = i;
		primes.push_back(i);
		for (LL j=i*i;j<MAX_P;j+=i)
			if(!sp[j]) sp[j] = i;
	}
}

__int128 interpret(UI n, int b) {
	__int128 a = 0, i = 1;
	while (n) {
		if (n & 1) a += i;
		n /= 2;
		i *= b;
	}
	return a;
}

VI tryIt(UI n) {
	VI a;
	FOR(b,2,11) {
		__int128 i = interpret(n, b);
		int gotP = -1;
		for (int p : primes) if (p < i && i % p == 0) {
			gotP = p;
			break;
		}
		if (gotP == -1) return VI();
		a.push_back(gotP);
	}
	return a;
}

int main() {
	sieve();

	cout << "Case #1:\n";
	for (UI n = (1<<N-1)|1, j = J; j; n += 2) {
		VI t = tryIt(n);
		if (!t.empty()) {
			j--;
			cout << bitset<N>(n);
			for (int x : t) cout << ' ' << x;
			cout << endl;
		}
	}
}
