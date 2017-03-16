#include <stdio.h>
#include <stdlib.h>

#define MAXN 100011

int n,m,k;
double a[MAXN];

void solve()
{
    double min = m+2.0;
    double right = 1.0;
    double b;

    for(int i=n; i>=0; i--)
    {
        b = right*(2*i+m-n+1) + (1-right) * (2*i+m-n+1+m+1);
	
        //printf("\n i=%d right=%f b=%f\n",i,right,b);
		right *= a[n-i+1];
        if(b<min)
            min=b;
    }

    printf("%.6f\n",min);
}

int main()
{
    int casen;

    scanf("%d",&casen);

    for(int i=1; i<=casen; i++)
    {
        scanf("%d%d",&n,&m);
        for(int j=1; j<=n; j++)
            scanf("%lf",&a[j]);

        printf("Case #%d: ",i);
        solve();
    }
}
