#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin >> s;
        string r;
        r+=s[0];
        for(int j=1;j<s.size();j++)
        {
            if(s[j]<r[0])
                r+=s[j];
            else
            {
                string o;
                o+=s[j];
                r.insert(0,o);
            }
        }
        cout << "Case #" << i << ": " << r << "\n";
    }
    return 0;
}
