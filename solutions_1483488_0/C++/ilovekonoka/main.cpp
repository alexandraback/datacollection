#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

int T;
int A, B;

using namespace std;

int pow10[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000 };

int main()
{
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        cin >> A >> B;
        int numDigits = 0;
        int a = A;
        while (a > 0)
        {
            a /= 10;
            ++numDigits;
        }
        int total = 0;
        for (int num = A; num <= B; ++num)
        {
            vector<int> history;
            history.reserve(10);
            for (int d = 1; d < numDigits; ++d)
            {
                int firstPart = num / pow10[d];
                int secondPart = num % pow10[d];
                int num2 = secondPart * pow10[numDigits - d] + firstPart;
                if (num2 >= A && num2 <= B && num2 > num && find(begin(history), end(history), num2) == end(history))
                {
                    ++total;
                    history.push_back(num2);
                }
            }
        }
        cout << "Case #" << t + 1 << ": " << total << endl;
    }
}