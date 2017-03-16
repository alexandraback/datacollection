#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<iostream>
#include<cstdlib>
#include<queue>
#include<sstream>
#include<queue>
#include<ctype.h>
#include<cstring>


using namespace std;

#define re return
#define co continue
#define pb push_back
#define br break
#define sz size


#define pf printf
#define sf scanf

int pathCount[55][55];

int main()
{
    //freopen("sample.in","r",stdin);

    freopen("a.in","r",stdin);
    freopen("a.ans","w",stdout);

    int kase=1;
    int t;
    sf("%d",&t);
    while ( t--)
    {
        int j,k,i;
        int n;
        sf("%d",&n);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                pathCount[i][j] = 0;
        for(i=0;i<n;i++)
        {
            int ancestor;
            sf("%d",&ancestor);
            while(ancestor--)
            {
                int id;
                sf("%d",&id);
                pathCount[i][id-1] = 1;
            }
        }
        bool yes=false;
        for(k=0;k<n;k++)
            for(i=0;i<n;i++)
                for(j=0;j<n;j++)
                {
                    pathCount[i][j] += pathCount[i][k]* pathCount[k][j];
                    if ( pathCount[i][j] > 1)
                        yes = true;
                }
        pf("Case #%d: %s\n",kase++, (yes?"Yes":"No"));

    }
    return 0;
}
