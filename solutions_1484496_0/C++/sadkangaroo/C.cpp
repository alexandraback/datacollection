#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<cctype>
#include<climits>
#include<algorithm>
#include<complex>
#include<vector>
#include<queue>
#include<set>
#include<map>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;

const int MaxN = 20 + 5;

int T, N;
int a[MaxN];
pii num[(1 << 20) + 100];
int top;

void pushIt(int sta) {
    int tmp = 0;
    for (int i = 0; i < N; ++i)
        if (sta & (1 << i)) tmp += a[i];
    num[top++] = pii(tmp, sta);
}

void Out(int sta) {
    bool fst = true;
    for (int i = 0; i < N; ++i) if (sta & (1 << i)) {
        if (fst) {printf("%d", a[i]); fst = false;}
        else printf(" %d", a[i]);
    }
    puts("");
}

int main() {

    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);

    scanf("%d", &T);
    for (int te = 1; te <= T; ++te) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) scanf("%d", a + i);
        top = 0;
        for (int sta = 1; sta < (1 << N); ++sta) {
            pushIt(sta);
        }
        sort(num, num + top);
        bool found = false; int s1, s2;
        for (int i = 0; i + 1 < top; ++i)
            if (num[i].first == num[i + 1].first) {
                found = true;
                s1 = num[i].second; s2 = num[i + 1].second;
                break;
            }
        printf("Case #%d:\n", te);
        if (found) {
            Out(s1);
            Out(s2);
        }
        else puts("Impossible");

    }

    return 0;

}

