#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
typedef long  long LL;

const int N = 1000005;
const int inf = 1<<28;
const double eps = 1e-8;
using namespace std;

int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,cas=1;
    scanf("%d",&t);
    while(t--){
        int a,n;
        int b[105],i;
        int res,tmp=0;
        scanf("%d%d",&a,&n);
        res=n;
        for(i=0;i<n;i++){
            scanf("%d",&b[i]);
        }
        if(a==1){
            printf("Case #%d: %d\n",cas++,res);
            continue;
        }
        sort(b,b+n);
        for(i=0;i<n;i++){
            while(a<=b[i]){
                a=a*2-1;
                tmp++;
            }
            res=min(res,tmp+n-i-1);
            a+=b[i];
        }
        printf("Case #%d: %d\n",cas++,res);
    }
    return 0;
}




