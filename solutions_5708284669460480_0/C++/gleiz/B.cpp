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
#include <initializer_list>

using namespace std;

char keyboard[16] = {0};
char target[16] = {0};

char current[16] = {0};

double cnt = 0;
double sum = 0;
double maxnum = 0.0;
int K = 0, L = 0, S = 0;

void dfs1(int depth) {
    if (depth == S) {
        double found = 0;
        for (int i = 0; i < S && i + L <= S; i++) {
            bool t = true;
            for (int j = i; j < i + L; j++) {
                if (current[j] != target[j - i]) {
                    t = false;
                    break;
                }
            }

            if (t) found += 1.0;
        }

        maxnum = std::max(maxnum, found);
        cnt += 1.0;
    } else {
        for (int i = 0; i < K; i++) {
            current[depth] = keyboard[i];
            dfs1(depth + 1);
        }
    }
}

void dfs2(int depth) {
    if (depth == S) {
        double found = 0;
        for (int i = 0; i < S && i + L <= S; i++) {
            bool t = true;
            for (int j = i; j < i + L; j++) {
                if (current[j] != target[j - i]) {
                    t = false;
                    break;
                }
            }

            if (t) found += 1.0;
        }

        sum += (maxnum - found);
    } else {
        for (int i = 0; i < K; i++) {
            current[depth] = keyboard[i];
            dfs2(depth + 1);
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
        memset(keyboard, 0, sizeof(keyboard));
        memset(target, 0, sizeof(target));
        memset(current, 0, sizeof(current));
        
        scanf("%d %d %d", &K, &L, &S);
        scanf("%s", keyboard);
        scanf("%s", target);

        sum = 0.0;
        cnt = 0.0;
        maxnum = 0.0;
        
        dfs1(0);
        dfs2(0);

        printf("Case #%d: %.8lf\n", cas, sum / cnt);
    }

    return 0;
}
