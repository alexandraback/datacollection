#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <math.h>
#include <stack>
#include <list>


#define pb push_back
using namespace std;

typedef long long Long;


int grid[107][107];
int n,m;

int main()
{
    //freopen("in.txt","rt",stdin);
    freopen("B.in","rt",stdin);
    freopen("B.out","wt",stdout);
    int tst,cas;
    scanf("%d",&tst);
    for(cas=1;cas<=tst;cas++) {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) scanf("%d",&grid[i][j]);
        }

        bool plx = true;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {

                bool pl = true;
                for(int k=0;k<n;k++) {
                    if(grid[k][j]>grid[i][j]) {
                        pl = false;
                        break;
                    }
                }
                if(pl) continue;

                pl = true;

                for(int k=0;k<m;k++) {
                    if(grid[i][k]>grid[i][j]) {
                        pl = false;
                        break;
                    }
                }

                if(!pl) plx = false;

            }
        }

        if(plx) printf("Case #%d: YES\n",cas);
        else printf("Case #%d: NO\n",cas);
    }
    return 0;
}
