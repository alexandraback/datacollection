#include <bits/stdc++.h>
using namespace std;

int solve(string s)
{
    int n=s.size();

    int result=0;

    int flipped=0;
    for(int i=n-1; i>=0; i--)
    {
        int curr=s[i]=='-'?1:0;
        int comb=curr^flipped;

        if(comb==1)
        {
            flipped^=1;
            result++;
        }
    }

    return result;
}

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    for(int t=1; t<=T; t++)
    {
        string s;
        cin >> s;
        cout << "Case #" << t << ": " << solve(s) << endl;
    }
    return 0;
}
