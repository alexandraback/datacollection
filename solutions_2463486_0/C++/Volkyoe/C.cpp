#include"stdio.h"
#include"math.h"
#include"stdlib.h"
#include"string.h"
int t,T,i,j,a,b,tmp[20],count;
int OK = 1;
bool isPalin(int x){
    for(j=0;x>0;j++,x/=10) tmp[j]=x%10;
    for(int k=0;k<=j/2;k++) if(tmp[k]!=tmp[j-1-k]) return false;
    return true;
}
int main(){
    if(OK){
        freopen("1.in","r",stdin);
        freopen("1.txt","w",stdout);
    }
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        count=0;
        scanf("%d%d",&a,&b);
        i=(int)sqrt(a);
        if(i*i<a) a=i+1;
        else a=i;
        b=(int)sqrt(b);
        for(i=a;i<=b;i++)
            if(isPalin(i)) if(isPalin(i*i)) count++; //printf("%d %d\n",i,i*i);
        printf("Case #%d: %d\n",t,count);
    }
    
    scanf(" ");
}
