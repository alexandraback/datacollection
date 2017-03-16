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

int ODN[] = {0,8,4,6,5,7,2,3,9,1};
string OD[] = {"ZERO", "EIGHT", "FOUR", "SIX", "FIVE", "SEVEN", "TWO", "THREE", "NINE", "ONE"};

int main() {
	int TC;
	cin >> TC;
	FOR(tc,1,TC+1) {
		string s, ans;
		cin >> s;
		int ltr[256] = {}, rml=0;
		for (char c : s) {ltr[c]++; rml++;}
		while (rml) {
			FOR(k,0,10) {
				int c3[256] = {};
				for (char c : OD[k]) c3[c]++;
				bool works = true;
				FOR(i,0,256) if (ltr[i] < c3[i]) works=false;
				if (!works) continue;
				ans += char(ODN[k]+'0');
				FOR(i,0,256) {ltr[i] -= c3[i]; rml -= c3[i];}
				break;
			}
		}
		sort(begin(ans), end(ans));
		cout << "Case #" << tc << ": " << ans << endl;
	}
}
