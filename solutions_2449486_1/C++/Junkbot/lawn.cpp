#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 105;

int R, C;
int grid[MAX_N][MAX_N];

int maxRow[MAX_N];
int maxCol[MAX_N];

int main() {
    int T;
    scanf("%d",&T);

    for(int z=1;z<=T;z++) {
        scanf("%d %d",&R,&C);

        for(int i=0;i<R;i++) {
            for(int j=0;j<C;j++) {
                scanf("%d",&grid[i][j]);
            }
        }

        for(int i=0;i<R;i++) {
            maxRow[i] = grid[i][0];
            for(int j=0;j<C;j++) {
                maxRow[i] = max(maxRow[i], grid[i][j]);
            }
        }

        for(int j=0;j<C;j++) {
            maxCol[j] = grid[0][j];
            for(int i=0;i<R;i++) {
                maxCol[j] = max(maxCol[j], grid[i][j]);
            }
        }

        bool works = true;
        for(int i=0;i<R;i++) {
            for(int j=0;j<C;j++) {
                if(min(maxRow[i], maxCol[j]) != grid[i][j]) {
                    works = false;
                }
            }
        }

        printf("Case #%d: ",z);
        if(works) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
