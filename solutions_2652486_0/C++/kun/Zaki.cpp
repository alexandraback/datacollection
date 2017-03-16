#include<algorithm>
#include<cstdio>
int r,n,m,k,d,T;
int x[10],g[3],sv[8],ct;
using namespace std;
void Try(int i,int j){
    if(i==3){
        sv[ct++] = j;
        return ;
    }
    Try(i+1,j*g[i]);
    Try(i+1,j);
}
int Chk(){
    ct = 0;
    Try(0,1);
    for(int i=0;i<k;i++){
        for(int j=0;j<ct;j++){
            if(x[i]==sv[j]){
                goto gs;
            }
        }
        return 0;
        gs:;
    }
    return 1;
}
int W(int i,int j){
    if(i == 3){
        if( Chk()){
            for(int i=0;i<3;i++) printf("%d",g[i]); printf("\n");
            return 1;
        }
        return 0;
    }
    for(int run = j;run<=m;run++){
        g[i] = run;
        if(W(i+1,run)) return 1;
        g[i] = 0;
    }
    return 0;
}
int main(){
    freopen("C-small-1-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    printf("Case #1:\n");
        scanf("%d%d%d%d",&r,&n,&m,&k);
    while(r){
        for(int i=0;i<k;i++){
            scanf("%d",&x[i]);
        }
        int d = W(0,2);
        r--;
    }
    return 0;
}
//
