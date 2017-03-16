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

string C, J;
int N, PF;

bool is_match(string const& s, int a) {
	string t = to_string(a);
	while (t.size() < N) t = "0" + t;
	FOR(n,0,N) if (s[n] != '?' && s[n] != t[n]) return false;
	return true;
}

int main() {
	int TC;
	cin >> TC;
	FOR(tc,1,TC+1) {
		cin >> C >> J;
		N = (int)C.size();

		int mx = 1;
		FOR(i,0,N) mx *= 10;

		int bestC=-1, bestJ=-1;
		FOR(a,0,mx) FOR(b,0,mx) if (is_match(C, a) && is_match(J,b)){
			LL md = abs(a-b);
			LL td = abs(bestC-bestJ);
			if (bestC == -1 || md < td || (md==td && a<bestC) || (md==td && a==bestC && b<bestJ)) {
				bestC = a;
				bestJ = b;
			}
		}

		cout << "Case #" << tc << ": " << setw(N) << setfill('0') << bestC << ' ' << setw(N) << bestJ << endl;
	}
}
