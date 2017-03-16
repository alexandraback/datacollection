#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
const int DUZO = 256;
int lawn[DUZO][DUZO];
int row_max[DUZO];
int col_max[DUZO];

int main() {
    int t;

    scanf("%d", &t);
    for(int c = 1; c <= t; c++) {
        scanf("%d %d", &n, &m);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%d", &(lawn[i][j]));

        for(int i = 0; i < n; i++) {
            int maxi = lawn[i][0];

            for(int j = 1; j < m; j++)
                maxi = max(maxi, lawn[i][j]);

            row_max[i] = maxi;
        }

        for(int i = 0; i < m; i++) {
            int maxi = lawn[0][i];

            for(int j = 1; j < n; j++)
                maxi = max(maxi, lawn[j][i]);

            col_max[i] = maxi;
        }

        bool can_cut = true;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(lawn[i][j] != row_max[i] && lawn[i][j] != col_max[j]) {
                    can_cut = false;

                    break;
                }
            }
        }

        printf("Case #%d: %s\n", c, can_cut ? "YES" : "NO");
    }

    return 0;
}

