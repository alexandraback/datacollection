#include<stdio.h>
char p[110];
int main(){
    int i, n, res, TC,TT;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&TC);
    for(TT=1;TT<=TC;TT++){
        printf("Case #%d: ",TT);
        scanf("%s",p);
        for(i=0;p[i];i++);
        n=i;
        res=0;
        if(p[n-1]=='-')res++;
        for(i=0;i<n-1;i++){
            if(p[i]!=p[i+1])res++;
        }
        printf("%d\n",res);
    }
}
