#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;



int main()
{
    int T;
    cin >> T;

    for(int c=0; c<T; c++)
    {
        int smax;
        string seq;

        cin >> smax >> seq;

        int n = 0;
        int add = 0;
        for(int i=0; i<=smax; i++)
        {
            int num = (int)(seq[i] - '0');
            
            if(i > n)
            {
                add += (i - n);
                n = i;
            }

            n += num;
        }

        printf("Case #%d: %d\n", c+1, add);
    }

    return 0;
}
