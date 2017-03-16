#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;
char ch[4][4],win;
bool draw,may_not_end;
bool scan_row(int n)
{
    char first=ch[n][0];
    if(first=='X'){
        for(int i=1;i<4;i++)
            if(ch[n][i]=='O'||ch[n][i]=='.'){
                return false;
            }
        win='X';
        return true;
    }
    else if(first=='O'){
        for(int i=1;i<4;i++)
            if(ch[n][i]=='X'||ch[n][i]=='.'){
                return false;
            }
        win='O';
        return true;
    }
    else if(first=='T'){
        char temp=ch[n][1];
        if(temp=='.')
            return false;
        for(int i=2;i<4;i++)
            if(ch[n][i]!=temp){
                return false;
            }
        win=temp;
        return true;
    }
    else
        return false;
}
bool scan_col(int n)
{
    char first=ch[0][n];
    if(first=='X'){
        for(int i=1;i<4;i++)
            if(ch[i][n]=='O'||ch[i][n]=='.'){
                return false;
            }
        win='X';
        return true;
    }
    else if(first=='O'){
        for(int i=1;i<4;i++)
            if(ch[i][n]=='X'||ch[i][n]=='.'){
                return false;
            }
        win='O';
        return true;
    }
    else if(first=='T'){
        char temp=ch[1][n];
        if(temp=='.')
            return false;
        for(int i=2;i<4;i++)
            if(ch[i][n]!=temp){
                return false;
            }
        win=temp;
        return true;
    }
    else
        return false;
}
bool scan_diag_1()
{
    char temp=ch[0][0];
    if(temp=='X'){
        for(int i=1;i<4;i++)
            if(ch[i][i]=='O'||ch[i][i]=='.')
                return false;
        win='X';
        return true;
    }
    else if(temp=='O'){
        for(int i=1;i<4;i++)
            if(ch[i][i]=='X'||ch[i][i]=='.')
                return false;
        win='O';
        return true;
    }
    else if(temp=='T'){
        temp=ch[1][1];
        if(temp=='.')
            return false;
        for(int i=2;i<4;i++)
            if(ch[i][i]!=temp)
                return false;
        win=temp;
        return true;
    }
    else
        return false;
}
bool scan_diag_2()
{
    char temp=ch[3][0];
    if(temp=='X'){
        for(int i=1;i<4;i++)
            if(ch[3-i][i]=='O'||ch[3-i][i]=='.')
                return false;
        win='X';
        return true;
    }
    else if(temp=='O'){
        for(int i=1;i<4;i++)
            if(ch[3-i][i]=='X'||ch[3-i][i]=='.')
                return false;
        win='O';
        return true;
    }
    else if(temp=='T'){
        temp=ch[2][1];
        if(temp=='.')
            return false;
        for(int i=2;i<4;i++)
            if(ch[3-i][i]!=temp)
                return false;
        win=temp;
        return true;
    }
    else
        return false;
}
int main()
{
    FILE *fp,*fp_;
    freopen_s(&fp,"data.in","r",stdin);
    freopen_s(&fp_,"data.out","w",stdout);
    int T;
    cin>>T;
    for(int k=0;k<T;k++){
        draw=true;
        may_not_end=false;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++){
                cin>>ch[i][j];
                if(ch[i][j]=='.')
                    may_not_end=true;
            }
        for(int i=0;i<4;i++){
            if(scan_row(i)){
                cout<<"Case #"<<k+1<<": "<<win<<" won"<<endl;
                draw=false;
                break;
            }
            if(scan_col(i)){
                cout<<"Case #"<<k+1<<": "<<win<<" won"<<endl;
                draw=false;
                break;
            }
        }
        if(draw){
            if(scan_diag_1()){
                cout<<"Case #"<<k+1<<": "<<win<<" won"<<endl;
                continue;
            }
            if(scan_diag_2()){
                cout<<"Case #"<<k+1<<": "<<win<<" won"<<endl;
                continue;
            }
            if(may_not_end)
                cout<<"Case #"<<k+1<<": "<<"Game has not completed"<<endl;
            else
                cout<<"Case #"<<k+1<<": "<<"Draw"<<endl;
        }
    }
    fcloseall();
    return 0;
}