#include <stdio.h>
int main()
{
    freopen("aaa.in","r",stdin);
    freopen("aaa.out","w",stdout);
    int t[1000],r[1000],c[1000],w[1000];
    int i,j,k,sonuc,ilkvurma=0;
    scanf("%d",&i);
    for(j=0;j<i;j++){scanf("%d%d%d",&r[j],&c[j],&w[j]);}
    for(j=0;j<i;j++){
        sonuc=0;
        if(w[j]== 1)printf("Case #%d: %d\n",j+1,c[j]*r[j]);
        else{
             sonuc+= (c[j]/w[j])*(r[j]-1);
             if(c[j]%w[j] == 0)sonuc+= w[j]-1 + (c[j]/w[j]);
             else sonuc+= w[j] -1 + (c[j]/w[j]) +1;
             printf("Case #%d: %d\n", j+1, sonuc);


            }




                    }
    return 0;
        }
