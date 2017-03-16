#include <stdio.h>
int dirx[]={0,1,0,-1};
int diry[]={1,0,-1,0};
char dir[]={'N','E','S','W'};
int X,Y;
int memo[202][202][502];
int visit[202][202][502],True;
int move[202][202][502];
int dp(int x,int y,int m){
    int i;
    if(x==X&&y==Y) return 0;
    if(m>500) return m;
    if(visit[x][y][m]==True) return memo[x][y][m];
    visit[x][y][m]=True;
    int ret[4]={1000,1000,1000,1000};
    if(y+m<=200&&y+m>=0) ret[0]=1+dp(x,y+m,m+1);
    if(x+m<=200&&x+m>=0) ret[1]=1+dp(x+m,y,m+1);
    if(y-m<=200&&y-m>=0) ret[2]=1+dp(x,y-m,m+1);
    if(x-m<=200&&x-m>=0) ret[3]=1+dp(x-m,y,m+1);
    int mini=ret[0];
    for(i=1;i<=3;++i) if(ret[i]<mini) mini=ret[i];
    for(i=0;i<=3;++i){
        if(mini==ret[i]){
            move[x][y][m]=i;
            memo[x][y][m]=ret[i];
            break;
        }
    }
    return memo[x][y][m];
}
int main(){
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cc=1;cc<=t;++cc){
        scanf("%d %d",&X,&Y);
        X+=100,Y+=100,++True;
        dp(100,100,1);
        printf("Case #%d: ",cc);
        int x=100,y=100,m=1;
        while(!(x==X&&y==Y)){
            printf("%c",dir[move[x][y][m]]);
            if(move[x][y][m]==0) y+=m;
            else if(move[x][y][m]==1) x+=m;
            else if(move[x][y][m]==2) y-=m;
            else x-=m;
            ++m;
        }
        printf("\n");
    }
    return 0;
}
