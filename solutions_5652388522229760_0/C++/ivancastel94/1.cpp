#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int i,j,aux,n,cases,t;
    bool dig[10],cont;
    scanf("%d",&t);
    cases=1;
    while(cases<=t){
        scanf("%d",&n);
        printf("Case #%d: ",cases);
        if(n==0){
            printf("INSOMNIA\n");
        }
        else{
            memset(dig, 0, sizeof dig);
            cont=true;
            j=1;
            while(cont){
                aux=j*n;
                while(aux>0){
                    dig[aux%10]=1;
                    aux=aux/10;
                }
                cont=false;
                for(i=0;i<10;i++)if(!dig[i])cont=true;
                j++;
            }
            n=(j-1)*n;
            printf("%d\n",n);
        }
        cases++;
    }
}
