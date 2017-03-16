#include <stdio.h>

int check[1000],fr[1000],reci[1000],Ans[1000],M,N;

void longest (int next)
{
    int k=0;
    int x = Ans[next-1];
        //printf("%d %d\n",next,x);
        if(check[fr[x]] == 0){
            check[fr[x]] = 1;
            Ans[next] = fr[x];
            k = 1;
            longest(next + 1);
            check[fr[x]] = 0;
        }
        else if (reci[x] != -1 && Ans[next-2] == fr[x] && check[reci[x]] == 0) {
            check[reci[x]] = 1;
            Ans[next] = reci[x];
            k = 1;
            longest(next + 1);
            check[reci[x]] = 0;
        }
    if(M < next && (Ans[next-2] == fr[x] || Ans[0] == fr[x])){
        /*for(int i=0;i<next;i++)
            printf("%d ",Ans[i]);
        printf("\n");*/
        M = next;
    }
}

int main()
{
    int T,i,C,temp,j;
    scanf("%d",&T);
    for(C=1;C<=T;C++){
        M = 0;
        scanf("%d",&N);
        for(i=0;i<N;i++) {
            check[i] = 0;
            Ans[i] = 0;
            fr[i] = -1;
            reci[i] = -1;
        }
        for(i=0;i<N;i++)
        {
            scanf("%d",&temp);
            temp--;
            fr[i] = temp;
            reci[temp] = i;
            //printf("%d %d\n",i,fr[i]);
        }
        for(i=0;i<N;i++){
            Ans[0] = i;
            check[i] = 1;
            longest(1);
            check[i] = 0;
        }
        printf("Case #%d: %d\n",C,M);
    }
    return 0;
}
