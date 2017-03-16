#include<bits/stdc++.h>
using namespace std;
int T,n,x;
int f[3234];
int main(){
    freopen("t.in","r",stdin);
    freopen("t.out","w",stdout);
    scanf("%d",&T);

    for(int ti=1;ti<=T;ti++){
        printf("Case #%d: ",ti);
        for(int i=0;i<2600;i++)f[i]=0;
        scanf("%d",&n);
        for(int i=0;i<2*n-1;i++)
            for(int j=0;j<n;j++){
                scanf("%d",&x);
                f[x]++;
            }
        bool v=false;
        for(int i=0;i<2600;i++)if(f[i]%2==1){
            if(v) printf(" ");
            printf("%d",i);

            v=true;
        }
        printf("\n");


    }


}
