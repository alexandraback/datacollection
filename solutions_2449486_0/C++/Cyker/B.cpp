#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define RANGE(i,b,e) for(int (i)=(b);(i)<(int)(e);(i)++)
#define CRANGE(i,b,e) for(int (i)=(b);(i)<=(int)(e);(i)++)
#define RRANGE(i,b,e) for(int (i)=(b);(i)>=(int)(e);(i)--)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define PI 3.1415926535897932384626433832795
#define INF 0x7FFFFFFF

int T;
int N, M;
int a[101][101];
int r[101], c[101];

bool solve()
{
    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < M;j++) {
            r[i] = max(r[i], a[i][j]);
            c[j] = max(c[j], a[i][j]);
        }
    }
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < M;j++) {
            if (a[i][j] != min(r[i], c[j]))
                return false;
        }
    }
    return true;
}

int main(int argc, char **argv)
{
    scanf("%d\n", &T);
    for (int t = 0;t < T;t++) {
        scanf("%d %d\n", &N, &M);
        for (int i = 0;i < N;i++) {
            for (int j = 0;j < M;j++) {
                scanf("%d", &a[i][j]);
            }
        }

        printf("Case #%d: ", t + 1);
        if (solve()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}

