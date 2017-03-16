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

bool cn(string s) {
	for(int i = 0 ;i < s.sz; i++)
		if(voc.find(s[i]) != voc.end()) return false;

	return true;
}
bool can(string s, int len) {
	string now;
	if(len > s.sz) return false;
	for(int i = 0; i < len; i++)
		now += s[i];

	if(cn(now)) return true;
	for(int i = len; i < s.sz; i++) {
		now.erase(now.begin());
		now += s[i];
		if(cn(now)) return true;
	}
	return false;
}
void solve() {
	int ans = 0, n;
	string s;
	cin >> s >> n;
	for(int i = 0; i < s.sz; i++) {
		for(int j = i + 1; j < s.sz; j++) {
			if(can(s.substr(i, j - i + 1), n)) ans++;
			
		}
	}
	printf("%d\n", ans);
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