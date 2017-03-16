#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

#define FORALL(a,b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)
#define FOR(i,a,b) for(int i = a; i < (int)(b); ++i)

typedef long long LL;

const double EPS = 1e-6;
const int INF = 1<<29;
const int N = 1010;

int n;
int a[N], b[N], remain[N];

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);

    int t, cas = 0;
    scanf("%d", &t);

    while (t--){
        scanf("%d", &n);
        for (int i = 0; i < n; ++i){
            scanf("%d %d", &a[i], &b[i]);
            remain[i] = 2;
        }
        int ans = 0;
        int rating = 0;;
        while (rating != n*2){
            int mark = -1;
            for (int i = 0; i < n; ++i){
                if (!remain[i]) continue;
                if (rating >= b[i]){
                    ++ans;
                    rating += remain[i];
                    remain[i] = 0;
                    mark = 0;
                }
            }
            if (!mark) continue;
            mark = -1;
            for (int i = 0; i < n; ++i){
                if (remain[i] != 2) continue;
                if (rating < a[i]) continue;
                if (mark == -1 || b[mark] < b[i]){
                    mark = i;
                }
            }
            if (mark == -1) break;
            ++ans;
            remain[mark] = 1;
            ++rating;
        }
        printf("Case #%d: ", ++cas);
        if (rating != 2*n) puts("Too Bad");
        else printf("%d\n", ans);
    }

    return 0;
}

