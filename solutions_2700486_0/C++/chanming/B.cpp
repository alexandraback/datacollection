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
int c[21][21];
int n,x,y;

void prework(){
    for (int i=1;i<=1000;++i)
        f[i]=(2*i*i-i);
    memset(c,0,sizeof(c));
    for (int i=0;i<21;++i)
        c[i][0]=1;
    for (int i=1;i<21;++i)
        for (int j=1;j<21;++j)
            c[i][j]=c[i-1][j]+c[i-1][j-1];
}


double calc(){
    if (x>10 || x<-10 || y>10) return 0;
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
    for (int i=z;i>=q;--i)
        tmp+=c[z][i];
    return tmp*1.0/tmq;
}

int main(){
    int T;
    //freopen("input.txt","r",stdin);
    freopen("B.in","r",stdin);
    freopen("output.txt","w",stdout);
    prework();
    scanf("%d",&T);
    for (int i=1;i<=T;++i){
        scanf("%d%d%d",&n,&x,&y);
        printf("Case #%d: %.6lf\n",i,calc());
    }
    return 0;
}
