#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

using namespace std;

char fl(char c) {
	if(c == '+') return '-';
	return '+';
}

void flip(string& m, int k) {
	for(int i = 0; i < k/2; ++i)
		swap(m[i],m[k-1-i]);
	for(int i = 0; i < k; ++i)
		m[i] = fl(m[i]);
}

int getans(string s) {
	string tgt(s.size(),'+');
	int f = 0;
	int b = s.size()-1;
	while(s != tgt) {
		if(s[0] == '+') {
			int a = 1;
			while(a < s.size() && s[a] == '+')
				++a;
			++f;
			flip(s,a);
		} else {
			while(s[b] == '+')
				--b;
			++f;
			flip(s,b+1);
		}
	}
	return f;
}

int main() {
	ios::sync_with_stdio(0);
  // freopen("b.in","r",stdin);
  freopen("bb.txt","w",stdout);
  int T;
  cin >> T;
  for(int t = 1; t <= T; ++t) {
    string s;
    cin >> s;
    cout << "Case #" << t << ": " << getans(s) << "\n";
  }

	return 0;
}