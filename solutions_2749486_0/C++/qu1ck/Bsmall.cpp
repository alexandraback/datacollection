#include <cstdio>
#include <cstring>

int main() {
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int ncase;
    scanf("%d",&ncase);
    for(int C=1;C<=ncase;C++){
        printf("Case #%d: ",C);
        int x,y;
        scanf("%d%d",&x,&y);
        if(x>0){
            for(int i=0;i<x;i++)printf("WE");
        }else{
            for(int i=0;i<-x;i++)printf("EW");
        }
        if(y>0){
            for(int i=0;i<y;i++)printf("SN");
        }else{
            for(int i=0;i<-y;i++)printf("NS");
        }
        puts("");
    }
    return 0;
}