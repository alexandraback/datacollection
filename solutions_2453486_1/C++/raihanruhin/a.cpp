#include<iostream>
#include<cstdio>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>
#include<deque>
#include<iterator>
#include<assert.h>
#include<bitset>
#include<climits>
#include<ctime>
#include<complex>

using namespace std;

#define SET(a) memset(a,-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define PB push_back
#define PI acos(-1.0)
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define READ freopen("a1.in", "r", stdin)
#define WRITE freopen("a1.out", "w", stdout)
#define LL long long

#define S(a) scanf("%d",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define KS printf("Case %d: ",kk++)

#define MOD 1000000007
#define MX 100010


int main()
{
    int tc,kk=1,n,m;
    char s[5][5],sx[5][5],so[5][5];
    string ans;
    READ;
    WRITE;
    cin>>tc;
    while(tc--)
    {
        ans="Draw";
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
            {
                cin>>s[i][j];

                sx[i][j]=so[i][j]='.';
                if(s[i][j]=='T')
                    {
                        sx[i][j]='X';
                        so[i][j]='O';
                    }
                else if(s[i][j]=='X')
                    sx[i][j]='X';
                else if(s[i][j]=='O')
                    so[i][j]='O';

            }
        //cout<<sx[0]<<endl;

        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                if(s[i][j]=='.')
                    ans="Game has not completed";


        for(int i=0;i<4;i++)    //row
            if(sx[i][0]==sx[i][1] && sx[i][0]==sx[i][2] && sx[i][0]==sx[i][3])
                if(sx[i][0]!='.')
                    ans="X won";

        for(int i=0;i<4;i++)    //row
            if(so[i][0]==so[i][1] && so[i][0]==so[i][2] && so[i][0]==so[i][3])
                if(so[i][0]!='.')
                    //cout<<"row";
                    ans="O won";


        for(int i=0;i<4;i++)    //col
            if(sx[0][i]==sx[1][i] && sx[0][i]==sx[2][i] && sx[0][i]==sx[3][i])
                if(sx[0][i]!='.')
                    ans="X won";

        for(int i=0;i<4;i++)    //col
            if(so[0][i]==so[1][i] && so[0][i]==so[2][i] && so[0][i]==so[3][i])
                if(so[0][i]!='.')
                    //cout<<"col"<<" "<<i<<endl;
                    ans="O won";


        if(sx[0][0]==sx[1][1] && sx[0][0]==sx[2][2] && sx[0][0]==sx[3][3]) //upper digonal
            if(sx[0][0]!='.')
                ans="X won";

        if(so[0][0]==so[1][1] && so[0][0]==so[2][2] && so[0][0]==so[3][3]) //upper digonal
            if(so[0][0]!='.')
                //cout<<"UD";
                ans="O won";


        if(sx[0][3]==sx[1][2] && sx[0][3]==sx[2][1] && sx[0][3]==sx[3][0]) //lower digonal
            if(sx[0][3]!='.')
                ans="X won";

        if(so[0][3]==so[1][2] && so[0][3]==so[2][1] && so[0][3]==so[3][0]) //lower digonal
            if(so[0][3]!='.')
                //cout<<"LD";
                ans="O won";


        printf("Case #%d: ",kk++);
        cout<<ans;
        printf("\n");
    }
    return 0;
}

