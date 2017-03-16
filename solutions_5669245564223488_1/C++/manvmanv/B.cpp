#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;
typedef int typec;

#define MAXN 105
#define INF 0x3f3f3f3f
#define MOD 1000000009

int A[MAXN];

int main(void) {
    FILE *fp, *fp2;
    freopen_s(&fp, "B-small-attempt0.in", "r", stdin);
    freopen_s(&fp2, "B.out", "w", stdout);
    int nCase;
    while (cin >> nCase) {
        A[0] = 1;
        for (int i = 1; i < MAXN; ++i) {
            A[i] = (int)((LL)A[i - 1] * i % MOD);
        }
        for (int cas = 1; cas <= nCase; ++cas) {
            int N;
            cin >> N;
            string str;
            vector<string> vec;
            for (int i = 0; i < N; ++i) {
                cin >> str;
                vec.push_back(str);
            }
            bool vis[MAXN][MAXN];
            int nArray[MAXN];
            int nNum[5];
            bool result = true;
            int ans = 1;
            int nTotal = N;

            memset(vis, true, sizeof(vis));
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                memset(nNum, 0, sizeof(nNum));
                int ID[2];
                for (int i = 0; i < vec.size(); ++i) {
                    int nSum = 0;
                    bool bFlag = false;
                    for (int j = 0; j < vec[i].length(); ++j) {
                        if (ch == vec[i][j]) {
                            if (!bFlag) {
                                bFlag = true;
                                ++nSum;
                            }
                        }
                        else {
                            bFlag = false;
                        }
                    }
                    if (nSum >= 2) {
                        result = false;
                        break;
                    }
                    else if (nSum == 1) {
                        if (vec[i][0] == ch && vec[i][vec[i].length() - 1] == ch) {
                            nArray[i] = 2;
                        }
                        else if (vec[i][0] == ch) {
                            nArray[i] = 4;
                            ID[1] = i;
                        }
                        else if (vec[i][vec[i].length() - 1] == ch) {
                            nArray[i] = 1;
                            ID[0] = i;
                        }
                        else {
                            nArray[i] = 0;
                        }
                        ++nNum[nArray[i]];
                    }
                }
                if (nNum[0] && (nNum[1] + nNum[2] + nNum[4]) > 0) {
                    result = false;
                    break;
                }
                if (nNum[2]) {
                    ans = (int)((LL)ans * A[nNum[2]] % MOD);
                    nTotal -= nNum[2] - 1;
                }
                if (nNum[1] == 1 && nNum[4] == 1) {
                    if (!vis[ID[0]][ID[1]]) {
                        result = false;
                        break;
                    }
                    if (nNum[2]) {
                        nTotal -= 2;
                    }
                    else {
                        nTotal--;
                    }
                    vis[ID[0]][ID[1]] = vis[ID[1]][ID[0]] = false;
                }
                else if (nNum[1] == 1 && nNum[4] == 0) {
                    if (nNum[2]) {
                        --nTotal;
                    }
                }
                else if (nNum[1] == 0 && nNum[4] == 1) {
                    if (nNum[2]) {
                        --nTotal;
                    }
                }
                else if (nNum[1] == 0 && nNum[4] == 0) {
                    continue;
                }
                else {
                    result = false;
                    break;
                }
            }
            ans = (int)((LL)ans * A[nTotal] % MOD);
            if (!result) {
                ans = 0;
            }
            printf("Case #%d: ", cas);
            printf("%d\n", ans);
        }
    }
    return 0;
}