#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <utility>
#include <cctype>
#include <list>
#include <bitset>

using namespace std;

#define FORALL(i,a,b) for(int i=(a);i<=(b);++i)
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORB(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef long double ld;
typedef complex<ld> vec;

typedef pair<int,int> pii;
typedef map<int,int> mii;

#define pb push_back
#define mp make_pair

#define MAXN 2005
#define ALPHA 256

string words[] = {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT", "NINE"};
int ord[] = {0,6,8,3,2,4,5,7,9,1};
char S[MAXN];
int cnt[ALPHA];
char s[MAXN];

bool try_apply(int d) {
	string s = words[d];
	map<char,int> occs;
	FOR(x,s.length()) occs[s[x]]++;
	for (const auto & p : occs) {
		char c = p.first;
		int t = p.second;
		if (cnt[c] < t) return false;
	}

	for (const auto& p : occs) {
		char c = p.first;
		int t = p.second;
		cnt[c] -= t;
		assert(cnt[c] >= 0);
	}

	return true;
}

string solve() {
	scanf("%s",&S[0]);
	int N = strlen(S);

	memset(cnt,0,sizeof(cnt));
	FOR(i,N) cnt[S[i]]++;
	memset(s,0,sizeof(s));

	int K = 0;
	while(true) {
		bool found = false;
		FOR(i,10) {
			int d = ord[i];
			if (try_apply(d)) {
				s[K++] = (char)('0'+d);
				found = true;
				break;
			}
		}
		if (!found) break;
	}

	assert(K);
	FOR(i,ALPHA) assert(cnt[i] == 0);

	sort(s,s+K);
	return s;
}

int main() {
	// SANITY CHECK
	set<char> seen;
	FORB(i,9,0) {
		int d = ord[i];
		string w = words[d];
		bool found = false;
		FOR(x,(int)w.length()) {
			char c = w[x];
			if (!seen.count(c)) {
				found = true;
				seen.insert(c);
			}
		}
		assert(found);
	}

	
	int TEST;
	scanf("%d",&TEST);
	FOR(test,TEST) {
		string ans = solve();
		printf("Case #%d: %s\n", test+1, ans.c_str());
	}

}































