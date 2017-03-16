#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

#define MAX 100
int grid[MAX][MAX];
int mxc[MAX], mxr[MAX];
int n,m;

bool calc()
{
    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
            if(grid[i][j] < mxc[j] && grid[i][j] < mxr[i])
                return false;
    return true;
}

int main()
{
//    freopen("../lab_algorithms/dummy.txt","r",stdin);
    freopen("../lab_algorithms/B-large.in","r",stdin);
    freopen("../lab_algorithms/B-large.out","wt",stdout);


    int tc;
    cin >> tc;
    for(int tt=1; tt<=tc; tt++)
    {
        memset(mxc,0,sizeof(mxc));
        memset(mxr,0,sizeof(mxr));
        cin >> n >> m;
        for(int i=0; i < n; i++)
        {
            for(int j=0; j < m; j++)
            {
                cin >> grid[i][j];
                mxr[i] = max(mxr[i],grid[i][j]);
                mxc[j] = max(mxc[j],grid[i][j]);
            }
        }

        if(calc())
            cout << "Case #" << tt << ": " << "YES" << endl;
        else
            cout << "Case #" << tt << ": " << "NO" << endl;
    }

    return 0;
}
