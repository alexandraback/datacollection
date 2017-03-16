#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for(int t = 1; t <= T; t++)
    {
        long long int N;

        cin >> N;

        if(N == 0)
        {
            printf("Case #%d: INSOMNIA\n", t);
            continue;
        }

        bool seen[10];
        memset(seen, false, sizeof(seen));

        long long int x = 0;
        bool done = false;
        do
        {
            x += N;
            long long int y = x;
            while(y > 9)
            {
                seen[y%10] = true;
                y /= 10;
            }
            seen[y] = true;

            done = true;
            for(int i = 0; i < 10; i++)
                done = done && seen[i];
        }
        while(x > 0 && !done);

        printf("Case #%d: %lld\n", t, x);
    }
}
