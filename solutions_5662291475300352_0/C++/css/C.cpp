#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int maxN = 5e5+7;
vector<pair<int, int> > hiker;
int T, n, d, h, m;
int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    scanf("%d", &T);
    for (int count = 1; count <= T; count++) {
        hiker.clear();
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &d, &h, &m);
            for (int j = 0; j < h; j++)
                hiker.push_back(make_pair(m+j, d));
        }
        sort(hiker.begin(), hiker.end());
        //printf("%d %d\n", hiker[0].first, hiker[0].second);
        //printf("%d %d\n", hiker[1].first, hiker[1].second);
        int ans = 0;
        int len0 = 360-hiker[0].second;
        int len1 = 360-hiker[1].second;
        //if (len0 > len1) {
           // if (len0*hiker[0].first <= len1*hiker[1].first) ans = max(1, ans);
        //}
        if ((len0+360)*hiker[0].first <= len1*hiker[1].first) ans = max(1, ans);
        printf("Case #%d: %d\n", count, ans);
    }
}
