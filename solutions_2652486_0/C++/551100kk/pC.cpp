#include<stdio.h>
int s[10];
int main(){
    freopen("C-small-1-attempt0.in","r",stdin);
    freopen("C-small-1-attempt0.out","w",stdout);
    int t,k,i,j,R,N,M,K,now,r,ne,a,b,c;
    while(scanf("%d",&t)!=EOF){
        printf("Case #1:\n");
        scanf("%d%d%d%d",&R,&N,&M,&K);
        for(k=1;k<=R;k++){
            for(i=0;i<K;i++){
                scanf("%d",&s[i]);
            }
            for(a=2;a<=5;a++){
                for(b=2;b<=5;b++){
                    for(c=2;c<=5;c++){
                        now=1;
                        for(i=0;i<K;i++){
                            if(s[i]==1 || s[i]==a || s[i]==b || s[i]==c || s[i]==a*b || s[i]==a*c || s[i]==b*c || s[i]==a*b*c){
                                now=1;
                            }
                            else{
                                now=0;
                                break;
                            }
                        }
                        if(now){
                            printf("%d%d%d\n",a,b,c);
                            goto go;
                        }
                    }
                }
            }
            go:;
        }
    }
}
