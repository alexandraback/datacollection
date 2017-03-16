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

vector<int> x, y, z;
int p;
LL dp[110][2][2][2];

LL go(int cur, bool px, bool py, bool pz)
{
    if (cur>=p) return ((px&py)&pz);
    if (dp[cur][px][py][pz]>=0) return dp[cur][px][py][pz];
    LL ret=0;
    int ez=0;
    if (pz || z[cur]==1) ez=1;
    for (int i=0;i<=ez;i++)
    {
        for (int j=0;j<=1;j++)
            for (int k=0;k<=1;k++)
                if ((j&k)==i)
                {
                    if (j==1 && !px && x[cur]==0) continue;
                    if (k==1 && !py && y[cur]==0) continue;
                    ret+=go(cur+1,(bool)px|(j<x[cur]),(bool)py|(k<y[cur]),(bool)pz|(i<z[cur]));
                }
    }
    return dp[cur][px][py][pz]=ret;
}
int main()
{
    freopen("new_lottery_game.in","r",stdin);
    freopen("new_lottery_game.out","w",stdout);
    int tc, nt=1;
    cin>>tc;
    while (tc--)
    {
        int a, b, k;
        cin>>a>>b>>k;
        x.clear();
        y.clear();
        z.clear();
        while (a>0)
        {
            x.push_back(a%2);
            a/=2;
        }
        while (b>0)
        {
            y.push_back(b%2);
            b/=2;
        }
        while (k>0)
        {
            z.push_back(k%2);
            k/=2;
        }
        p=max(max(x.size(),y.size()),z.size());
        while (x.size()<p) x.push_back(0);
        while (y.size()<p) y.push_back(0);
        while (z.size()<p) z.push_back(0);
        reverse(x.begin(),x.end());
        reverse(y.begin(),y.end());
        reverse(z.begin(),z.end());
/*        for (int i=0;i<p;i++) cout<<x[i]<<" ";cout<<endl;
        for (int i=0;i<p;i++) cout<<y[i]<<" ";cout<<endl;
        for (int i=0;i<p;i++) cout<<z[i]<<" ";cout<<endl;*/
        memset(dp,-1,sizeof(dp));
        cout<<"Case #"<<nt++<<": "<<go(0,0,0,0)<<endl;
    }
}
