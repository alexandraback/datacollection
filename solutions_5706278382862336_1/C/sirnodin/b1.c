/*=============================================================================
#     FileName: b1.c
#         Desc: 
#       Author: zhangc
#        Email: sirnodin@gmail.com
#     HomePage: 
#      Version: 0.0.1
#     CreateOn: 2014-05-11 17:21:56
#   LastChange: 2014-05-11 17:36:17
#      History:
=============================================================================*/
#include <stdio.h>
int T,CASE;
unsigned long long P,Q;
unsigned long long bbb(unsigned long long a,unsigned long long b){
    if((a)%(b)==0) return b;
    else return bbb(b,a%b);
}
void bsd(){
    unsigned long long ff=bbb(Q,P);
    P/=ff;
    Q/=ff;
}
unsigned long long TP[50];
int main(){
    scanf("%d",&T);
    int i;
    unsigned long long temp=1L;
    for(i=0;i<50;++i){
        TP[i]=temp;
        temp*=2L;
    }
    for(CASE=1;CASE<=T;++CASE){
        scanf("%lld/%lld",&P,&Q);
        bsd();
        for(i=0;i<50;++i){
            if(Q==TP[i]) break;
        }
        printf("Case #%d: ",CASE);
        if(i>40) printf("impossible\n");
        else{
            for(i=0;i<50;++i){
                {
                    if(TP[i]*P>=Q) break;
                }
            }
            printf("%d\n",i);
        }
    }
}
