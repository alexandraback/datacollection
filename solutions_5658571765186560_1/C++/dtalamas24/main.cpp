#include <cstdio>
#include <iostream>

using namespace std;

int casos, x, cto1, cto2;

int main()
{
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);

    scanf("%d",&casos);
    for(int v=1; v<=casos; v++){
        scanf("%d%d%d",&x,&cto1,&cto2);
        printf("Case #%d: ",v);

        if(cto1*cto2%x != 0){
            printf("RICHARD\n");
            continue;
        }
        if(x>max(cto1,cto2)){
            printf("RICHARD\n");
            continue;
        }
        if(x>6){
            printf("RICHARD\n");
            continue;
        }
        if(x > min(cto1, cto2) * 2){
            printf("RICHARD\n");
            continue;
        }

        if(x==1){
            printf("GABRIEL\n");
            continue;
        }
        if(x==2){
            if(cto1==cto2 and cto1==1){
                printf("RICHARD\n");
            }
            else {
                printf("GABRIEL\n");
            }
            continue;
        }
        if(x==3){
            printf("GABRIEL\n");
            continue;
        }
        if(x==4){
            if(min(cto1, cto2)<=2){
                printf("RICHARD\n");
            }
            else {
                printf("GABRIEL\n");
            }
            continue;
        }
        if(x==5 or x==6){
            if(min(cto1, cto2)<4){
                printf("RICHARD\n");
                continue;
            }
            printf("GABRIEL\n");
            continue;
        }
    }
    return 0;
}
