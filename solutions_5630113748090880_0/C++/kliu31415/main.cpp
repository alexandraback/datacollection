#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    for(int q=1;q<=t;q++)
    {
        int n;
        cin >> n;
        vector<int> x[100];
        int o[2600]{};
        for(int i=0;i<2*n-1;i++)
        {
            for(int j=0;j<n;j++)
            {
                int a;
                cin >> a;
                x[i].push_back(a);
                o[a]++;
            }
        }
        vector<int> b;
        for(int i=0;i<2600;i++)
            if(o[i]%2==1)
                b.push_back(i);
        sort(b.begin(),b.end());
        cout << "Case #" << q << ": ";
        for(auto &i:b)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
