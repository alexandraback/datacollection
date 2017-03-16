#include<cmath>
#include<cstdio>
#include<cctype>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

#define sqr(a) (a)*(a)
#define cub(a) (a)*(a)*(a)
#define for1(i,a,b) for(i=(a);i<(b);i++)
#define for2(i,a,b) for(i=(a);i>(b);i--)
#define same(a) memset((a),0,sizeof(a));
#define ll long long

int cmpint(const void*a,const void *b)
{
    if(((int*)a)[0]==((int*)b)[0])
      return ((int*)a)[1]-((int*)b)[1];
    return ((int*)a)[0]-((int*)b)[0];
}

int a[1005][2];
double b[1005];

int main()
{
    int i,j,n,m,k,l,o,p;
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d",&p);
    for1(o,0,p){
        same(b);
        scanf("%d",&n);
        double sum=0;
        for1(i,0,n){
             scanf("%d",&a[i][0]);
             a[i][1]=i;
             sum+=a[i][0];
        }
        a[n][0]=10000000;
        qsort(a,n,sizeof(int)*2,cmpint);
        i=0;
        double tsum=sum;
        while(sum>0){
            if(sum>(a[i+1][0]-a[i][0])*(i+1)){
               for1(j,0,i+1)
                 b[j]+=a[i+1][0]-a[i][0];
                sum-=(a[i+1][0]-a[i][0])*(i+1);
                i++;
            }
            else{
               for1(j,0,i+1)
                 b[j]+=sum/(i+1);
               sum=0;
            }
            //printf("%d %f\n",i,sum);
        }

        printf("Case #%d:",o+1);
        for1(i,0,n){
           for1(j,0,n)
            if(a[j][1]==i){
                printf(" %.6f",b[j]/tsum*100);
                break;
            }
        }
        printf("\n");
    }
    return 0;
}
