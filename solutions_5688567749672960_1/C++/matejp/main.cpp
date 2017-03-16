#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

int lengthof(long long x)
{
    int length = 0;
    for(; x != 0; x /= 10, length++);
    return length;
}

long long reverse(long long x)
{
    long long y = 0;
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
    long long N;
    ifstream input ("input.in");
    if (input.is_open())
    {
        ofstream output ("output.out");
        input >> T;
        for (int i = 0; i < T; i++)
        {
            long long x, result;
            input >> N;
            x = N;
            int lengthofx = lengthof(x);
            long long thisbase = pow(10, lengthofx - 1);
            long long tenpow = pow(10, lengthofx / 2);
            result = 1;
            while (x != 1)
            {
                if (((x - 1) % tenpow == 0) && (reverse(x) < x))
                {
                    x = reverse(x);
                    result++;
                }
                else
                {
                    if (x == thisbase)
                    {
                        lengthofx--;
                        thisbase /= 10;
                        tenpow = pow(10, lengthofx / 2);
                    }
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

