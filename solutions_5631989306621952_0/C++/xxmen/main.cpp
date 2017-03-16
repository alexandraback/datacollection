#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int t, Case = 0;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        string ans = "";
        int len = (int)s.length();
        for (int i = 0; i < len; i++)
        {
            if (ans + s[i] > s[i] + ans)
                ans += s[i];
            else ans = s[i] + ans;
        }
        cout<<"Case #"<<++Case<<": "<<ans<<endl;
    }
}