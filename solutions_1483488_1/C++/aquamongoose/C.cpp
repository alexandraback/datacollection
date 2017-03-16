#include <iostream>
using namespace std;

int solve(int a, int b)
{
    int mult = 1, temp = a;
    int ret = 0;
    while (temp)
    {
        mult *= 10;
        temp /= 10;
    }
    mult /= 10;

    for (int i=a; i<=b; i++)
    {
        int j = i/10 + (i%10)*mult;

        while (i != j)
        {
            if (j > i && j <= b) ret++;
            j = j/10 + (j%10)*mult;
        }
    }

    return ret;
}

int main()
{
    int t; cin >> t;

    for (int kase=1; kase<=t; kase++)
    {
        cout << "Case #" << kase << ": ";
        int a,b;
        cin >> a >> b;
        cout << solve(a,b) << endl;
    }
    return 0;
}
