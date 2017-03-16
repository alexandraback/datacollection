#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<utility>
#include<cassert>
#include<ctime>
#define debug(i) cout<<#i" = "<<i<<"\n";system("pause");
#define SET(p) memset(p,-1,sizeof(p))
#define CLR(p) memset(p,0,sizeof(p))
#define S(n) scanf("%d",&n)
#define P(n) printf("%d\n",n)
#define Sl(n) scanf("%lld",&n)
#define Pl(n) printf("%lld\n",n)
#define Sf(n) scanf("%lf",&n)
#define Ss(n) scanf("%s",n)
#define LL long long
#define ULL unsigned long long
#define pb push_back
using namespace std;
int main()
{
    int test,counter=1;
    scanf("%d ",&test);
    while(test--)
    {
        char n[4][4];
        register int i,j;
        int t,o,x,dot=0;
        for(i=0; i<4; i++)
        {
            for(j=0; j<4; j++)
            {
                scanf(" %c",&n[i][j]);
            }
        }
        cout<<"Case #"<<counter++<<": ";
        for(i=0; i<4; i++)
        {
            t=x=o=0;
            for(j=0; j<4; j++)
            {
                if(n[i][j]=='T')
                    t++;
                else if(n[i][j]=='O')
                    o++;
                else if(n[i][j]=='X')
                    x++;
                else
                    dot++;
            }
            if((x==3&&t==1)||x==4)
            {
                cout<<"X won\n";
                break;
            }
            else if((o==3&&t==1)||o==4)
            {
                cout<<"O won\n";
                break;
            }
            t=x=o=0;
            for(j=0; j<4; j++)
            {
                if(n[j][i]=='T')
                    t++;
                else if(n[j][i]=='O')
                    o++;
                else if(n[j][i]=='X')
                    x++;
            }
            if((x==3&&t==1)||x==4)
            {
                cout<<"X won\n";
                break;
            }
            else if((o==3&&t==1)||o==4)
            {
                cout<<"O won\n";
                break;
            }
        }
        if(i!=4)
            continue;
        t=x=o=0;
        for(i=0; i<4; i++)
        {
            if(n[i][i]=='T')
                t++;
            else if(n[i][i]=='O')
                o++;
            else if(n[i][i]=='X')
                x++;
        }
        if((x==3&&t==1)||x==4)
        {
            cout<<"X won\n";
            continue;
        }
        else if((o==3&&t==1)||o==4)
        {
            cout<<"O won\n";
            continue;
        }
         t=x=o=0;
        for(i=3; i>=0; i--)
        {
            if(n[3-i][i]=='T')
                t++;
            else if(n[3-i][i]=='O')
                o++;
            else if(n[3-i][i]=='X')
                x++;
        }
        if((x==3&&t==1)||x==4)
        {
            cout<<"X won\n";
            continue;
        }
        else if((o==3&&t==1)||o==4)
        {
            cout<<"O won\n";
            continue;
        }
        if(dot)
        {
            cout<<"Game has not completed\n";
        }
        else
        {
            cout<<"Draw\n";
        }
    }
}
