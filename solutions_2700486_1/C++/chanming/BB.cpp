#include <iostream>
#include <sstream>
#include <string.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <map>
#define pb push_back
#define MAXN 1
#define MAXM 1
#define INF (1<<30)
#define PI 3.1415926535898
#define esp 10e-6
#define Si size()
const int dx[4]={1,0,-1,0};
const int dy[4]={0,-1,0,1};
using namespace std;
int f[1011];
double c[310][310];
int n,x,y;

void prework(){
    for (int i=1;i<=1000;++i)
        f[i]=(2*i*i-i);
}


double calc(){
    if (x>500 || x<-500 || y>250) return 0;
    int p=(abs(x)+y)/2+1;
    if (x==0){
        if (n>=f[p]) return 1;
            else return 0;
    }
    if (n<=f[p-1]) return 0;
    if (n>f[p-1]+(p-1)*2+y) return 1;
    int z=n-(f[p-1]);
    int q=y+1;
    int tmq=(1<<z);
    int tmp=0;
    c[0][0]=100000;
    for (int i=1;i<=z;++i){
        c[i][0]=c[i-1][0]/2;
        for (int j=1;j<=z;++j)
            c[i][j]=(c[i-1][j]+c[i-1][j-1])/2;
    }
    double ans=0;
    for (int i=q;i<=z;++i)
        ans+=c[z][i];
    return ans/100000;
}

int main(){
    int T;
    //freopen("input.txt","r",stdin);
    freopen("B.in","r",stdin);
    freopen("outpp.txt","w",stdout);
    prework();
    scanf("%d",&T);
    for (int i=1;i<=T;++i){
        scanf("%d%d%d",&n,&x,&y);
        printf("Case #%d: %.6lf\n",i,calc());
    }
    return 0;
}
