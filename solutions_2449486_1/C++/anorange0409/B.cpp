#include <iostream>
#include <cstdio>
using namespace std;

const int N = 205;
int a[N][N], hang[N], lie[N];

int main(){
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int testcase;
    cin >> testcase;
    for (int t = 1; t <= testcase; t++){
        printf("Case #%d: ", t);
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n + m; i++)
            hang[i] = lie[i] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++){
                cin >> a[i][j];
                hang[i] = max(hang[i], a[i][j]);
                lie[j] = max(lie[j], a[i][j]);
            }
        bool OK = true;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (a[i][j] < hang[i] && a[i][j] < lie[j])
                    OK = false;
        if (OK) printf("YES\n");
        else printf("NO\n");

    }
}
