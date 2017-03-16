#include<iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int ii = 0; ii < t; ii++)
    {
        int a,b,k;
        int ans = 0;
        cin >> a >> b >> k;
        for (int i = 0; i < a; i++)
            for (int j = 0; j < b; j++)
                if ((i & j) < k)
                    ans++;
        cout << "Case #" << ii + 1 << ": " << ans << endl;
    }

    return 0;
}
