#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>

using namespace std;
const int N = 100;

double t[N],x[N],a[N],d;
int n,m;

void init(){
    int i,j;
    scanf("%lf%d%d",&d,&n,&m);
    for(i = 0; i < n; i++){
        scanf("%lf%lf",&t[i],&x[i]);
    }
    for(i = 0; i < m; i++){
        scanf("%lf",&a[i]);
    }
}

void gao1(){
    double ans;
    int i;
    for(i = 0; i < m; i++){
        ans = sqrt(2*d/a[i]);
        printf("%.12lf\n",ans);
    }
}
void gao2(){
    double ans;
    int i;
    for(i = 0; i < m; i++){
        ans = max(sqrt(2*d/a[i]),(d - x[0])*(t[1] - t[0])/(x[1] - x[0]));
        printf("%.12lf\n",ans);
    }
}
int main()
{
//    freopen("in","r",stdin);
//    freopen("out","w",stdout);
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B.out","w",stdout);
//    freopen("A-large.in","r",stdin);
//    freopen("AA.out","w",stdout);
    int t,cas;
    
    scanf("%d",&t);cas = 0;
    while(t--)
    {
        printf("Case #%d:\n",++cas);
        init();
        if(n == 1) gao1();
        if(n == 2) gao2();
    }

}
