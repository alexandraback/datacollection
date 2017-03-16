#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef long long LL;

int ca, x,y;

int main(){
    int ca; scanf("%d",&ca);
    for (int tt=1; tt<=ca; tt++){
        scanf("%d%d",&x,&y);
        printf("Case #%d: ", tt);
        for (int i=0; i<abs(x); i++){
            if (x>0) printf("WE");
            else printf("EW");
        }
        for (int i=0; i<abs(y); i++){
            if (y>0) printf("SN");
            else printf("NS");
        }
        puts("");
    }
    return 0;
}
