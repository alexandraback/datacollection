#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int G[5][5];
int main(){
    int T,n,m,i,j,k,l,tt;
    char ch;
    freopen("A.out","w",stdout);
    scanf("%d",&T);
    tt=0;
    while(T--){
        tt++;
        for(i=1;i<=4;i++)
            for(j=1;j<=4;j++){
                ch=getchar();
                while(ch!='X'&&ch!='O'&&ch!='T'&&ch!='.')ch=getchar();
                if(ch=='X')G[i][j]=0;
                else if(ch=='O')G[i][j]=1;
                else if(ch=='T')G[i][j]=2;
                else G[i][j]=3;
            }
        int ans=-1;
        for(i=1;i<=4;i++){
            int s[2]={0},fl=0;
            for(j=1;j<=4;j++){
                if(G[i][j]<=1)s[G[i][j]]++;
                else if(G[i][j]==2)fl=1;
            }
            if(fl&&s[0]==3||s[0]==4)ans=0;
            if(fl&&s[1]==3||s[1]==4)ans=1;
        }
        for(i=1;i<=4;i++){
            int s[2]={0},fl=0;
            for(j=1;j<=4;j++){
                if(G[j][i]<=1)s[G[j][i]]++;
                else if(G[j][i]==2)fl=1;
            }
            if(fl&&s[0]==3||s[0]==4)ans=0;
            if(fl&&s[1]==3||s[1]==4)ans=1;
        }
        {
            int s[2]={0},fl=0;
            for(j=1;j<=4;j++){
                if(G[j][j]<=1)s[G[j][j]]++;
                else if(G[j][j]==2)fl=1;
            }
            if(fl&&s[0]==3||s[0]==4)ans=0;
            if(fl&&s[1]==3||s[1]==4)ans=1;
        }
        {
            int s[2]={0},fl=0;
            for(j=1;j<=4;j++){
                if(G[j][5-j]<=1)s[G[j][5-j]]++;
                else if(G[j][5-j]==2)fl=1;
            }
            if(fl&&s[0]==3||s[0]==4)ans=0;
            if(fl&&s[1]==3||s[1]==4)ans=1;
        }
        printf("Case #%d: ",tt);
        if(ans==0)printf("X won\n");
        else if(ans==1)printf("O won\n");
        else {
            int fl=0;
            for(i=1;i<=4;i++)
                for(j=1;j<=4;j++)
                    if(G[i][j]==3)fl=1;
            if(fl)printf("Game has not completed\n");
            else printf("Draw\n");
        }
    }
    return 0;
}

        

