#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

#define pb push_back
#define mp make_pair
typedef pair<int, int> ii;
typedef vector<int> vi;

int main()
{
   // freopen("sb4.in","r",stdin);
   // freopen("sb4.out","w",stdout);
    int t,x=0;
    cin>>t;
    while(t--)
    {
        x++;
        int n,m;
        cin>>n>>m;
        vector<vector<int> >v(n);
        vector<int>row(n,1000000),col(m,1000000);
        for(int i=0;i<n;i++)
        {
            v[i].resize(m);
            for(int j=0;j<m;j++)
                cin>>v[i][j];
        }
        for(int i=0;i<n;i++)
        {
            int high=0;
            for(int j=0;j<m;j++) high=max(high,v[i][j]);
            row[i]=high;
            for(int j=0;j<m;j++)
                if(v[i][j]!=high)
                {
                    col[j]=min(col[j],v[i][j]);
                }
          //  cout<<row[i]<<" "<<i<<"\n";
        }
        vector<vector<int> >b(n);
        for(int i=0;i<n;i++)
        {
            b[i].resize(m,1000000);
            for(int j=0;j<m;j++)
                b[i][j]=min(b[i][j],min(row[i],col[j]));
        }
        if(b==v)
        cout<<"Case #"<<x<<": "<<"YES"<<"\n";
        else cout<<"Case #"<<x<<": "<<"NO"<<"\n";
    }
    return 0;
}
