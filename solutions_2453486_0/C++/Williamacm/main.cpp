#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
char s[4][5];
int x,y;
char test(char k)
{
    if(x>=0) s[x][y]=k;
    for(int i=0;i<4;i++)
    if(s[i][0]==s[i][1]&&s[i][1]==s[i][2]&&s[i][2]==s[i][3]&&s[i][3]==k) return k;
    for(int i=0;i<4;i++)
    if(s[0][i]==s[1][i]&&s[1][i]==s[2][i]&&s[2][i]==s[3][i]&&s[3][i]==k) return k;
    if(s[0][0]==s[1][1]&&s[1][1]==s[2][2]&&s[2][2]==s[3][3]&&s[3][3]==k) return k;
    if(s[0][3]==s[1][2]&&s[1][2]==s[2][1]&&s[2][1]==s[3][0]&&s[3][0]==k) return k;
    return 0;
}
char init()
{
    int cnt=0;
    x=y=-1;
    for(int i=0;i<4;i++)
    {
        scanf("%s",s[i]);
        for(int j=0;j<4;j++)
        {
            if(s[i][j]=='T') {x=i,y=j;}
            if(s[i][j]=='.') cnt++;
        }
    }
    if(test('X')) return 'X';
    if(test('O')) return 'O';


    if(cnt==0) return 0;
    else return 1;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out","w",stdout);
    int w;cin>>w;
    int cnt=1;
    while(w--)
    {
        printf("Case #%d: ",cnt++);
        char k=init();
        if(k==0) puts("Draw");
        else
        if(k==1) puts("Game has not completed");
        else printf("%c won\n",k);
    }
//    cout << "Hello world!" << endl;
    return 0;
}
