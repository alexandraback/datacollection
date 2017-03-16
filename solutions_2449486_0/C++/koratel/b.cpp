#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define x first
#define y second

const int INF = 1 << 30;
const double EPS = 1e-13;

int p[100][100];

int main()
{
    ios_base::sync_with_stdio(0);
    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        int n, m;
        cin>>n>>m;
        for(int i=0; i<n; i++)
        {
            for(int j=0;j<m; j++) cin>>p[i][j];
        }
        // heura (nm)*(n+m) xD
        int ans=1;
        for(int i=0; i<n; i++)
        {
            for(int j=0;j<m; j++)
            {
                int pion=0, poziom=0;
                for(int k=0; k<n; k++)
                {
                    if(p[i][j]<p[k][j]) pion=1;
                }
                for(int k=0; k<m; k++)
                {
                    if(p[i][j]<p[i][k]) poziom=1;
                }
                if(pion&&poziom) ans=0;
            }
        }
        cout<<"Case #"<<t<<": ";
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
