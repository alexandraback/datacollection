#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

//global constants
const int INF = 1<<29;
const double EPS = 1e-8;
typedef __int64 LL;

//local constants
const int N = 60;
vector<vector<int> > arr;
int sum[N][N];
bool used[N*2];
int n;

int main()
{
    freopen("B-small-attempt1.in","r",stdin);
//    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t, cas = 0;
    scanf(" %d ", &t);
    while (t--) {
        scanf(" %d ", &n);
        arr.clear();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                sum[i][j] = 0;
        for (int i = 0; i < 2*n; ++i) used[i] = 0;
        for (int i = 0; i < 2*n-1; ++i) {
            int tmp;
            vector<int> tmp_vt;
            for (int j = 0; j < n; ++j) {
                scanf(" %d ", &tmp);
                tmp_vt.push_back(tmp);
            }
            arr.push_back(tmp_vt);
        }
        int mark = -1;
        for (int i = 0; i < n; ++i) {
            int minv = INF;
            int cnt = 0;
            for (int j = 0; j < 2*n-1; ++j) {
                if (used[j]) continue;
                if (arr[j][i] < minv) {
                    minv = arr[j][i];
                }
            }
            for (int j = 0; j < 2*n-1; ++j) {
                if (used[j]) continue;
                if (arr[j][i] == minv) {
                    used[j] = 1;
                    cnt++;
                    for (int k = 0; k < n; ++k) sum[i][k] += arr[j][k];
                }
            }
//            for (int k = 0; k < n; ++k) printf("%d ", sum[i][k]);
//            putchar('\n');
//            printf("cnt = %d\n", cnt);
            if (cnt == 1) mark = i;
        }
        printf("Case #%d:", ++cas);
        for (int i = 0; i < n; ++i) {
            if (i == mark) printf(" %d", sum[i][i]);
            else printf(" %d", sum[i][mark] - sum[mark][i]);
        }
        putchar('\n');
    }
    return 0;
}
