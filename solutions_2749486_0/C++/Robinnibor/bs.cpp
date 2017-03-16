#include<stdio.h>
#include<algorithm>
#include<queue>

using namespace std;


int main()
{
    freopen("bs.in","r",stdin);
    freopen("bs.out","w",stdout);
    int cases,ii,x,y,xx,yy;
    scanf("%d",&cases);
    for(ii=1;ii<=cases;ii++){
        scanf("%d%d",&x,&y);
        printf("Case #%d: ",ii);
        xx=yy=0;
        if(x<0){
            while(xx!=x){
                printf("EW");
                xx--;
            }
        }
        else if(x>0){
            while(xx!=x){
                printf("WE");
                xx++;
            }
        }
        if(y<0){
            while(yy!=y){
                printf("NS");
                yy--;
            }
        }
        else if(y>0){
            while(yy!=y){
                printf("SN");
                yy++;
            }
        }
        printf("\n");
    }
    
    return 0;
}
