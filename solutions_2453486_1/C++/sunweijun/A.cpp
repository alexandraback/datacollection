#include<cstdio>
#include<cstring>
#define fo(i,a,b) for(i=a;i<=b;++i)
int Q,T;
char f[10][10],s1[10][10],s2[10][10];
bool win(char ch,char f[][10])
{
    int i,j,s;
    fo(i,1,4)
        fo(j,1,4)
            if(f[i][j]=='T')f[i][j]=ch;
    fo(i,1,4)
    {
        s=0;
        fo(j,1,4)s+=f[i][j]==ch;
        if(s==4)return 1;
    }
    fo(i,1,4)
    {
        s=0;
        fo(j,1,4)s+=f[j][i]==ch;
        if(s==4)return 1;
    }
    s=0;
    fo(i,1,4)
        s+=f[i][i]==ch;
    if(s==4)return 1;
    s=0;
    fo(i,1,4)s+=f[i][4-i+1]==ch;
    if(s==4)return 1;
    return 0;
}
bool full(char f[][10])
{
    int i,j;
    fo(i,1,4)
        fo(j,1,4)
            if(f[i][j]=='.')return 0;
    return 1;
}
int main()
{
    scanf("%d",&Q);
    fo(T,1,Q)
    {
        int i;
        fo(i,1,4)
            scanf("%s",f[i]+1);
        memcpy(s1,f,sizeof f);
        memcpy(s2,f,sizeof f);
        printf("Case #%d: ",T);
        if(win('X',s1))puts("X won");
        else if(win('O',s2))puts("O won");
        else if(!full(f))puts("Game has not completed");
        else puts("Draw");
    }
    return 0;
}
