#include<cstdio>
int T,x,y;
int main(){
    scanf("%d",&T);
    for (int o=1; o<=T; o++){
        scanf("%d%d",&x,&y);
        printf("Case #%d: ",o);
        if (x<0)
           for (int i=1; i<=-x; i++) printf("EW");
        else for (int i=1; i<=x; i++) printf("WE");
        if (y<0) for (int i=1; i<=-y; i++) printf("NS");
        else for (int i=1; i<=y; i++) printf("SN");
        printf("\n");  
    }
    return 0;    
}
