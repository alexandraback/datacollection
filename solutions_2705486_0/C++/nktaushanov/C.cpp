/*
  ID: nigo1
  LANG: C++
  TASK: A
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>

using namespace std;

int T;
char dict[522000][12];
char buffer[12];
int sz[26];

int DP[64];

char s[64];

int cost(char a, char b) {
    if (a == b) return 0;
    if (abs(a - b) < 5) return -1;
    return 1;
}

int main()
{
    freopen ("dict.txt", "r", stdin);
    int cnt = 0;
    while (scanf("%s\n", &buffer) == 1) {
        strcpy(dict[cnt++], buffer);
    }

    freopen ("C-small-attempt0.in", "r", stdin);
    //freopen ("C.out", "w", stdout);

    scanf("%d", &T);
    for (int test = 1; test <= T; test++) {
        memset (DP, -1, sizeof DP);
        DP[0] = 0;
        scanf("%s\n", &s);

        for (int i = 1; i <= strlen(s); i++) {
            for (int j = 0; j < cnt; j++) {
                int k = strlen(dict[j]);
                if (k > i) continue;
                if (DP[i - k] == -1) continue;
                int l = 0;
                int sum = 0;
                for (l = 0; l < k; l++) {
                    int c = cost(dict[j][l], s[i - k + l]);

                    if (c == -1)
                        break;
                    sum += c;
                }

                if (l != k) continue;

                if (DP[i] == -1)
                    DP[i] = sum + DP[i - k];
                else
                    DP[i] = min(DP[i], sum + DP[i - k]);
            }
        }

        printf("Case #%d: %d\n", test, DP[strlen(s)]);
    }

    return 0;
}

