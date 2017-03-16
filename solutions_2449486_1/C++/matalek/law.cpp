#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <iostream>
#define REP(x,n) for (int x = 0; x < (n); ++x)
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
#define VAR(v,n) __typeof(n) v = (n)
#define FOREACH(i,c) for (VAR(i,(c).begin()); i!=(c).end(); ++i)
#define deb(a)
using namespace std;
typedef long long int LL;
typedef vector<int> VI;
typedef pair <int,int> PII;
typedef vector< PII > VPII;

const int N = 103;
int arr[N][N], max1[N], max2[N]; //n,m

int main()
{
    int t, n, m;

    scanf("%d",&t);
    REP(abc,t)
    {
        scanf("%d%d",&n,&m);

        REP(i,n)
            REP(j,m)
                scanf("%d",&arr[i][j]);

        REP(i,N)
            max1[i] = max2[i] = 0;

        REP(i,n)
            REP(j,m)
                max1[i] = max(max1[i], arr[i][j]);

        deb(REP(i,n) printf("Max w kolumnie %d  %d\n",i+1,max1[i]);)

        REP(j,m)
            REP(i,n)
                max2[j] = max(max2[j], arr[i][j]);

        bool guard = true;
        REP(i,n)
            REP(j,m)
                if(arr[i][j] != max1[i] && arr[i][j] != max2[j])
                {
                    deb(printf("%d %d %d %d %d\n",i+1,j+1, arr[i][j], max1[i],max2[j]);)
                    guard = false;
                }


        printf("Case #%d: ",abc+1);
        if (guard)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
