#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int T, C, D;
    long long V;
    ifstream input ("input.in");
    if (input.is_open())
    {
        ofstream output ("output.out");
        input >> T;
        for (int i = 0; i < T; i++)
        {
            int result = 0;
            input >> C >> D >> V;
            long long left = 1;
            long long x = 0, sum = 0;
            for (int j = 0; j < D; j++)
            {
                long long z = 0;
                input >> x;
                while (left < x)
                {
                    int y = left;
                    sum += y;
                    left += y;
                    result++;
                }
                sum += x;
                left = sum + 1;
                if (j == D - 1)
                {
                    while (left < V)
                    {
                        int y = left;
                        sum += y;
                        left += y;
                        result++;
                    }
                }
            }
            //cout << "Case #" << i + 1 << ": " << result << endl;
            output << "Case #" << i + 1 << ": " << result << endl;
        }
    input.close();
    output.close();
    }
    return 0;
}

