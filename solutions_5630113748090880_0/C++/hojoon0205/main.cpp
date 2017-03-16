#include<stdio.h>
int n, arr[60][60];
int cnt[2510];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i, j, x;
    int T, tt;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt)
    {
        scanf("%d", &n);
        for(i=1; i<=2500; ++i) cnt[i]=0;
        for(i=1; i<=(2*n-1)*n; ++i)
        {
            scanf("%d", &x);
            ++cnt[x];
        }
        printf("Case #%d: ", tt);
        for(i=1; i<=2500; ++i)
        {
            if(cnt[i]%2==1) printf("%d ", i);
        }
        printf("\n");
    }
}
