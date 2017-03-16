#include <cstdio>

char dekiru[]="GABRIEL";
char dekinai[]="RICHARD";

int main()
{
    freopen("D:\\input","r",stdin);
    freopen("D:\\output","w",stdout);
    int t;
    scanf("%d",&t);
    int i;
    for(i=1;i<=t;++i){
        int x,r,c;
        scanf("%d%d%d",&x,&r,&c);
        printf("Case #%d: ",i);
        if(x==1) puts(dekiru);
        else if(x>r && x>c) puts(dekinai);
        else if(x>=7) puts(dekinai);
        else {
            if(r*c%x) puts(dekinai);
            else if(x==2) puts(dekiru);
            else {
                if(r==1 || c==1) puts(dekinai);
                else {
                    if(r>c) r^=c^=r^=c;
                    if(x==3){
                        if(r==1) puts(dekinai);
                        else puts(dekiru);
                    } else if(x==4){
                        if(r<=2) puts(dekinai);
                        else puts(dekiru);
                    } else if(x>=5){
                        if(r<=3) puts(dekinai);
                        else puts(dekiru);
                    }
                }
            }
        }
    }
    return 0;
}
