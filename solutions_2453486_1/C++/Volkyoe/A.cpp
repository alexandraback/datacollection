#include"stdio.h"
#include"math.h"
#include"stdlib.h"
#include"string.h"
int a[4][4],row[4],col[4],dia[4],T,t,i,j,full,tmp,end;
char s[10];
int OK = 1;
int main(){
    if(OK){
        freopen("1.in","r",stdin);
        freopen("1.txt","w",stdout);
    }
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        full=1;
        for(i=0;i<4;i++) row[i]=col[i]=dia[i]=0;
        for(i=0;i<4;i++)
        {
            scanf("%s",s);
            for(j=0;j<4;j++)
            {
                tmp=0;
                if(s[j]=='X') tmp=-5;
                else if(s[j]=='O') tmp=5;
                else if(s[j]=='T') tmp=500;
                else full=0;
                row[i]+=tmp;
                col[j]+=tmp;
                if(i==j) dia[0]+=tmp;
                if(i+j==3) dia[1]+=tmp;
            }
        }
        printf("Case #%d: ",t);
        for(end=i=0;i<4;i++)
        {
            if(row[i]==-20||row[i]==485||col[i]==-20||col[i]==485||dia[i]==-20||dia[i]==485){ end=1; break;}
            else if(row[i]==20||row[i]==515||col[i]==20||col[i]==515||dia[i]==20||dia[i]==515){ end=2; break; }
        }
        if(end==1) printf("X won\n");
        else if(end==2) printf("O won\n");
        else if(full) printf("Draw\n");
        else printf("Game has not completed\n");
    }
    scanf(" ");
}
