#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <list>
using namespace std;

#define PB push_back
#define MP make_pair
#define A first
#define B second
#define eps 1e-8

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int sum[10010], t, p[10010][2], tt;
char ans[100010];

void prepare() {
    sum[0] = 0;
    for (int i = 1; i <= 10000; i ++ )
        sum[i] = sum[i - 1] + i;
}

void work(int x, int y, int t) {
    //cout<<x<<" "<<y<<" "<<t<<endl;
    if (t == 0) {
        for (int i = 1; i <= tt; i ++ )
            if (p[i][0] > 0)
                if (p[i][1] > 0) ans[i - 1] = 'E';
                else ans[i - 1] = 'N';
            else if (p[i][1] > 0) ans[i - 1] = 'S';
            else ans[i - 1] = 'W';
            ans[tt] = '\0';
        return ;
    }
    for (int i = -1; i <= 1; i += 2)
        for (int j = -1; j <= 1; j += 2) {
            int xx = x + i * t;
            int yy = y + j * t;
            if (abs(xx) <= sum[t - 1] && abs(yy) <= sum[t - 1]
             && (sum[t - 1] - xx) % 2 == 0 && (sum[t - 1] - yy) % 2 == 0) {
                p[t][0] = -i;
                p[t][1] = -j;
                work(xx, yy, t - 1);
                return ;
             }
        }

}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    prepare();
    scanf("%d", &t);
    for (int ca = 1; ca <= t; ca ++ ) {
        int x, y, xx, yy;
        scanf("%d%d", &x, &y);
        xx = x + y;
        yy = x - y;
        for (int i = 1; i <= 10000; i ++ )
            if (abs(xx) <= sum[i] && abs(yy) <= sum[i]
            && (sum[i] - xx) % 2 == 0 && (sum[i] - yy) % 2 == 0) {
                tt = i;
                work(xx, yy, i);
                break;
            }
        xx = yy = 0;
        for (int i = 0; i < strlen(ans); i ++ )
            if (ans[i] == 'N') yy += i + 1;
            else if (ans[i] == 'S') yy -= i + 1;
            else if (ans[i] == 'E') xx += i + 1;
            else xx -= i + 1;
        if (xx != x || yy != y) while (1);
        printf("Case #%d: %s\n", ca, ans);
    }
    return 0;
}
