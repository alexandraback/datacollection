#include <stdio.h>
using namespace std;
int a[6][6],n;
int main()
{
    char x;
    freopen("sergiu.in","r",stdin);
    freopen("sergiu.out","w",stdout);
    scanf("%d ",&n);
    bool castigatx;
    bool castigato;
    bool necompletat;
    bool gasit;
    for(int k=1; k<=n; ++k)
    {
        castigatx=true;
        castigato=true;
        necompletat=false;
        gasit=false;
        for(int i=1; i<=4; ++i)
        {
            for(int j=1; j<=4; ++j)
            {
                if(j==4)scanf("%c ",&x);
                else scanf("%c",&x);
                if(x=='X')a[i][j]=1;
                else if(x=='O')a[i][j]=2;
                else if(x=='T')a[i][j]=3;
                else a[i][j]=0;
            }
        }
        for(int i=1; i<=4; ++i)
        {
            castigatx=true;
            castigato=true;
            for(int j=1; j<=4; ++j)
            {
                if(a[i][j]==0)necompletat=true;
                if(a[i][j]!=1&&a[i][j]!=3)castigatx=false;
                if(a[i][j]!=2&&a[i][j]!=3)castigato=false;
                if(!castigato&&necompletat&&!castigatx)break;
            }
            if(castigato)
            {
                printf("Case #%d: O won\n",k);
                gasit=true;
                break;
            }
            else if(castigatx)
            {
                printf("Case #%d: X won\n",k);
                gasit=true;
                break;
            }
        }
        if(!gasit)
            for(int i=1; i<=4; ++i)
            {
                castigatx=true;
                castigato=true;
                for(int j=1; j<=4; ++j)
                {
                    if(a[j][i]==0)necompletat=true;
                    if(a[j][i]!=1&&a[j][i]!=3)castigatx=false;
                    if(a[j][i]!=2&&a[j][i]!=3)castigato=false;
                    if(!castigato&&necompletat&&!castigatx)break;
                }
                if(castigato)
                {
                    printf("Case #%d: O won\n",k);
                    gasit=true;
                    break;
                }
                else if(castigatx)
                {
                    printf("Case #%d: X won\n",k);
                    gasit=true;
                    break;
                }
            }
        if(!gasit)
        {
            castigatx=true;
            castigato=true;
            for(int i=1; i<=4; ++i)
            {
                if(a[i][i]==0)necompletat=true;
                if(a[i][i]!=1&&a[i][i]!=3)castigatx=false;
                if(a[i][i]!=2&&a[i][i]!=3)castigato=false;
                if(!castigato&&necompletat&&!castigatx)break;
            }
            if(castigato)
            {
                printf("Case #%d: O won\n",k);
                gasit=true;
            }
            else if(castigatx)
            {
                printf("Case #%d: X won\n",k);
                gasit=true;
            }
        }
        if(!gasit)
        {
            castigatx=true;
            castigato=true;
            for(int i=1; i<=4; ++i)
            {
                if(a[i][4-i+1]==0)necompletat=true;
                if(a[i][4-i+1]!=1&&a[i][4-i+1]!=3)castigatx=false;
                if(a[i][4-i+1]!=2&&a[i][4-i+1]!=3)castigato=false;
                if(!castigato&&necompletat&&!castigatx)break;
            }
        }
        if(!gasit)
        {
            if(castigato)
            {
                printf("Case #%d: O won\n",k);
            }
            else if(castigatx)
            {
                printf("Case #%d: X won\n",k);
            }
            else if(!necompletat&&!castigato&&!castigatx)
            {
                printf("Case #%d: Draw\n",k);
            }
            else if(necompletat&&!castigato&&!castigatx)
            {
                printf("Case #%d: Game has not completed\n",k);
            }
        }
    }
    return 0;
}
