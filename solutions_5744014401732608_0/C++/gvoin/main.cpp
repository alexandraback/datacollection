#include <bits/stdc++.h>
using namespace std;

int n;
int a[60][60];
long long m;

int main()
{
    ios::sync_with_stdio(0);
    //freopen("input.in","r",stdin);
    //freopen("output.txt","w",stdout);
    int T;
    cin >> T;
    for(int t=1;t<=T;++t)
    {
        printf("Case #%d:",t);
        cin >> n >> m;
        memset(a,0,sizeof(a));
        for(int i=0;i<n;++i)
            for(int j=i+1;j<n;++j)
                a[i][j]=1;
        long long cur=1;
        for(int i=3;i<=n;++i) cur*=2;

        if(cur<m)
        {
            printf(" IMPOSSIBLE\n");
            continue;
        }

        cur = cur - m;
        int p = 1;
        while(cur)
        {
            if(cur%2) a[p][n-1] = 0;
            cur/=2;
            p++;
        }

        printf(" POSSIBLE\n");
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
                printf("%d",a[i][j]);
            printf("\n");
        }


    }

}
