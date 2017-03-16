#include <cstdio>
#include <algorithm>

using namespace std;

int tc, ttc;
char s[111];
char cur;

int main(){
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    scanf("%d", &tc);
    for(ttc = 1; ttc <= tc; ttc++){
        scanf("%s", s);
        int i = 0;
        cur = '+';
        int ans = 0;
        for(; s[i]; i++);
        for(i--; i >= 0; i--){
            if(cur != s[i]) cur = s[i], ans++;
        }
        printf("case #%d: %d\n", ttc, ans);
    }
}
