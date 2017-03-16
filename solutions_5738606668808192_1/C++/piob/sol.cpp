#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) ((int)(a).size())
#define VAR(x) #x ": " << x << " "
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define gcd __gcd
#define x first
#define y second
#define st first
#define nd second
#define pb push_back

using namespace std;

template<typename T> ostream& operator<<(ostream &out, const vector<T> &v){ out << "{"; for(const T &a : v) out << a << ", "; out << "}"; return out; }
template<typename S, typename T> ostream& operator<<(ostream &out, const pair<S,T> &p){ out << "(" << p.st << ", " << p.nd << ")"; return out; }

typedef long long int64;
typedef pair<int, int> PII;
typedef long double K;
typedef vector<int> VI;

const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};

const int n = 32;
const int j = 500;

struct answer {
	string coin;
	array<int, 11> divs;
};

vector<answer> out;

string coin;

bool is_div(int base, int div){
	int rem = 0;
	for(char c : coin){
		rem = rem * base + (c - '0');
		rem %= div;
	}
	return rem == 0;
}

void check(){
	for(answer &a : out)
		if(a.coin == coin)
			return;

	answer a;
	FWD(b,2,11){
		bool got = 0;
		FWD(d,2,1000)
			if(is_div(b, d)){
				a.divs[b] = d;
				got = 1;
				break;
			}
		if(!got) return;
	}

	a.coin = coin;
	out.push_back(a);
	printf("%s", a.coin.data());
	FWD(b,2,11) printf(" %d", a.divs[b]);
	printf("\n");
}

int main(){
	printf("Case #1:\n");

	mt19937_64 eng;
	uniform_int_distribution<int> dist(0, 1);

	coin.resize(n);
	coin[0] = '1';
	coin[n-1] = '1';

	while(out.size() != j){
		FWD(i,1,n-1) coin[i] = '0' + dist(eng);
		check();
	}
	return 0;
}
