#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

typedef long long LL;

const int MAXN = 1000100;
char str[MAXN];
bool f[300];

int len[MAXN], rt[MAXN];

int main(){
    freopen("A-large.in", "r", stdin);
    freopen("large.out", "w", stdout);

    memset(f, 0, sizeof(f));
    f['a'] = f['e'] = f['i'] = f['o'] = f['u'] = 1;
    int test, cas(1);

    scanf("%d", &test);
    while(test--){
        int m, n;
        scanf("%s%d", str, &m);
        n = strlen(str);

        for(int i = 0, j = 0; i < n; ++i){
            if(f[str[i]])  j = 0;
            else  ++j;
            len[i] = j;

        }
        for(int i = n - 1, j = -1; i >= 0; --i){
            if(len[i] >= m)  rt[i] = i, j = i;
            else {
                rt[i] = j;
            }
        }
        LL ans(0);
        for(int i = 0; i < n; ++i){
            if(i + m - 1 >= n)   break;
            else if(rt[i + m - 1] == -1)  break;
            else{
                ans += n - rt[i + m - 1];
            }
        }
        printf("Case #%d: %I64d\n", cas++, ans);
    }


    return 0;
}
