#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for(int c=0; c<T; c++)
    {
        int D, maxp = 0;
        static int P[1010];
        static int cnt[1010];

        memset(cnt, 0, sizeof(cnt));

        cin >> D;
        for(int i=0; i<D; i++)
        {
            cin >> P[i];
            maxp = max(maxp, P[i]);
            cnt[P[i]]++;
        }

        int minv = 9999;

        for(int i=1; i<=maxp; i++)
        {
            int movs = 0;
            for(int j=i+1; j<=maxp; j++)
            {
                int r = j % i;
                int n = j / i;
                if(r != 0) n++;

                movs += (n-1) * cnt[j];
            }

            minv = min(minv, i + movs);
        }


        printf("Case #%d: %d\n", c+1, minv);
    }

    return 0;
}
