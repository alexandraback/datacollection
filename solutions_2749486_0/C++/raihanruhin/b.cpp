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
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)
#define LL long long

#define S(a) scanf("%d",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define KS printf("Case %d: ",kk++)

#define MOD 1000000007
#define MX 100010


int main()
{
    READ;
    WRITE;
    int tc,kk=1,n,m,x,y,cnt;
    cin>>tc;
    while(tc--)
    {
        cin>>x>>y;
        string s="";
        cnt=1;
        int posx=0;
        bool chk=1;
        while(posx!=x)
        {
            if(chk)
            {
                posx+=cnt;
                s+="E";
            }
            else
            {
                posx-=cnt;
                s+="W";
            }
            cnt++;
            chk=1-chk;
        }

        int posy=0;
        if(y!=0)
        {
            if(y>0) chk=1;
            else chk=0;

            while(cnt>abs(y-posy))
            {
                if(y>0)
                {
                    posy-=cnt;
                    s+="S";
                    chk=1;
                }
                else
                {
                    posy+=cnt;
                    s+="N";
                    chk=0;
                }
                cnt++;
            }

            while(posy!=y)
            {
                if(chk)
                {
                    posy+=cnt;
                    s+="N";
                }
                else
                {
                    posy-=cnt;
                    s+="S";
                }
                chk=1-chk;
                cnt++;
            }
        }

        printf("Case #%d: ",kk++);
        cout<<s;
        printf("\n");
    }
    return 0;
}

