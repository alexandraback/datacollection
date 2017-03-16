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
#define MAXN 1000100
#define MAXM 1
#define INF (1<<30)
#define PI 3.1415926535898
#define esp 10e-6
#define Si size()
const int dx[4]={1,0,-1,0};
const int dy[4]={0,-1,0,1};
using namespace std;
int n,m;
int a[MAXN];

void init(){
    scanf("%d%d",&m,&n);
    for (int i=0;i<n;++i)
        scanf("%d",&a[i]);
    sort(a,a+n);
}

void work(){
    long long tmq=m;
    if (tmq==1){
        printf("%d\n",n);
        return;
    }
    int tmp=0;
    int Ans=n;
    for (int i=0;i<n;++i){
        if (tmp+n-i<Ans)
            Ans=tmp+n-i;
        if (tmq>a[i])
            tmq+=a[i];
        else{
            while (tmq<=a[i]){
                tmq=tmq*2-1;
                tmp++;
            }
            tmq+=a[i];
        }
    }
    if (tmp<Ans) Ans=tmp;
    printf("%d\n",Ans);
}
int main(){
    freopen("A.in","r",stdin);
    //freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int i=1;i<=T;++i){
        init();
        printf("Case #%d: ",i);
        work();
    }
    return 0;
}
