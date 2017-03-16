#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int c, d, v;
char arr[31];

int check(int exist)
{


    for(int i = 0; i <= v; i++)
        if(!arr[i])
            return false;

    return true;
}

int curr = 1;

int go(int i)
{
    if(i == v + 1)
    {
        if(check(curr))
            return 0;
        else
            return INT_MAX / 2;
    }

    int mask = 1 << i;

    int ans = INT_MAX;
    if(curr & mask || arr[i])
         ans = min(ans, go(i + 1));



    if(!(curr & mask))
    {
        curr |= mask;

        vector<int> s;

        for(int j = v; j >= i; j--)
            if(arr[j - i] && !arr[j])
            {
                s.push_back(j);
                arr[j] = true;
            }

        ans = min(ans, go(i + 1) + 1);
        curr ^= mask;

        for(int j : s)
            arr[j] = false;
    }

    return ans;
}

void solve()
{
    cin >> c >> d >> v;

    for(int i = 0; i < d; i++)
    {
        int a;
        cin >> a;

        int mask = 1 << a;

        curr |= mask;
    }

    for(int i = 0; i <= v; i++)
        arr[i] = false;

    arr[0] = true;

    for(int i = 0; i <= v; i++)
    {
        int mask = 1 << i;

        if(curr & mask)
        {
            for(int j = v; j >= i; j--)
                if(arr[j - i])
                    arr[j] = true;
        }
    }

    cout << go(0);
}

int main()
{
    int t;
    cin >> t;

    for(int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
}
