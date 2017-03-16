#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef long long LL;
#define CLR(a,b) memset(a,b,sizeof(a))
const int N = 50+5;
int n;
int num[N][N];
unordered_map<int, int> cnt;
void solve()
{
    vector<int> vec;
    for (auto& ite : cnt) {
        if (ite.second % 2 == 1) {
            vec.push_back(ite.first);
        }
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; ++i) {
        if (i > 0) printf(" ");
        printf("%d", vec[i]);
    }
    puts("");
}

int main()
{
    freopen("/Users/lizhen/Documents/Project/Cpp/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/lizhen/Documents/Project/Cpp/cpp/cpp/output.txt", "w", stdout);
    int T, cas = 0;
    scanf("%d", &T);
    while (T--) {
        cnt.clear();
        printf("Case #%d: ", ++cas);
        scanf("%d", &n);
        for (int i = 0; i < 2 * n-1; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &num[i][j]);
                cnt[num[i][j]] ++;
            }
        }
        solve();
    }
    return 0;
}