#include <bits/stdc++.h>
using namespace std;
#define W << " " <<
const int MOD = (int) 1e9 + 7;
const double eps = 1e-8, pi = acos(-1);
void MAIN();
int main(){
    //freopen("input.txt", "r", stdin);
    ios:: sync_with_stdio(false); cin.tie(0);
    MAIN();
    return 0;
}


void MAIN() {
    int nTest;
    cin >> nTest;
    for (int cs = 1; cs <= nTest; cs ++) {
        string s, a, b;
        cin >> s;
        int n = s.size();
        vector <char> maxPrefix(n, s[0]);
        for (int i = 1; i < n; i ++)    maxPrefix[i] = max(maxPrefix[i-1], s[i]);
        for (int i = n-1; i >= 0; i --) {
            if (s[i] == maxPrefix[i])   a += s[i];
            else                        b += s[i];
        }
        reverse(b.begin(), b.end());
        cout << "Case #" << cs << ": " << a + b << "\n";
        cerr << "Case #" << cs << ": " << a + b << "\n";
    }
}
