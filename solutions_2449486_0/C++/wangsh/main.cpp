#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

#define FORALL(a,b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)
#define FOR(i,a,b) for(int i = a; i < (int)(b); ++i)

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

typedef long long LL;

const double EPS = 1e-6;
const int INF = 1<<29;

const int N = 110;
const int M = 110;
int mat[M][N];

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);

    int t, cas = 0, n, m;
    int maxM[M];
    int maxN[N];
    scanf("%d", &t);

    while (t--){

        scanf("%d %d", &m, &n);

        for (int i = 0; i < m; ++i) maxM[i] = 0;
        for (int i = 0; i < n; ++i) maxN[i] = 0;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j){
                scanf("%d", &mat[i][j]);
                if (maxM[i] < mat[i][j]) maxM[i] = mat[i][j];
                if (maxN[j] < mat[i][j]) maxN[j] = mat[i][j];
            }

        bool res = 1;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j){
                if (maxM[i] > mat[i][j] && maxN[j] > mat[i][j])
                    res = 0;
            }

        printf("Case #%d: ", ++cas);
        puts(res ? "YES" : "NO");
    }

    return 0;
}
