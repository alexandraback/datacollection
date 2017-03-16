#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int cas, CAS, l, i, now, n, h, f;
char s[1000005];

int ck(int i){
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') return 1;
    return 0;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    scanf("%d", &CAS);
    for (cas = 1; cas <= CAS; cas++){
        scanf("%s %d", s + 1, &n);
        l = strlen(s + 1);
        long long ans = 0;
        now = f = h = 0;
        for (i = 1; i <= l; i++){
            if (ck(i)) now = 0; else now++;
            if (now >= n){
                h = i - now + 1;
                f = now;
            }
            if (f >= n) ans += h + f - n;
        }
        //cout << ans << endl;
        printf("Case #%d: %lld\n", cas, ans);
    }

}
