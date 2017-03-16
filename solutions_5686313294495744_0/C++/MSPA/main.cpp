#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>

const int N = 1e5+3;
const int inf = 1e9;

typedef long long ll;

using namespace std;
char s1[N], s2[N];
int ans = 0;
vector<pair<string, string>> v;
int a[N],n;
void rec(int x)
{
    if (x == n){
        int k = 0;
        for (int i = 0; i < n; ++i)
            if (a[i] == 0) {
                int t = 0;
                for (int j = 0; j < n; ++j) {
                    if (a[j] == 1 && v[i].first == v[j].first) t|=1;
                    if (a[j] == 1 && v[i].second == v[j].second) t|=2;
                    
                }
                k += (t == 3);
            }
//        for (int i = 0; i < n; ++i)
//            printf("%d ", a[i]);
//        puts("");
//        printf("%d\n", k);
        ans = max(ans,k);
        return;
    }
    for (a[x] = 0; a[x] < 2; ++a[x])
        rec(x+1);
}
bool solve()
{
    scanf("%d", &n);
    v.resize(n);
    for(auto&p:v) {
        scanf("%s%s",s1, s2);
        p = {s1,s2};
    }
    ans = 0;
    rec(0);
    printf("%d\n", ans);
    return false;
}

int main()
{
        freopen("input.txt","r", stdin);
        freopen("output.txt", "w", stdout);
    int countTests;
    scanf("%d", &countTests);
    for (int curTest = 1; curTest <= countTests; ++curTest) {
        printf("Case #%d: ", curTest);
        solve();
    }
    
    return 0;
}
