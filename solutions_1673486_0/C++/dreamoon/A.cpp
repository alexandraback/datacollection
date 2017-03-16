#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<set>
#include<queue>
#include<map>
using namespace std;
#define SIZE 100010
double dp[SIZE],p[SIZE];
int main(){
    int T,i,j,A,B,cs=0;
    scanf("%d",&T);
    while(T--){
        double an;
        scanf("%d%d",&A,&B);
        for(i=1;i<=A;i++)scanf("%lf",&p[i]);
        an=2+B;
        double now=1;
        for(i=1;i<=A;i++){
            now*=p[i];
            an=min(an,now*(B-i+A-i+1)+(1-now)*(B-i+A-i+1+B+1));
        }
        printf("Case #%d: %.6lf\n",++cs,an);
    }
    return 0;
}
