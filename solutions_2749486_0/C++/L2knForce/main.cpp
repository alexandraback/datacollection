#include <cstdio>

int mainrun(){
    int x,y;
    scanf("%d %d",&x,&y);
    while(y>0){
        printf("SN");
        y--;
    }
    while(y<0){
        printf("NS");
        y++;
    }
    while(x>0){
        printf("WE");
        x--;
    }
    while(x<0){
        printf("EW");
        x++;
    }
    printf("\n");
}

int main(){
    freopen("tt.in","r",stdin);
    freopen("tt.out","w",stdout);
    int total;
    scanf("%d",&total);
    for(int c=1;c<=total;c++){
        printf("Case #%d: ",c);
        mainrun();
    }
    return 0;
}
