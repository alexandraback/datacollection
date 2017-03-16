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

const int MOD = 1000000009;

int cmpint(const void*a,const void *b)
{
    if(((int*)a)[0]==((int*)b)[0])
      return ((int*)a)[1]-((int*)b)[1];
    return ((int*)a)[0]-((int*)b)[0];
}

double cc(int n,int m){
    int i;
    double ans=1;
    for1(i,0,m-1){
        ans=ans*(n-1-i)/(i+1);
    }
    return ans;
}

double c(int n,int m,int k){
    double ans=0;
    int i;
    double t=1;
    for1(i,0,m)
      t*=0.5;
    for1(i,m,n+1){
        ans+=cc(i,m)*t;
        t*=0.5;
    }
    return ans;
}

ll a[10005];

int main()
{
    int i,j,n,m,k,l,o,p;
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    scanf("%d",&p);
    int x,y;
    a[0]=0;
    for1(i,1,10001)
       a[i]=a[i-1]+i*4-3;
    for1(o,1,p+1){
        scanf("%d%d%d",&n,&x,&y);
        if(x<0) x=-x;
        printf("Case #%d: ",o);
        k=(x+y)/2;
        if(n<=a[k]) {
            printf("0.0\n");
            continue;
        }
        if(n>=a[k+1]){
            printf("1.0\n");
            continue;
        }
        n-=a[k];
        if(n<y+1||x==0){
            printf("0.0\n");
            continue;
        }
        if(n>=y+1+k*2){
            printf("1.0\n");
            continue;
        }
        double ans=c(n,y+1,k*2);
        printf("%f\n",ans);
    }




    return 0;
}
