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

char s[1000005];
double a[1000005];

int main()
{
    int i,j,n,m,k,l,o,p;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    scanf("%d",&p);
    for1(o,1,p+1){
        scanf("%d%d",&n,&m);
        for1(i,0,n)
          scanf("%lf",&a[i]);
        double win,los;
        double ans=m+2;
        double tans;
        win=1;los=0;
        for1(i,0,n){
            win=win*a[i];
            los=1-win;
            //printf("%f %f %f\n",ans,win,los);
            tans=win*(n-i-1+m-i)+los*(n-i-1+m-i+m+1);
            if(tans<ans) ans=tans;
        }
        printf("Case #%d: %.6f\n",o,ans);
    }
    return 0;
}
