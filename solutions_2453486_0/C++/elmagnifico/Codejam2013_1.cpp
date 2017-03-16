/*
Original Author: El_Magnifico(Sudhanshu Shekhar)
*/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cctype>
#include<sstream>
#include<cmath>
#include<list>
#include<climits>
#include<stack>
#include<map>
#include<bitset>
#include<queue>
#include<set>
#include<climits>
#include<cstring>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
typedef long long ll;
int main()
{
    freopen("C:\\Users\\Psyduck\\Desktop\\A-small-attempt0.in","r",stdin);
    freopen("C:\\Users\\Psyduck\\Desktop\\output.txt","w",stdout);
    ll i,j,k,n,m,t,tcase,X,O,T,blank;
    bool end=false;
    char input[4][4];
    cin>>tcase;
    for(t=1;t<=tcase;t++)
    {
        X=0;O=0;T=0;blank=0;end=false;
        cout<<"Case #"<<t<<": ";
        for(i=0;i<4;i++)for(j=0;j<4;j++){cin>>input[i][j];if(input[i][j]=='.')blank++;}
        //for(i=0;i<4;i++){for(j=0;j<4;j++)cout<<input[i][j]<<" ";cout<<endl;}
        i=0;j=0;

        for(i=0;i<4;i++)
        {
            X=0;O=0;T=0;
            for(j=0;j<4;j++)
            {
                if(input[i][j]=='X')X++;
                else if(input[i][j]=='O')O++;
                else if(input[i][j]=='T')T++;
            }
            if(X+T==4){cout<<"X won"<<endl;end=true;break;}
            if(O+T==4){cout<<"O won"<<endl;end=true;break;}
        }

        if(end)continue;

        for(j=0;j<4;j++)
        {
            X=0;O=0;T=0;
            for(i=0;i<4;i++)
            {
                if(input[i][j]=='X')X++;
                else if(input[i][j]=='O')O++;
                else if(input[i][j]=='T')T++;
            }
            if(X+T==4){cout<<"X won"<<endl;end=true;break;}
            if(O+T==4){cout<<"O won"<<endl;end=true;break;}
        }

        if(end)continue;

        X=0;O=0;T=0;
        for(i=0;i<4;i++)
        {
            if(input[i][i]=='X')X++;
            if(input[i][i]=='O')O++;
            if(input[i][i]=='T')T++;
        }
        if(X+T==4){cout<<"X won"<<endl;end=true;}
        if(O+T==4){cout<<"O won"<<endl;end=true;}

        if(end)continue;

        X=0;O=0;T=0;
        for(i=0;i<4;i++)
        {
            if(input[i][3-i]=='X')X++;
            if(input[i][3-i]=='O')O++;
            if(input[i][3-i]=='T')T++;
        }
        if(X+T==4){cout<<"X won"<<endl;end=true;}
        if(O+T==4){cout<<"O won"<<endl;end=true;}

        if(end)continue;

        if(!end && blank==0)cout<<"Draw"<<endl;
        else if(!end && blank>0)cout<<"Game has not completed"<<endl;
    }
    return 0;
}
