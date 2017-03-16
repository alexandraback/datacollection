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

int a[100005];
int fg[100005];
int b[100005];

int main()
{
    int i,j,n,m,k,l,o,p;
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d",&p);
    for1(o,1,p+1){
        scanf("%d%d",&n,&m);
        same(b);
        b[0]=n;
        for1(i,0,m)
           scanf("%d",&a[i]);
        qsort(a,m,sizeof(int),cmpint);
        same(fg);
        printf("Case #%d: ",o);
        if(n==1) {printf("%d\n",m);continue;}
        int ans=100000;
        int tans=0;
        for1(i,0,m){
            if(b[i]>a[i]) b[i+1]=a[i]+b[i];
            else{
                l=b[i];
                k=0;
                while(l<=a[i]){
                    l+=l-1;
                    k++;
                }
                ans=min(ans,tans+m-i);
                tans+=k;
                b[i+1]=l+a[i];
            }
        }
        ans=min(ans,tans);
        printf("%d\n",ans);
    }
    return 0;
}
