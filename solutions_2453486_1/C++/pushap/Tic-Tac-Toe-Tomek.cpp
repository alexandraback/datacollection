#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#define ALL(i,n)    for(i = 0; i < (n); i++)
#define FOR(i,a,b)  for(i = (a); i < (b); i++)
#define SET(p)      memset(p,-1,sizeof(p))
#define CLR(p)      memset(p,0,sizeof(p))
#define MIn(a,b) a>b?b:a
#define MAx(a,b) a>b?a:b
//#define FOR(i,n) for(i=1;i<=n;i++)
#define S(n) scanf("%d",&n)
#define P(n) printf("%d",n)
#define sl(n) scanf("%lld",&n)
#define mod 1000000007
#define ull unsigned long long
using namespace std;
char a[6][6];
int main()
{
    int t,i,x,o,flag,count=0,ans,j;
    freopen("A-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    S(t);
    while(t--)
    {
        //getchar();

        for(i=0; i<4; i++)
        {
            cin>>a[i];
        }
        flag=0;
        ans=0;
        for(i=0; i<4; i++)
        {
            x=0;
            o=0;
            for(j=0; j<4; j++)
            {
                if(a[i][j]=='T')
                {
                    x++;
                    o++;
                }
                else if(a[i][j]=='O')
                {
                    o++;
                }
                else if(a[i][j]=='X')
                {
                    x++;
                }
                else
                {
                    flag=1;
                    break;
                }
            }
            if(x==4)
            {
                printf("Case #%d: X won\n",++count);
                ans=1;
                break;
            }
            else if(o==4)
            {
                printf("Case #%d: O won\n",++count);
                ans=1;
                break;
            }
        }
        ///////////////////
        if(ans==0)
        {
            for(j=0; j<4; j++)
            {
                x=0;
                o=0;
                for(i=0; i<4; i++)
                {
                    if(a[i][j]=='T')
                    {
                        x++;
                        o++;
                    }
                    else if(a[i][j]=='O')
                    {
                        o++;
                    }
                    else if(a[i][j]=='X')
                    {
                        x++;
                    }
                    else
                    {
                        flag=1;
                        break;
                    }
                }
                if(x==4)
                {
                    printf("Case #%d: X won\n",++count);
                    ans=1;
                    break;
                }
                else if(o==4)
                {
                    printf("Case #%d: O won\n",++count);
                    ans=1;
                    break;
                }
            }

        }
        // cout<<ans<<endl;
        if(ans==0)//diagnol
        {
                o=0;
                x=0;
            for(i=0; i<4; i++)
            {

               //cout<<x<<" "<<o<<endl;
                if(a[i][i]=='T')
                {
                    o++;
                    x++;
                }
                else if(a[i][i]=='X')
                {

                    x++;
                }
                else if(a[i][i]=='O')
                {
                    o++;
                }
                else
                {
                    flag=1;
                    break;
                }
            }

            if(x==4)
            {
                printf("Case #%d: X won\n",++count);
                ans=1;
                //break;
            }
            else if(o==4)
            {
                printf("Case #%d: O won\n",++count);
                ans=1;
                //break;
            }


        }

        if(ans==0)
        {
                o=0;
                x=0;
            for(j=3,i=0; i<4; j--,i++)
            {

                if(a[i][j]=='T')
                {
                    o++;
                    x++;
                }
                else if(a[i][j]=='X')
                {

                    x++;
                }
                else if(a[i][j]=='O')
                {
                    o++;
                }
                else
                {
                    flag=1;
                    break;
                }
            }
            if(x==4)
            {
                printf("Case #%d: X won\n",++count);
                ans=1;
                //break;
            }
            else if(o==4)
            {
                printf("Case #%d: O won\n",++count);
                ans=1;
                //break;
            }

     }
     if(ans==0&&flag==1)
     {
         printf("Case #%d: Game has not completed\n",++count);
     }
     else if(ans==0&&flag==0)
     {
         printf("Case #%d: Draw\n",++count);
     }

    }
    return 0;
}
