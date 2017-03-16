#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <queue>#include <cstdio>
using namespace std;int f[50][50];
int v[50];
int e,r,n;
int main () {    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    for (int cas=1;cas<=T;++cas) {            cin>>e>>r>>n;
            r = min(r,e);
            for (int i=1;i<=n;++i) cin>>v[i];
            v[n+1] = 0;
            for (int i=0;i<=n;++i)
                for (int j=0;j<=e;++j)
                    f[i][j] = -1000000;

            f[0][e] = 0;
            for (int i=0;i<=n;++i)
                for (int j=0;j<=e;++j) {

                    for (int k=0;k<=j;++k) {
                        int u;
                        if (k==0)
                            u = j;
                        else
                            u = min(e,j-k+r);
                        f[i+1][u] = max(f[i+1][u],f[i][j]+k*v[i+1]);

                    }
                }
        //    cout<<f[2][0];
     //       cout<<f[3][0];



            cout<<"Case #"<<cas<<": ";
            int res = -1;
            for (int i=0;i<=e;++i)
                res = max(res, f[n+1][i]);
            cout<<res<<endl;    }
    return 0;
}
