#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cfloat>
#include <climits>
#include <numeric>

using namespace std;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORS(i,a,b,s) for (int i = (a); i < (b); i=i+(s))
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)

const double PI = 2.0 * acos(0.0);

string int_to_str(int v) {
	ostringstream os;
	os << v;
	return os.str();
}

int str_to_int(string s) {
	istringstream is(s);
	int v;
	is >> v;
	return v;

}

int n;
map<string, int> cars;
vector<string> beg[26];
vector<string> end[26];
int only[26];
char follower[26];
char before[26];
bool letter[26];
bool vis[26];
vi used;
ll bp = 1000000007;
void reset(){
	cars.clear();
	used.clear();
	FOR(i, 0, 26){
		only[i] = 0;
		follower[i] = 'A';
		before[i] = 'A';
		letter[i] = false;
		vis[i] = false;
	}
}

void rem(char c){
	vi::iterator it = used.begin();
	for(;it!=used.end(); it++){
		if(c == *it){
			used.erase(it);
			return;
		}
	}
}

ll fac(ll base, int n){
	ll erg = base;
	FOR(i, 1, n+1) erg *=i%bp;
	return erg%bp;
}

ll calc(){
	vector<ll> vals;
	int counter = 0;
	while(sz(used)){
		counter++;
		ll val = 1;
		char cur = used[0];
		while(true){
			if(before[cur]!='A') {
				if(vis[cur]) return 0;
				vis[cur] = true;
				cur = before[cur]-'a';
			}
			else break;
		}
		rem(cur);
		val = fac(val, only[cur]);
		while(true){
			if(follower[cur]!='A'){
				cur = follower[cur]-'a';
				rem(cur);
				val = fac(val, only[cur]);
			}else break;
		}
		vals.push_back(val);
	}
	ll erg = vals[0];
	FOR(i, 1, sz(vals)) erg *= vals[i]%bp;
	erg *= fac(1, sz(vals)) % bp;
	return erg;
}

int main() {
	int tc;
	cin >> tc;
	FOR(cas, 1, tc+1){
		cin >> n;
		bool broken = false;
		reset();
		FOR(i, 0, n){
			string s;
			cin >> s;	
			if(broken) continue;
			set<char> ch;
			vector<char> buf;
			buf.push_back(s[0]);
			letter[s[0]-'a'] = true;
			FOR(j, 1, sz(s)){
				if(ch.count(s[j]) && s[j-1]!=s[j]) broken = true;
				if(s[j-1]!= s[j]) ch.insert(s[j-1]), buf.push_back(s[j]);
				letter[s[j]-'a'] = true;
			}
			if(sz(buf)==1) only[buf[0]-'a']++;
			else{
				FOR(i, 0, sz(buf)-1){
					if(follower[buf[i]-'a'] != 'A') broken = true;
					follower[buf[i]-'a'] = buf[i+1];
					before[buf[i+1]-'a'] = buf[i];
				}
			}
		}
		cout << "Case #" << cas <<": ";
		if(broken){
			cout << 0 << endl;
			continue;
		}
		FOR(i, 0, 26){
			if(letter[i]) used.push_back(i);
		}
		ll erg = calc();
		cout << erg << endl;
	}
}