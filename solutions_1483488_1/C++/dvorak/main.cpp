#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAXN 2000005
using namespace std;

vector<int> data[MAXN];

int main() {
    freopen("in","r",stdin);
    freopen("out2","w",stdout);
    char str[10], ch;
    int n;
    for (int i = 1; i <= 2000000; i++) {
        sprintf(str, "%d", i);
        for (int k = 0, l = strlen(str); k < l - 1; k++) {
            ch = str[0];
            for (int j = 0; j < l - 1; j++)
                str[j] = str[j + 1];
            str[l - 1] = ch;
            sscanf(str, "%d", &n);
            data[i].push_back(n);
        }
        sort(data[i].begin(), data[i].end());
        data[i].erase(unique(data[i].begin(), data[i].end()), data[i].end());
    }
    printf("OK\n");

    int T, a, b;
    scanf("%d\n", &T);
    int cas = 1;
    while (T--) {
        scanf("%d%d", &a, &b);
        int sum = 0;
        for (int i = a; i <= b; i++) {
            for (int j = 0; j < data[i].size(); j++)
                if (data[i][j] > i && data[i][j] <= b) {
                    //printf("{%d,%d}\n",i,data[i][j]);
                    sum++;
                }
        }
        printf("Case #%d: %d\n", cas++, sum);
    }

}


