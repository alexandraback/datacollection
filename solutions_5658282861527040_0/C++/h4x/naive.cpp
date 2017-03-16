#include <iostream>
#include <cstring>

using namespace std;


int main()
{
    int T;
    cin >> T;

    for(int c=0; c<T; c++)
    {
        int A, B, K;

        cin >> A >> B >> K;

        int total = 0;
        for(int x=0; x<A; x++)
            for(int y=0; y<B; y++)
                if((x & y) < K)
                    total++;

        int result = total;
        printf("Case #%d: %d\n", c+1, result);
    }

    return 0;
}
