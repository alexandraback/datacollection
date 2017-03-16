#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
using namespace std;
 
#define mp make_pair
#define X first
#define Y second
#define pb push_back
#define sz size()
#define sqr(x) (x) * (x)
#define all(x) (x).begin(), (x).end()

set<char> voc;

void solve() {
	int n;
	long long ans = 0;
	int from, len, prev = -1;
	string s, now;
	set<pair<int,int> > pos;

	cin >> s >> n;
	for(int i = 0; i < s.sz; i++) {
		now += s[i];
		if(voc.find(s[i]) != voc.end()) {
			if(now.sz >= n) {
				pos.insert(mp(i - now.sz + 1, now.sz - 1));
			}
			now.clear();
		} 
	}
	if(now.sz >= n) {
		pos.insert(mp(s.sz - now.sz, now.sz));
	}

	for(set<pair<int,int> >::iterator it = pos.begin();  it != pos.end(); it++) {
		from = it->X;
		len = it->Y;
		for(int j = 0; j <= len - n; j++) {
			ans += (from + j - (prev + 1) + 1) * (s.sz - (from + j + n) + 1);
			prev = from + j;
		}
	}

	printf("%lld\n", ans);
}
void OJ() {
	voc.insert('a');
	voc.insert('e');
	voc.insert('i');
	voc.insert('o');
	voc.insert('u');
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
        solve();
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    OJ();
    //solve();
    return 0;
}