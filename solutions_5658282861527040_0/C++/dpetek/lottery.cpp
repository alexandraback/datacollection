#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int pairs[1001][1001];

int main(void)
{
    freopen("B-small.in", "r", stdin);
    freopen("B-small.out", "w", stdout);

//    freopen("B-large.in", "r", stdin);
//    freopen("B-large.out", "w", stdout);

    int tests;

    scanf("%d", &tests);

    for (int test=1;test<=tests;++test) {
        int a, b, k;

        for (int i=0;i<=1000;++i)
            for(int j=0;j<=1000;++j)
                pairs[i][j] = -1;

        scanf ("%d %d %d", &a, &b, &k);
        int cnt = 0;
        for (int i=0;i<a;++i) {
            for (int j=0;j<b;++j) {
                if (pairs[i][j] == -1 && (i&j) < k) {
                    pairs[i][j] = 1;
                    cnt ++;
                }
            }
        }

        printf("Case #%d: %d\n", test, cnt);
    }
    return 0;
}
