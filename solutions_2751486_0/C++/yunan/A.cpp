#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
int n;
int t, len;
string s;
int q[1000006];
int l, r;
long long ans;
int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> t;
    string s;
    int tmp, pre, now, tt = 0;
    for (;t;--t){
        cin >> s >> n;
        len = s.size();
        q[0] = 0; ans = 0;pre = -1; now = 0;tmp = 0;
        bool has = false;
        for (int i = 0; i < len; ++i) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
              tmp = 0;
           } else {
                tmp = tmp + 1;
                if (tmp >= n) {
                    has = true;
                    now = i - n + 1;
                }
            }
            if (has) {
                ans = ans + now + 1;
            }
        }
        cout << "Case #"<< ++tt << ": " << ans <<endl;
    }
    return 0;
}
