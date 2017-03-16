#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std ;

#define MAXN 200

int arr[MAXN+5];
int n;
double sum;

bool check(double percent,int i)
{
    double ret=0;
    double tot = percent*sum + arr[i];
    int c,c2;
    int cnt=n-1;
    for (c=0;c<n;c++)
    {
        if (c==i)continue;
        if (tot<arr[c]){
            cnt--;
            continue;
        }
        ret+=(tot-arr[c])/sum;
    }
    return (cnt>0)&&((ret+percent)>=1);
}

double getAns(int st,int en,int i)
{
    double s=st,e=en;
    while (fabs(e-s)>1e-12){
        double mid = (s+e)/2.0;
        if (check(mid,i))e=mid;
        else s=mid;
    }
    return s+1e-11;
}

int main()
{
    FILE *in=fopen("safety.in","r");
    freopen("safety.out","w",stdout);
    int c,c2;
    int tests;
    fscanf(in,"%d",&tests);
    for (int test=1;test<=tests;test++)
    {
        sum=0;
        fscanf(in,"%d",&n);
        int mini=50000,maxi=0;
        for (c=0;c<n;c++){
            fscanf(in,"%d",&arr[c]);
            mini=min(arr[c],mini);
            maxi=max(arr[c],maxi);
            sum+=arr[c];
        }
        printf("Case #%d:",test);
        for (c=0;c<n;c++)
        {
            double ret = getAns(0,1,c);
            printf(" %.7lf",ret*100.0);
        }
        printf("\n");
    }
    
    
//    system("pause");
    return 0;
    
    
}
