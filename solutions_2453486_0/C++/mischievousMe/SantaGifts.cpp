#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

#define pb push_back
#define mp make_pair
typedef pair<int, int> ii;
typedef vector<int> vi;

int main()
{
    //freopen("sb.in","r",stdin);
    //freopen("sb.out","w",stdout);
    int t;
    cin>>t;
    int x=0;
    while(t--)
    {
        x++;
        vector<string>board(4);
        for(int i=0;i<4;i++) cin>>board[i];
        int xw=0,ow=0;
        bool drw=true;
        //checking rows
        for(int i=0;i<4;i++)
        {
            int cx=0,co=0,tt=0;
            for(int j=0;j<4;j++)
            {
                if(board[i][j]=='X') cx++;
                else if(board[i][j]=='O') co++;
                else if(board[i][j]=='T') tt++;
                else drw=false;
            }
            if(cx==4||(cx+tt)==4)
                xw=1;
            else if(co==4||(co+tt)==4)
                ow=1;
        }
        if(xw)
            {cout<<"Case #"<<x<<": "<<"X won\n";  continue;}
        else if(ow) {cout<<"Case #"<<x<<": "<<"O won\n"; continue;}
        //checking columns
        for(int i=0;i<4;i++)
        {
            int cx=0,co=0,tt=0;
            for(int j=0;j<4;j++)
            {
                if(board[j][i]=='X') cx++;
                else if(board[j][i]=='O') co++;
                else if(board[j][i]=='T') tt++;
            }
            if(cx==4||(cx+tt)==4)
            {
                xw=1;
                break;
            }
            else if(co==4||(co+tt)==4)
            {
                ow=1;
                break;
            }
        }
        if(xw)
            {cout<<"Case #"<<x<<": "<<"X won\n";  continue;}
        else if(ow) {cout<<"Case #"<<x<<": "<<"O won\n"; continue;}
        //checking both the diagonals
        int cx=0,co=0,tt=0;
        for(int i=0;i<4;i++)
        {
            if(board[i][i]=='X') cx++;
            else if(board[i][i]=='O') co++;
            else if(board[i][i]=='T') tt++;
        }
        if(cx==4||(cx+tt)==4)
        {
            cout<<"Case #"<<x<<": "<<"X won\n";
            continue;
        }
        else if(co==4||(co+tt)==4)
        {
            cout<<"Case #"<<x<<": "<<"O won\n"; continue;
        }
        cx=0;
        co=0;
        tt=0;
        for(int i=0;i<4;i++)
        {
            if(board[i][3-i]=='X') cx++;
            else if(board[i][3-i]=='O') co++;
            else if(board[i][3-i]=='T') tt++;
        }
        if(cx==4||(cx+tt)==4)
        {
            cout<<"Case #"<<x<<": "<<"X won\n";
            continue;
        }
        else if(co==4||(co+tt)==4)
        {
            cout<<"Case #"<<x<<": "<<"O won\n"; continue;
        }
        if(drw) cout<<"Case #"<<x<<": "<<"Draw\n";
        else cout<<"Case #"<<x<<": "<<"Game has not completed\n";
    }
    return 0;
}
