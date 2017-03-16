#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);

    int t,xcnt,ycnt,tcnt,cc=1;
    bool dot,x,y;
    string str[5];

    cin>>t;

    while(t--)
    {
        x = y = dot = false;

        for(int i=0;i<4;i++)
        {
            cin>>str[i];

            for(int j=0;j<4;j++)
            {
                if(str[i][j]=='.') dot = true;
            }
        }

        for(int i=0;i<4;i++)
        {
            tcnt = xcnt = ycnt = 0;

            for(int j=0;j<4;j++)
            {
                     if(str[i][j]=='X') xcnt++;
                else if(str[i][j]=='O') ycnt++;
                else if(str[i][j]=='T') tcnt++;
            }

            if(xcnt==4 || ((xcnt+tcnt)==4))
            {
                x = true;
            }
            else if(ycnt==4 || (ycnt+tcnt)==4)
            {
                y = true;
            }

            tcnt = xcnt = ycnt = 0;

            for(int j=0;j<4;j++)
            {
                     if(str[j][i]=='X') xcnt++;
                else if(str[j][i]=='O') ycnt++;
                else if(str[j][i]=='T') tcnt++;
            }

            if(xcnt==4 || ((xcnt+tcnt)==4))
            {
                x = true;
            }
            else if(ycnt==4 || (ycnt+tcnt)==4)
            {
                y = true;
            }

            if(x||y) break;
        }

//first corner
        xcnt = ycnt = tcnt = 0;

        for(int i=0;i<4;i++)
        {
                 if(str[i][i]=='X') xcnt++;
            else if(str[i][i]=='O') ycnt++;
            else if(str[i][i]=='T') tcnt++;
        }

        if(xcnt==4 || (xcnt+tcnt)==4)
        {
            x = true;
        }
        else if(ycnt==4 || (ycnt+tcnt)==4)
        {
            y = true;
        }

        xcnt = ycnt = tcnt = 0;

        for(int i=0;i<4;i++)
        {
                 if(str[i][3-i]=='X') xcnt++;
            else if(str[i][3-i]=='O') ycnt++;
            else if(str[i][3-i]=='T') tcnt++;
        }

        if(xcnt==4 || (xcnt+tcnt)==4)
        {
            x = true;
        }
        else if(ycnt==4 || (ycnt+tcnt)==4)
        {
            y = true;
        }

        cout<<"Case #"<<cc++<<": ";

        if(x) cout<<"X won"<<endl;
        else if(y) cout<<"O won"<<endl;
        else if(dot) cout<<"Game has not completed"<<endl;
        else cout<<"Draw"<<endl;

        cout<<endl;
    }

    return 0;
}
