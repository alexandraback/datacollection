#include <iostream>
using namespace std;

string solve(int x, int y)
{
    string ans = "";

    if (x > 0)
    {
        for (int i = 0; i < x; ++i)
        {
            ans += "WE";
        }
    }
    else
    {
        for (int i = 0; i < -x; ++i)
        {
            ans += "EW";
        }
    }

    if (y > 0)
    {
        for (int i = 0; i < y; ++i)
        {
            ans += "SN";
        }
    }
    else
    {
        for (int i = 0; i < -y; ++i)
        {
            ans += "NS";
        }
    }

    return ans;
}

int main()
{
    int T;
    cin>>T;

    for (int i = 0; i < T; ++i)
    {
        int x, y;
        cin>>x>>y;

        string result = solve(x, y);
        cout<<"Case #"<<(i + 1)<<": "<<result<<endl;
    }

    return 0;
}
