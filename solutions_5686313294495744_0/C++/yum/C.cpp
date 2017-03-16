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

int main() {
	int TC, N;
	cin >> TC;
	FOR(tc,1,TC+1) {
		unordered_map<string, int> strs;
		vector<PT> vpt;
		cin >> N;
		FOR(n,0,N) {
			string s1, s2;
			cin >> s1 >> s2;
			if (!strs.count(s1)) strs[s1] = (int)strs.size();
			if (!strs.count(s2)) strs[s2] = (int)strs.size();
			vpt.emplace_back(strs[s1], strs[s2]);
		}
		int ans = 0;
		FOR(bs,0,1<<N) {
			bool ld[100] = {}, rd[100] = {};
			FOR(n,0,N) if (bs&(1<<n)) {
				ld[vpt[n].first] = true;
				rd[vpt[n].second] = true;
			}
			bool works = true;
			FOR(n,0,N) if (!(bs&(1<<n))) {
				if (!ld[vpt[n].first] || !rd[vpt[n].second]) {works=false;break;}
			}
			if (works) {
				ans = max(ans, N-__builtin_popcount(bs));
				//cout << bitset<10>(bs) << endl;
			}
		}
		cout << "Case #" << tc << ": " << ans << endl;
	}
}
