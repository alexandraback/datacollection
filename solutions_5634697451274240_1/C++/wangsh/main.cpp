#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

const int N = 110;
char s[N] = {};

void flip(char *s, int len) {
    for (int i = 0; i < len; ++i) s[i] = '-'+'+'-s[i];
    for (int i = 0, j = len-1; i < j; ++i, --j) {
        swap(s[i], s[j]);
    }
}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int cas;
    scanf(" %d", &cas);
    for (int i = 0; i < cas; ++i) {
        int ret = 0;
        scanf("%s", s);
        int l = strlen(s);
        while (l > 0) {
//            printf("%s\n", s);
            if (s[l-1] == '+') {
                --l;
                continue;
            }
            ++ret;
            if (s[0] == '-') flip(s, l);
            else {
                for (int j = 0; j < l; ++j)
                    if (s[j] == '+') s[j] = '-';
                    else break;
            }
        }
        printf("Case #%d: %d\n", i+1, ret);
    }
    return 0;
}
