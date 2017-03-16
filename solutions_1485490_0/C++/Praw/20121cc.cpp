#include <stdio.h>

long long a[4];
long long b[101];
int ta[4],tb[101];

long long sum[4][101];
long long min(long long z, long long x)
{
    if(x>z)return z;
    return x;
}
main()
{
      
          freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small.out","w",stdout);
    int q;
    scanf("%d", &q);
    for(int qq=0;qq<q;qq++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%I64d%d",&a[i],&ta[i]);
        for(int i=1;i<=m;i++)
            scanf("%I64d%d",&b[i],&tb[i]);
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            sum[i][j]=sum[i][j-1];
            if(ta[i]==tb[j])sum[i][j] += b[j];
        }

        int step[5];
        for(int i=0;i<n;i++)step[i]=0;
        long long max=0;
        int mm=m+1;
        while(true){
            int s2[4];
            s2[0]=0;
            for(int i=1;i<n;i++)s2[i]=step[i-1];
            s2[n]=m;
            int noround=false;
            for(int i=0;i<n;i++)if(s2[i]>s2[i+1])noround=true;
            if(!noround){


            long long s=0;
            for(int i=1;i<=n;i++)s+=min(a[i],sum[i][s2[i]]-sum[i][s2[i-1]]);
            if(s>max)max=s;
            }
            step[0]++;
            for(int i=0;i<n;i++){
                step[i+1]+=step[i]/mm;
                step[i]%=mm;
            }
            if(step[n-1]>0)break;
        }
        if(n==3 && ta[1] == ta[3])
        {
            if(min(sum[1][m]-sum[1][0],a[1]+a[3])>max)
            max = min(sum[1][m]-sum[1][0],a[1]+a[3]);
        }
        printf("Case #%d: %I64d\n", qq+1,max);
    }
}
