#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

bool cmp(const string& s, const string& t)
{
    for(int i = 0; i < s.length(); i++)
    {
        if( s[i] < t[i] )
            return false;
        else if( s[i] > t[i] )
            return true;
    }
    return true;
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("aout.txt","w",stdout);

    int T;
    scanf("%d",&T);

    for(int cases = 1; cases <= T; cases++)
    {
        string str;
        cin >> str;

        string dp;
        dp += str[0];

        for(int i = 1; i < str.length(); i++)
        {
            if( cmp(str[i]+dp, dp+str[i]) )
                dp = str[i]+dp;
            else
                dp = dp+str[i];
        }

        cout << "Case #" << cases << ": " << dp << endl;
    }

    return 0;
}
