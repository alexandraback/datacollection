#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <utility>
#include <stack>
#include <functional>
#include <set>
#include <stdlib.h>
#define INF 0x3f3f3f3f
#define clc(x) memset(x, 0, sizeof(x))
using namespace std;
typedef long long ll;
int N, J, T;
const int mxn = 32;
int b[mxn];
int x1[26][6];
int x2[26][6];
int main()
{
    int kase = 1;
    clc(b);
    int s1[15] = {1,3,5,7,9,11,13,15,17,19,21,23,25,27,29};
    int s2[15] = {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30};
    int cnt = 5;
    // freopen("/Users/akanork/desktop/1.in", "r", stdin);
    // freopen("/Users/akanork/desktop/1.out", "w", stdout);
    scanf("%d", &T);
    scanf("%d %d", &N, &J);
    while (T--) {
        for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            x1[i][j] = s1[j];
            x2[i][j] = s2[j];
        }
        x1[i][5] = s1[cnt];
        x2[i][5] = s2[cnt];
        cnt++;
        }
        cnt = 6;
        for (int i = 10; i < 19; i++) {
            for (int j = 0; j < 5; j++) {
                x1[i][j] = s1[j + 1];
                x2[i][j] = s2[j + 1];
            }
            x1[i][5] = s1[cnt];
            x2[i][5] = s2[cnt];
            cnt++;
        }
        cnt = 7;
        for (int i = 19; i < 26; i++) {
            for (int j = 0; j < 5; j++) {
                x1[i][j] = s1[j + 2];
                x2[i][j] = s2[j + 2];
            }
            x1[i][5] = s1[cnt];
            x2[i][5] = s2[cnt];
            cnt++;
        }
        //     for (int i = 0; i < 26; i++) {
        //     for (int j = 0; j < 6; j++) {
        //         printf("%d ", x1[i][j]);
        //     }
        //     printf("\n");
        // }
        //     for (int i = 0; i < 26; i++) {
        //     for (int j = 0; j < 6; j++) {
        //         printf("%d ", x2[i][j]);
        //     }
        //     printf("\n");
        // }
        cnt = 0;
        bool flag = true;
        printf("Case #%d:\n", kase++);
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (cnt >= J) {
                    flag = false;
                    break;
                }
                for (int k = 0; k < 6; k++) {
                    b[x1[i][k]] = 1;
                    b[x2[j][k]] = 1; 
                }
                printf("1");
                for (int i = 1; i <= 30; i++) {
                    printf("%d", b[i]);
                }
                printf("1 ");
                printf("3 2 5 2 7 2 7 2 11\n");
                cnt++;
                clc(b);
            }
            if (!flag) break;
        }
    


    }
    



return 0;
}