#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <ctime>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define sz(s) (int)(s).size()
using namespace std;

inline string toString(int a){
	string s = "";
	while(a > 0)
		s.push_back(a%10 + '0'), a/= 10;
	if(s.empty())
		s.push_back('0');
	reverse(s.begin(), s.end());
	return s;
}
inline int toInt(const string & s){
	int a = 0;
	forn(i, sz(s))
		a =  a * 10 + s[i] - '0';
	return a;
}
int main(){
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int t;
	cin >> t;
	set<pair<int, int> > ss;
	forn(step, t){
		ss.clear();
		int a, b;
		cin >> a >> b;
		int ans = 0;
		for(int c = a; c <= b; c++){
			string cs = toString(c);
			forn(i, sz(cs)-1){
				string cc = "";
				cc += cs[sz(cs) - 1];
				cs.erase(sz(cs) - 1, 1);
				cs.insert(0, cc);
				int csi = toInt(cs);
				if(csi < c && csi >= a){
					
					ss.insert(make_pair(csi, c));
					ans++;
				}
			}
		}
		ans =sz(ss);
		cout << "Case #" << step + 1 << ": " << ans << endl;
	}
	
	return 0;
}