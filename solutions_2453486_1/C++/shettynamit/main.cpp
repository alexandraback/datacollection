#include <iostream>
#include <cstdio>

using namespace std;

string B[4];
int win(char p)
{
    int i,j;
    //rows
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(B[i][j]!=p&&B[i][j]!='T')
                break;
        }
        if(j>=4)
            return 1;
    }
    for(j=0;j<4;j++)
    {
        for(i=0;i<4;i++)
        {
            if(B[i][j]!=p&&B[i][j]!='T')
                break;
        }
        if(i>=4)
            return 1;
    }
    for(i=0;i<4;i++)
        if(B[i][i]!=p&&B[i][i]!='T')
            break;
    if(i>=4)
        return 1;
    for(i=0;i<4;i++)
        if(B[i][3-i]!=p&&B[i][3-i]!='T')
            break;
    if(i>=4)
        return 1;
    return 0;
}

int draw() {
    int i,j;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            if(B[i][j]=='.')
                return 0;
    return 1;
}

int main()
{
    int n;
    string line;
    freopen("large.in","r",stdin);
    freopen("large.out","w",stdout);
    cin>>n;
    for(int c=1;c<=n;c++)
    {
        cout<<"Case #"<<c<<": ";
        for(int i=0;i<4;i++)
        {
            cin>>B[i];
            //cout<<"["<<B[i]<<"]"<<endl;
        }
        if(win('X'))
            cout<<"X won";
        else if(win('O'))
            cout<<"O won";
        else if(draw())
            cout<<"Draw";
        else
            cout<<"Game has not completed";
        cout<<endl;
        //cin>>line;
    }
    return 0;
}
