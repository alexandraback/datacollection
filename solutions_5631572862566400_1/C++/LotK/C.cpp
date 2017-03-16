#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int longest[1010];
int bff[1010];
int used[1010];
vector<pair<int, int> > adj;
int main() {
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);

    int tt;
    scanf("%d", &tt);
    for (int t=0 ; t<tt ; t++) {
        adj.clear();
        int ans=0, n;
        scanf("%d", &n);
        for (int i=1 ; i<=n ; i++) {
            scanf("%d", &bff[i]);
        }
        for (int i=1 ; i<=n ; i++) {
            for (int j=0 ; j<=n ; j++) longest[j] = 0;
        }
        for (int i=1 ; i<=n ; i++) {
            // find big loop
            for (int j=1 ; j<=n ; j++) used[j] = 0;
            int j=bff[i], last=i;
            int count=1;
            while (used[j] == 0) {
                used[j] = 1;
                if (bff[j] == last) {   // adjacent
                    adj.push_back(make_pair(last, j));
                    break;
                }
                else if (bff[j] == i) { // circle
                    ans = max(ans, count+1);
                    break;
                }
                else {
                    longest[j] = max(longest[j], count);
                }
                last = j;
                j = bff[j];
                count++;
            }
        }

        int sum = 0;
        for (int j=1 ; j<=n ; j++) used[j] = 0;
        for (int i=0 ; i<adj.size() ; i++) {
            if (used[adj[i].first]==1 || used[adj[i].second]==1) continue;
            sum += longest[adj[i].first] + longest[adj[i].second] + 2;
            used[adj[i].first] = 1;
            used[adj[i].second] = 2;
        }
//        printf("ans: %d\n", ans);
//        printf("sum: %d\n", sum);
        ans = max(ans, sum);

        printf("Case #%d: %d\n", t+1, ans);
//        printf("longest (%d): ", adj.size());
//        for(int i=1 ; i<=n ; i++) {
//            printf("%d ", longest[i]);
//        }
//        printf("\n");
    }
}
