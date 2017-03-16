#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <string>
#include <set>
#define inf 0x3f3f3f3f

using namespace std;

set<string> dict;

int main(void) {
    freopen("input.txt", "r", stdin);
    FILE *df = fopen("garbled_email_dictionary.txt", "r");
    int t, T, ans, n, i, j, k, r, kk;
    char str[55], ch, chch;
    int dp[55][55];
    string s;

    i = 0;
    while(fscanf(df, "%s", str)) {
        // i++;
        // if ( i == 200000 ) break;
        dict.insert(str);
        assert(strlen(str) <= 10 && strlen(str) > 0);
        if (feof(df)) break;
    }

    scanf("%d\n", &T);

    for (t=1; t<=T; ++t) {
        int ans = 0;

        scanf("%s", &str[1]);
        n = strlen(&str[1]);
        assert(n <= 50);
        /* printf("%s\n", &str[1]); */

        memset(dp, 0x3f, sizeof(dp));
        for (i=0; i<=n; ++i) dp[0][i] = 0;

        for (i=1; i<=n; ++i) {
            for (j=1; j<=min(10, i); ++j) {
                s = "";
                for (k=j; k>=1; --k) {
                    s += str[i-k+1];
                }
                /* printf("--------- %d %d %s -------\n", i, j, s.c_str()); */
                if ( dict.find(s) != dict.end() ) {
                    for (r=0; r<=n; ++r) {
                        dp[i][r] = min(dp[i][r], dp[i-j][min(r,i-j)]);
                    }
                    /* printf("found! %d %s\n", i-j+1, s.c_str()); */
                }
                /* else { */
                    /* k: se poio simeio ths lekshs tha ginei h
                     * allagh */
                    for (k=1; k<=j; ++k) {
                        char temp = s[k-1];
                        for (ch='a'; ch<='z'; ch++) {
                            s[k-1] = ch;
                            if ( dict.find(s) != dict.end() ) {
                                for (r=i-j+k; r<=n; ++r) {
                                    dp[i][r] = min(dp[i][r], dp[i-j][max(i-j+k-5,0)] + 1);
                                }
                                /* printf("found! %d %s\n", i-j+1, s.c_str()); */
                            }
                        }
                        s[k-1] = temp;
                    }
                    for (kk=1; kk<=j; ++kk) {
                        for (k=kk+5; k<=j; ++k) {
                            char temptemp = s[kk-1];
                            char temp = s[k-1];
                            for (chch='a'; chch<='z'; chch++) {
                                s[kk-1] = chch;
                                for (ch='a'; ch<='z'; ch++) {
                                    s[k-1] = ch;
                                    if ( dict.find(s) != dict.end() ) {
                                        for (r=i-j+k; r<=n; ++r) {
                                            dp[i][r] = min(dp[i][r], dp[i-j][max(i-j+kk-5,0)] + 2);
                                        }
                                        /* printf("found! %d %s\n", i-j+1, s.c_str()); */
                                    }
                                }
                            }
                            s[k-1] = temp;
                            s[kk-1] = temptemp;
                        }
                    }
                /* } */
            }
        }

        // for (i=1; i<=n; ++i) {
        //     printf("---- %d ----\n", i);
        //     for (j=1; j<=n; ++j) {
        //         printf("%d (%d)   ",  j, dp[i][j]);
        //     }
        //     printf("\n");
        // }

        printf("Case #%d: %d\n", t, dp[n][n]);
    }

    return 0;
}
