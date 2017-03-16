#include <iostream>
#include<cstdio>

using namespace std;

int main()
{
    //freopen("1.in", "rt", stdin);
    //freopen("1.out", "wt", stdout);
    long testCases, R, C, W, Result;

    cin >> testCases;
    for(int i=1; i<=testCases; i++)
    {
        cin >> C >> R >> W;

        int j = R;
        while(j % W != 0)
        {
            j++;
        }

        Result = (((j/W) + W - 1) + ((C-1) * (R/W)));

        cout << "Case #" << i << ": " << Result << endl;
    }
    return 0;
}
