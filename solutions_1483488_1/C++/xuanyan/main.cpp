#include <fstream>
#include <iostream>
using namespace std;

int exp10[8] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

int shift(int num, int n)
{
    return (num % 10) * exp10[n - 1] + num / 10;
}

int main()
{
	//ofstream cout("E:/out.txt");
    int T;
    cin >> T;

    for (int cases = 1; cases <= T; ++cases)
    {
        int A, B, size, sum = 0;
        cin >> A >> B;

        for (int i = 1; i < 8; ++i)
        {
            if (exp10[i] > B)
            {
                size = i;
                break;
            }
        }

        bool *visited = new bool[B + 1];

        for (int i = A; i <= B; ++i)
            visited[i] = false;

        for (int n = A; n <= B; ++n)
        {
            if (!visited[n])
            {
            	visited[n] = true;
                int cycle_length = 1;
                int m = n;

                do
                {
                    m = shift(m, size);

                    if (m >= A && m <= B && !visited[m])
                    {
                        visited[m] = true;
                        ++cycle_length;
                    }
                }
                while (m != n);

                sum += cycle_length * (cycle_length - 1) / 2;
            }
        }

        delete[] visited;

        cout << "Case #" << cases << ": " << sum << endl;
    }

    //cout.close();
}
