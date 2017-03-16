#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1000100;

char ans[MAXN * 5];

int main(){

    freopen("B-small-attempt0.in", "r", stdin);
    freopen("small.out", "w", stdout);

    int test, cas(1);
    int px, py;
    scanf("%d", &test);
    while(test--){
        scanf("%d%d", &px, &py);
        char e = 'E', w = 'W', n = 'N', s = 'S';
        if(px < 0) swap(e, w);
        if(py < 0) swap(n, s);
        int len(0);
        printf("Case #%d: ", cas++);
        for(int i = 0; i < 2 * abs(px); ++i){
            if(i & 1)  ans[len++] = e;
            else  ans[len++] = w;
        }
        for(int i = 0; i < 2 * abs(py); ++i){
            if(i & 1)  ans[len++] = n;
            else ans[len++] = s;
        }
        for(int i = 0; i < len; ++i)  printf("%c", ans[i]);
        puts("");
    }

    return 0;
}
