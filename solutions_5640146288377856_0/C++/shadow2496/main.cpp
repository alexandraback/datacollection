#include<stdio.h>

int T;

int R,C,W;
int Print;

int Output(int c)
{
    printf("Case #%d: %d\n",c,Print);
    return 0;
}

int Process()
{
    Print=0;

    while(1){
        if(W*2>C){
            Print+=(R-1);
            Print+=C<(W+1)?C:W+1;
            break;
        }

        Print+=R;
        C-=W;
    }
    return 0;
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);

    scanf("%d",&T);

    int i;
    for(i=1;i<=T;i++){
        scanf("%d %d %d",&R,&C,&W);

        Process();
        Output(i);
    }
    return 0;
}
