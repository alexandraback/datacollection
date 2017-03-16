#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <initializer_list>

using namespace std;

int C = 0, D = 0, V = 0;
int pre[64] = {0};
bool label[64] = {false};
bool dom[64] = {false};
int cnt = 0;
int res = 1024;

void dfs(int depth, int add) {
    if (depth > V) {
        res = std::min(res, add);
        return;
    } else {
        if (label[depth] == false) {
            bool orig_label[64] = {false};
            memcpy(orig_label, label, sizeof(label));
            
            for (int i = 0; i < depth; i++) {
                if (label[i] == true) {
                    int newone = depth - i;
                    if (dom[newone] == false) {
                        dom[newone] = true;
                        for (int j = V; j >= 0; j--) {
                            if (label[j] && j + newone <= V) {
                                label[j + newone] = true;
                            }
                        }
                        dfs(depth + 1, add + 1);
                        memcpy(label, orig_label, sizeof(label));
                        dom[newone] = false;
                    }
                }
            }
        } else {
            dfs(depth + 1, add);
        }
    }
}

int main(int argc, char *argv[])
{
    int T = 0;

    if (argc > 1) {
        freopen(argv[1], "r", stdin);
    }
    
    scanf("%d", &T);

    for (int cas = 1; cas <= T; cas++) {
        memset(pre, 0, sizeof(pre));
        res = 1024;
        scanf("%d %d %d", &C, &D, &V);
        
        for (int i = 0; i < D; i++) {
            scanf("%d", &pre[i]);
        }

        if (C == 1) {
            cnt = 0;
            memset(label, false, sizeof(label));
            memset(dom, false, sizeof(dom));
            
            for (int i = 0; i < D; i++) {
                label[pre[i]] = true;
                dom[pre[i]] = true;
            }

            label[0] = true;
            for (int mask = 0; mask < (1 << D); mask++) {
                int num = mask;
                int idx = 0;
                int r = 0;
                while (num) {
                    if (num & 1) {
                        r += pre[idx];
                    }
                    idx++; num /= 2;
                }

                if (r <= V) {
                    label[r] = true;
                }
            }

            dfs(0, 0);
        }
        
        printf("Case #%d: %d\n", cas, res);
    }

    return 0;
}
