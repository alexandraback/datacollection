#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;
char a[10][10];
int T;
char ch[2];
bool p[2];
void Win(int x)
{
    p[x]=false;
    int need,temp;
    for(int i=0;i<4;i++)
    {
        need=0,temp=0;
        for(int j=0;j<4;j++)
        {
            if(a[i][j]==ch[x])
                need++;
            else if(a[i][j]=='T')
                temp++;
        }
        if(need==4 || (need==3 && temp==1))
            p[x]=true;
            
        
        need=0,temp=0;
        for(int j=0;j<4;j++)
            if(a[j][i]==ch[x])
                need++;
            else if(a[j][i]=='T')
                temp++;
                
         if(need==4 || (need==3 && temp==1))
            p[x]=true;
    }
    need=0,temp=0;
    for(int i=0;i<4;i++)
    {
        if(a[i][i]==ch[x])
            need++;
        else if(a[i][i]=='T')
            temp++;
    }
    if(need==4 || (need==3 && temp==1))
       p[x]=true;

    need=0,temp=0;
    for(int i=0;i<4;i++)
    {
        if(a[i][4-1-i]==ch[x])
            need++;
        else if(a[i][4-1-i]=='T')
            temp++;
    }
    if(need==4 || (need==3 && temp==1))
       p[x]=true;
}
int main(long long argc, char *argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&T);
    ch[0]='O',ch[1]='X';
    int cas=1;
    while(T--)
    {
        for(int i=0;i<4;i++)
            scanf("%s",a[i]); 
        bool finish=true;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
            if(a[i][j]=='.')
            {
                finish=false;
                break;
            }   

        for(int i=0;i<2;i++)
            Win(i);
        if(p[0])
            printf("Case #%d: O won\n",cas++);
        else if(p[1])
            printf("Case #%d: X won\n",cas++);
        else
        {
            if(!finish)
                printf("Case #%d: Game has not completed\n",cas++);
            else
                printf("Case #%d: Draw\n",cas++);
        } 
    }
    

    return 0;
}
