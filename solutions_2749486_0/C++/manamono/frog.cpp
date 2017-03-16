#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int x,y;
int mainx(int I)
{
    char s[503];
    int c=0;
    scanf("%d%d",&x,&y);
    for(int i=0;i<abs(y);i++)
    {
        if(y>0){
            s[c++]='S';
            s[c++]='N';
        }
        else if(y<0){
            s[c++]='N';
            s[c++]='S';
        }
    }
    for(int i=0;i<abs(x);i++){
        if(x>0){
            s[c++]='W';
            s[c++]='E';
        }
        else if(x<0){
            s[c++]='E';
            s[c++]='W';
        }
    }
    printf("Case #%d: ",I);
    for(int i=0;i<c;i++)printf("%c",s[i]);
    printf("\n");
}
int main(){
    freopen("frogin1.in","r",stdin);
    freopen("frogsmall.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        mainx(i);
    }
}
