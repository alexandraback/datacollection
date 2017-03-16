#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;

#define MP make_pair
#define PB push_back

const int V = 110;
long long sum[10][200];
long long a[V], b[V];
int A[V], B[V];

int n, m;

int main()
{
    int test;
    scanf("%d",&test);
    for (int cas=1;cas<=test;cas++)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            cin >> a[i] >> A[i];
        
        for (int i=1;i<=m;i++)
            cin >> b[i] >> B[i];
        
        for (int i=1;i<=n;i++)
        {
            sum[i][0] = 0;
            for (int j=1;j<=m;j++)
            {
                sum[i][j] = sum[i][j-1] + ((B[j] == A[i]) ? b[j] : 0);
            }
        }
        /*
        for (int i=1;i<n;i++)
        if (A[i] == A[i+1])
        {
            i /= 0;
        }
        */
        printf("Case #%d: ",cas);
        if (n == 1) 
        {
            cout << min(a[1], sum[1][m]) << endl;
        }else
        if (n == 2)
        {
            long long ans = 0;
            for (int i=0;i<=m;i++)
            {
                long long tmp = min(a[1],sum[1][i]) + min(a[2],sum[2][m] - sum[2][i]);
                ans = max(ans, tmp);
            }
            if (A[1] == A[2])
            {
                long long tmp = min(a[1] + a[2], sum[1][m]);
                ans = max(ans, tmp);
            }
            cout << ans << endl;
        }else
        {
            long long  ans = 0;
            for (int i=0;i<=m;i++)
                for (int j=i;j<=m;j++)
                {
                    long long tmp = min(a[1],sum[1][i]) + min(a[2],sum[2][j]-sum[2][i]) +
                              min(a[3],sum[3][m]-sum[3][j]);
                            
                    //printf("%d %d %I64d\n",i, j, tmp);
                    ans = max(ans, tmp);
                }
            if (A[1] == A[2])
            {
                long long tmp = min(a[1] + a[2], sum[1][m]);
                ans = max(ans, tmp);
            }
            if (A[2] == A[3])
            {
                long long tmp = min(a[2] + a[3], sum[2][m]);
                ans = max(ans, tmp);
            }
            if (A[1] == A[3])
            {
                long long tmp = min(a[1] + a[3], sum[1][m]);
                ans = max(ans, tmp);
            }
            cout << ans << endl;
        }
        
    }
}


