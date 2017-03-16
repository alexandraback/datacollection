#include<cstdio>
#include<algorithm>
const int MAXN = 105;

int maxRow[MAXN], maxCol[MAXN], S[MAXN][MAXN];

int main() {
    int t;
    scanf("%d", &t);

    int test = 0;
    while (t--) {
        test++;
        
        int n, m; 
        scanf("%d%d", &n, &m);

        std::fill(maxRow, maxRow+MAXN, 0);
        std::fill(maxCol, maxCol+MAXN, 0);

        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                scanf("%d", &S[i][j]);

        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                maxRow[i] = std::max(maxRow[i], S[i][j]);
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                maxCol[i] = std::max(maxCol[i], S[j][i]);
        
        bool fail = false;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                if (maxRow[i] > S[i][j] && maxCol[j] > S[i][j]) {
                    fail = true;
                    break;
                }
        
        printf("Case #%d: ", test);
        if (fail)
            printf("NO\n");
        else
            printf("YES\n");
    }
}
