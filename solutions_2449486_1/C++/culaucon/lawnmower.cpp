#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <fstream>
#include <cstring>

using namespace std;
typedef long long LL;

int n, m;
int a[110][110];
int row[110], col[110];

int main()
{
    freopen("lawnmower.in","r",stdin);
    freopen("lawnmower.out","w",stdout);
    int nt, tt=1;
    cin>>nt;
    while (nt--)
    {
        memset(row,-1,sizeof(row));
        memset(col,-1,sizeof(col));
        cin>>n>>m;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
            {
                cin>>a[i][j];
                row[i]=max(row[i],a[i][j]);
                col[j]=max(col[j],a[i][j]);
            }
        bool can=1;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                if (a[i][j]!=row[i] && a[i][j]!=col[j]) can=0;
        cout<<"Case #"<<tt++<<": "<<(can?"YES":"NO")<<endl;
    }
}
