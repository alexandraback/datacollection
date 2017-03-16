//created by shikhar vishnoi

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <string.h>
#include <math.h>
#define ll long long
#define pb push_back
#define iosync ios_base::sync_with_stdio(false);cin.tie(0);
const ll mod=1000000007;
const double pi=3.14159265358979323846;
using namespace std;

int main ()
{
    
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    iosync
    ll t;
    cin>>t;
    for (int T = 1; T <= t; ++T)
    {
        ll b,m;
        cin>>b>>m;
        cout<<"Case #"<<T<<": ";
        if(m<=(1<<(b-2)))
            cout<<"POSSIBLE"<<endl;
        else
        {
            cout<<"IMPOSSIBLE"<<endl;continue;
        }
        ll build[b][b];
        memset(build,0,sizeof(build));
        for (int i = 1; i < b-1; ++i)
        {
            for (int j = i+1; j < b; ++j)
            {
                build[i][j]=1;
            }
        }
        for (int mask = 0; mask < b-2; ++mask)
        {
            if(m & (1<<mask))
                build[0][b-2-mask]=1;
        }
        if(m==(1<<(b-2)))
        {
            for (int i = 0; i < b-1; ++i)
                {
                    for (int j = i+1; j < b; ++j)
                    {
                        build[i][j]=1;
                    }
                }
        }
        for (int i = 0; i < b; ++i)
        {
            for (int j = 0; j < b; ++j)
            {
                cout<<build[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}