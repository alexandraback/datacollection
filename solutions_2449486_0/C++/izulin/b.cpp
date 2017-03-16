#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for(int ii=1;ii<=t;ii++)
    {
        int n,m;
        cin >> n >> m;
        int h[n][m];
        vector<int> h1(n);
        vector<int> h2(m);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                cin >> h[i][j];
                h1[i] = max(h1[i],h[i][j]);
                h2[j] = max(h2[j],h[i][j]);
            }
        bool ok = true;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if((h1[i] <= h[i][j]) || (h2[j] <= h[i][j]));
                else
                    ok = false;
        cout << "Case #" << ii << ": " << (ok?"YES":"NO") << endl;

    }
}
