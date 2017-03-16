#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>
using namespace std;

const int MAXN = 2000000;

int T;
int N;
int K;
int a[5];
int cnt;
int tmpa[5];
int ans[MAXN][4];

void solve(int idx)
{
    int cnt = 0;
    cout << "Case #" << idx << ": " << a[1]*a[2]*min(a[3],K) << endl;
    for(int k=1;k<=min(a[3],K);k++)
    {
        for(int i=1;i<=a[1];i++)
        {
            for(int j=1;j<=a[2];j++)
            {
                ans[cnt][1] = i;
                ans[cnt][2] = j;
                ans[cnt][3] = (k+a[3]-1+cnt/a[2]+cnt%a[2])%a[3]+1;
                for(int l=1;l<=2;l++)
                    cout << ans[cnt][l] << " ";
                cout << ans[cnt][3] << endl;
                cnt++;
            }
        }
        cnt = 0;
    }

}
int main()
{
//    freopen("in.txt","r",stdin);
    freopen("C-small-attempt3.in","r",stdin);
    freopen("C-small-attempt3-out.txt","w",stdout);

    cin >> T;
    for(int i=1;i<=T;i++)
    {
        for(int j=1;j<=3;j++)
            cin >> a[j];
        cin >> K;
        solve(i);
    }

    return 0;
}
