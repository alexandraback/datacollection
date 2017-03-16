#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int lengthof(long x)
{
    int lengthCount = 0;
    for(; x != 0; x /= 10, lengthCount++);
    return lengthCount;
}

long reverse(long x)
{
    long y = 0;
    while(x != 0)
    {
       y = y * 10;
       y = y + x % 10;
       x = x/10;
    }
    return y;
}

int main()
{
    int T;
    long N;
    ifstream input ("input.in");
    if (input.is_open())
    {
        ofstream output ("output.out");
        input >> T;
        for (int i = 0; i < T; i++)
        {
            long x, result;
            input >> N;
            x = N;
            result = 1;
            while (x != 1)
            {
                if ((reverse(x) < x) && ((x - 1) % (long)pow(10, lengthof(x) / 2) == 0))
                {
                    x = reverse(x);
                    result++;
                }
                else
                {
                    x--;
                    result++;
                }
            }
            output << "Case #" << i + 1 << ": " << result << endl;
        }
    input.close();
    output.close();
    }
    return 0;
}

