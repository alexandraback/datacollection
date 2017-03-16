#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<vector>
#include<string>
#include<set>
#define clr(x,y) memset(x,y,sizeof(x))
#define ll unsigned long long
using namespace std;

double inf = 1e18;
double eps=1e-10;
double c,f,x;

int main(){
    freopen("/home/zyc/Downloads/in","r",stdin);
    freopen("/home/zyc/Downloads/out","w",stdout);
//    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        scanf("%lf%lf%lf",&c,&f,&x);
        double temp = 2;
        double ans = inf;
        double t=0;
        do{
            ans = min(ans,t+x/temp);
            t += c/temp;
            temp += f;
        }while(t<ans);
        printf("Case #%d: %.10lf\n",++cas,ans);
    }
    return 0;
}
