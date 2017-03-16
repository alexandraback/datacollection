#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char name[9000000];
int cnt[9000000];
int ok[9000000];

inline bool is_vowel(char c){
    switch(c){
        case 'a': return true;
        case 'e': return true;
        case 'i': return true;
        case 'o': return true;
        case 'u': return true;
    }
    return false;
}
int main()
{
    int T;
    scanf("%d", &T);

    for(int tcase=1; tcase <= T; ++tcase){
        int n=0;
        memset(name, 0, sizeof(name));
        memset(cnt, 0, sizeof(cnt));
        memset(ok, 0, sizeof(ok));
        scanf("%s", name);
        scanf("%d", &n);
        int tmp = 0;
        int len = strlen(name);
        int num_ok = 0;
        for(int i=0; i < len; ++i){
            if(is_vowel(name[i]))
                tmp = 0;
            else
                tmp += 1;
            if(tmp >= n){
                ok[num_ok++] = i-n+1;
            }
        }
        sort(ok, ok+num_ok);
        long long ans = 0ll;
        for(int i=0; i < len; ++i){
            int idx = lower_bound(ok, ok+num_ok, i) - ok;
            if(idx == num_ok) continue;
            //printf("%d: %d~%d %d\n", i, ok[idx], ok[idx]+n, len-(ok[idx]+n));
            ans += (len - (ok[idx]+n) + 1);
        }
        printf("Case #%d: %lld\n", tcase, ans);
    }
    return 0;
}
