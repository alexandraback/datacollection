//By Brickgao
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
#define LL long long
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int t, caseno = 1;
LL a, b, sa, sb, ans;
char s[50];

int main() {
    cin >> t;
    while(t --) {
        ans = 0;
        cin >> a >> b;
        sa = sqrt(a), sb = sqrt(b);
        if(sa * sa != a)    sa ++;
        for(LL i = sa; i <= sb; i ++) {
            bool flag1 = true, flag2 = true;
            LL tmp = i * i;
            sprintf(s, "%I64d", tmp);
            for(int j = 0; j < (int)strlen(s) / 2; j ++) {
                if(s[j] != s[(int)strlen(s) - j - 1]) {
                    flag1 = false;
                }
            }
            sprintf(s, "%I64d", i);
            for(int j = 0; j < (int)strlen(s) / 2; j ++) {
                if(s[j] != s[(int)strlen(s) - j - 1]) {
                    flag2 = false;
                }
            }
            if(flag1 && flag2) {
                ans ++;
            }
        }
        printf("Case #%d: ", caseno ++);
        cout << ans << endl;
    }
    return 0;
}

