/// ///////////////////// ///
///                       ///
///      Silver Rain      ///
///                       ///
///         JU            ///
///                       ///
/// ///////////////////// ///

#include<iostream>
#include<sstream>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstdlib>
#include<cctype>
#define S(a) scanf("%d",&a)
#define PCASE() printf("Case #%d: ",kk++)

using namespace std;

int mat[15][15],n,m;

int main()
{
    int i,j,k,kk,T;
    kk=1;
    bool f,f1;
    freopen("cin.txt","r",stdin);
    freopen("cout.txt","w",stdout);
    S(T);
    while(T--)
    {
        S(n);S(m);
        for(i=1;i<=n;i++)for(j=1;j<=m;j++)S(mat[i][j]);

        f=1;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                f1=1;
                for(k=1;k<=n;k++)if(mat[k][j]>mat[i][j]){f1=0;break;}
                if(f1==0)
                {
                    f1=1;
                    for(k=1;k<=m;k++)if(mat[i][k]>mat[i][j]){f1=0;break;}
                }
                if(f1==0){f=0;break;}
            }
            if(!f)break;
        }
        PCASE();
        if(f)puts("YES");
        else puts("NO");
    }

    return 0;
}
