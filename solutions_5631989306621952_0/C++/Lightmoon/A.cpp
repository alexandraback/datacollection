#include <bits/stdc++.h>
using namespace std;

int ntest;
string s;
void solve(int test) {
   cout << "Case #" << test+1 << ": ";
   cin >> s;
   string r;
   r = s[0];
   for(int i=1; s[i]; i++){
		if(s[i] >= r[0] ) r = s[i] + r;
		else{
			r += s[i];
		}
   }
   cout << r << endl;
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("test.out", "w", stdout);
    ios::sync_with_stdio(false);
    int ntest;
    cin >> ntest;
    for(int test=0; test< ntest; test++) {
        solve(test);
    }
    return 0;
}

