#include<bits/stdc++.h>
using namespace std;
int a[51][51];
int main()
{
    int i,j,sum,n,t,r,bt;
    long long x,m;
    cin>>t;

    for(r = 1; r <= t; r++){
        scanf("%d %lld", &n, &m);
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++)
                a[i][j] = 0;
        }
        printf("Case #%d: ", r);
        x = 1;
        for(i = 1; i <n-1; i++){
            x *= 2;
        }
        if(m > x){
            printf("IMPOSSIBLE\n");
            continue;
        }
        for(i = 1; i < n-1; i++){
            for(j = i+1; j < n; j++){
                a[i][j] = 1;
            }
        }
        if(m == x){
            for(j = 1; j < n; j++){
                a[0][j] = 1;
            }
        }
        else{
            x = m;
            bt = 0;
            while(x){
                bt++;
                if(x & 1){
                    a[0][n - bt -1] = 1;
                }
                x >>= 1;
            }
        }
        printf("POSSIBLE\n");
        for(i = 0; i<n; i++)
        {
            for(j = 0; j < n; j++)
                printf("%d", a[i][j]);
            printf("\n");
        }

    }
    return 0;
}
