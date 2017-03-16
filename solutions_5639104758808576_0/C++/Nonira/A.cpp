#include<stdio.h>

int t,n,i,j,c,a;
char st[1010];

int main(){
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d %s",&n,st);
        c=0;
        a=0;
        for(j=0;j<=n;j++){
            if(c<j){
                c++;
                a++;
            }
            c+=st[j]-'0';
        }
        printf("Case #%d: %d\n",i,a);
    }
    return 0;
}
