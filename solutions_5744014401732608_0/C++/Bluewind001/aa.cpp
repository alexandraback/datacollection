#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<map>
#include<bitset>
#include<sstream>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int T,n,m;
bool g[55][55];

int make1(int t){
    g[1][n]=true;
    t--;
    int now=2;
    while(t>0 && now<n){
        g[1][now]=true;
        g[now][n]=true;
        now++;
        t--;
    }
    return t;
}
int make2(int t){
    if(t==0)
        return t;
    for(int i=2; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            g[i][j]=true;
            t--;
            if(t==0)
                return t;
        }
    }
    return t;
}

int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    cin >> T;
    for(int ii=1; ii<=T; ++ii){
        cin >> n >> m;
        cout << "Case #" << ii<<": ";
        if( pow(2,n-2)<m)
            cout << "IMPOSSIBLE"<<endl;
        else{
            memset(g,false,sizeof(g));
            m = make1(m);
            m = make2(m);
            if(m>0){
                cout << "IMPOSSIBLE" << endl;
            }
            else{
                cout << "POSSIBLE" << endl;
                for(int i=1; i<=n; ++i){
                    for(int j=1; j<=n; ++j)
                        cout << g[i][j];
                    cout << endl;
                }
            }
        }
    }

    return 0;
}
