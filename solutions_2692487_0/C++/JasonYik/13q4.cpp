#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<queue>
#define pii pair<int,int>
#define LL long long
using namespace std;
int t,n,a,b[1100000],c,d,e;

int main(){
    scanf("%d",&t);
    for (int I=1;I<=t;I++){
        scanf("%d%d",&a,&n);
        for (int i=1;i<=n;i++) scanf("%d",&b[i]);
        if (a==1){
           printf("Case #%d: %d\n",I,n);
           continue;
        }
        sort(b+1,b+1+n);
        e=n;d=0;
        for (int i=1;i<=n;i++){
            while (a<=b[i]){
                  a+=a-1;
                  d++;
                  }
            a+=b[i];
            e=min(e,d+n-i);
        }
        printf("Case #%d: %d\n",I,e);
    }
    return 0;
}
