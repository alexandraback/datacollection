#include<stdio.h>
#include<string.h>
#define LEN 1000
int sn, st1n, st2n;
char str[LEN+5], str1[LEN+5], str2[LEN+5];
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T, t = 1;
    for(scanf("%d", &T); (T--); ++t) {
        scanf("%s", str); sn = strlen(str); st1n = st2n = 0;
        for(int i = 'Z'; i >= 'A'; --i) {
            while(1) {
                int j = sn-1;
                for(; j >= 0; --j) {
                    if(str[j] == i) {
                        str1[st1n++] = str[j];
                        for(int k = sn-1; k > j; --k) str2[st2n++] = str[k];
                        sn = j;
                        break;
                    }
                }
                if(j < 0) break;
            }
        }
        str1[st1n] = str2[st2n] = NULL;
        printf("Case #%d: %s", t, str1);
        for(int i = st2n-1; i >= 0; --i) printf("%c", str2[i]);
        printf("\n");
    }
    return 0;
}
