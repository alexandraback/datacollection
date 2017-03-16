#include <cstdio>
#include <cstring>

typedef long long ll;

const int MAXN = 2000000;

char str[MAXN];
int A[MAXN];
char vowel['z' + 1];
bool tick[MAXN];

ll calc(){
    for(int i = 0; i < MAXN; ++i){
        A[i] = 0;
        tick[i] = false;
    }
    int k;
    scanf("%s %d", str, &k);
    int len = strlen(str);
    for(int i = 1; i <= len; ++i){
        A[i] = 1 - vowel[str[i - 1]] + A[i - 1];
    }
    int l = 1;
    int r = k;
    int prev = 1;
    ll ans = 0;
    while(r <= len){
        if(A[r] - A[l - 1] == k){
            ans += ll(l - prev + 1) * ll(len - r + 1);
            prev = l + 1;
        }
        l++;
        r++;
    }
    return ans;
}

int main(){
    int t;
    scanf("%d", &t);
    vowel['a'] = 1;
    vowel['e'] = 1;
    vowel['i'] = 1;
    vowel['o'] = 1;
    vowel['u'] = 1;
    for(int i = 1; i <= t; ++i){
        printf("Case #%d: %lld\n", i, calc());
    }
    return 0;
}
