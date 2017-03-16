/*
LANG: C++
*/

#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<list>
#include<set>
#include<queue>
#include<map>
#include<cctype>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<ctime>

using namespace std;

double p[100005];
double c[100005],csum[100005];

bool solve(){
    int a,b;
    scanf("%d %d",&a,&b);
    for(int i=0;i<a;i++)
        scanf("%lf",&p[i]);
    double t=1,t2=1;
    for(int i=0;i<a;i++)
    {
        c[i]=t2*(1-p[i]);
        t2*=p[i];
    }
    c[a]=t2;
    double sum=0;
    for(int i=0;i<=a;i++)
    {
        sum+=c[i];
//        printf("%lf ",c[i]);
    }
//    printf("\n");
    csum[0]=c[a]+c[a-1];
    for(int i=1;i<a;i++)
        csum[i]=csum[i-1]+c[a-i-1];
//    for(int i=0;i<a;i++)
//        printf("%lf ",csum[i]);
//    printf("\n");
    double sol=2000000000,tmpsol;
    tmpsol=c[a]*(b-a+1)+((double)1-c[a])*(b-a+1+b+1);
    sol=min(sol,tmpsol);
//    printf("-%lf\n",tmpsol);
    sol=min(sol,((double)1+b+1));
//    printf("-%lf\n",((double)1+b+1));
    for(int i=0;i<a;i++)
    {
//        printf("%d * %lf + %d * %lf =",(a-i+b-i+1),(csum[a-i-1]),(a-i+b-i+1+b+1),((double)1-csum[a-i-1]));
        tmpsol=(a-i+b-i+1)*(csum[a-i-1])+(a-i+b-i+1+b+1)*((double)1-csum[a-i-1]);
        sol=min(sol,tmpsol);
//        printf("%lf\n",tmpsol);
    }
    printf("%.9lf\n",sol);
    return true;
}

int main(){

    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        solve();
    }
    return 0;
}
