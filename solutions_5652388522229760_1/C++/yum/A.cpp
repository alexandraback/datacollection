#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<int(b);i++)
typedef long long LL;
typedef pair<int,int> PT;
typedef vector<int> VI;
typedef vector<VI> VVI;
template<typename T> ostream& operator<<(ostream& s, vector<T>& v)
{ s << '{'; FOR(i,0,v.size()) s << (i ? "," : "") << v[i]; return s << '}'; }
template<typename S, typename T> ostream& operator<<(ostream &s, pair<S,T> const& p)
{ return s << '(' << p.first << ',' << p.second << ')'; }

int gd(LL n) {
	int a = 0;
	while (n) {
		a |= (1<<(n%10));
		n /= 10;
	}
	return a;
}

LL sv(LL n) {
	LL m = n;
	int seen = gd(m);
	while (seen != (1<<10)-1) {
		m += n;
		seen |= gd(m);
	}
	return m;
}

int main() {
	int TC, N;
	scanf("%d", &TC);
	FOR(tc,1,TC+1) {
		scanf("%d", &N);
		printf("Case #%d: ", tc);
		if (!N) {
			puts("INSOMNIA");
		} else {
			printf("%lld\n", sv(N));
		}
	}
}
