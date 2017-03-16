#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
long long tA[300], tB[300];
int n, m;
long long tyA[300], tyB[300], ans;

void findans(int i,int j,long long ii, long long jj, long long pans) 
{
    if (i>n || j>m) 
    {
    	if(ans<pans)
        ans= pans;
        return;
    }
    if (tyA[i] == tyB[j]) 
    {
        if (ii < jj) 
        {
            findans(i + 1,j,tA[i + 1], jj - ii, pans + ii);
        }
         else 
        {
            findans(i,j+1,ii - jj, tB[j + 1], pans + jj);
        }
        return;
    }
    findans(i + 1, j,tA[i + 1], jj, pans);
    findans(i,j+1,ii, tB[j + 1], pans);
}

int main() {
    int tcase, casenum=0, i;
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    scanf("%d", &tcase);
    while (tcase--) 
    {
        scanf("%d%d", &n, &m);
        for (i = 1; i <= n; i++)
            scanf("%lld%lld", &tA[i], &tyA[i]);
        for (i = 1; i <= m; i++)
            scanf("%lld%lld", &tB[i], &tyB[i]);
        ans = 0;
        findans(1,1,tA[1], tB[1], 0);
        printf("Case #%d: %lld\n", ++casenum, ans);
    }
    return 0;
}
