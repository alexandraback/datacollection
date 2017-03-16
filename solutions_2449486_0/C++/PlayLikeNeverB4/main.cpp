#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctype.h>
#include <cstring>
#include <ctime>
#include <cassert>
#include <utility>

using namespace std;

#define INF 1000000000
#define MAXN 128
int N, M, T;
int A[MAXN][MAXN];
bool toLeft[MAXN][MAXN], toRight[MAXN][MAXN];
bool toUp[MAXN][MAXN], toDown[MAXN][MAXN];

int main() {
	freopen("date.in", "r", stdin);
	freopen("date.out","w", stdout);

	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
        scanf("%d %d", &N, &M);
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= M; j++)
                scanf("%d", &A[i][j]);

        memset(toLeft, false, sizeof(toLeft));
        memset(toRight, false, sizeof(toRight));
        memset(toUp, false, sizeof(toUp));
        memset(toDown, false, sizeof(toDown));

        for(int i = 1; i <= N; i++) {
            int vmax = -1;
            for(int j = 1; j <= M; j++) {
                if(vmax > A[i][j])
                    toLeft[i][j] = true;
                vmax = max(vmax, A[i][j]);
            }

            vmax = -1;
            for(int j = M; j >= 1; j--) {
                if(vmax > A[i][j])
                    toRight[i][j] = true;
                vmax = max(vmax, A[i][j]);
            }
        }

        for(int j = 1; j <= M; j++) {
            int vmax = -1;
            for(int i = 1; i <= N; i++) {
                if(vmax > A[i][j])
                    toUp[i][j] = true;
                vmax = max(vmax, A[i][j]);
            }

            vmax = -1;
            for(int i = N; i >= 1; i--) {
                if(vmax > A[i][j])
                    toDown[i][j] = true;
                vmax = max(vmax, A[i][j]);
            }
        }

        bool valid = true;
        for(int i = 1; i <= N && valid; i++)
            for(int j = 1; j <= M && valid; j++) {
                bool hor = !toLeft[i][j] && !toRight[i][j];
                bool vert = !toUp[i][j] && !toDown[i][j];

                if(!hor && !vert)
                    valid = false;
            }

        printf("Case #%d: ", t);
        if(valid)
            printf("YES\n");
        else
            printf("NO\n");
	}

	return 0;
}
