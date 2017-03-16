#include <cstdio>
#include <iostream>

using namespace std;

const int N = 100;

char ans[N][N];

void addEdge(int from, int to) {
    ans[from][to] = '1';
}

bool cal(int building, long long age) {
    long long maxV = 1LL << (building - 2);
    if (age > maxV) {
        return false;
    }
    for (int i = 0; i < building; ++i) {
        for (int j = 0; j < building; ++j) {
            ans[i][j] = '0';
        }
        ans[i][building] = '\0';
    }
    if (age == maxV) {
        for (int i = 0; i < building; ++i) {
            for (int j = i + 1; j < building; ++j) {
                addEdge(i, j);
            }
        }
        return true;
    }
    
    for (long long i = 1, cnt = age; cnt; cnt >>= 1, ++i) {
        if (cnt & 1) {
            addEdge(i, building - 1);
        }
        for (int j = 0; j < i; ++j) {
            addEdge(j, i);
        }
    }
    return true;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        long long b, m;
        cin >> b >> m;
        bool res = cal(b, m);
        printf("Case #%d: %s", (i + 1), (res ? "POSSIBLE" : "IMPOSSIBLE"));
        if (res) {
            printf("\n");
            for (int i = 0; i < b; ++i) {
                printf("%s", ans[i]);
                if (i + 1 < b) {
                    printf("\n");
                }
            }
        }
        if (i + 1 < T) {
            printf("\n");
        }
    }
    return 0;
}