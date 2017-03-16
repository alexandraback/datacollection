#include <iostream>
#include <string>

int T;
int S; // number of surprising
int p; // the score
int N; // number of people

int scores[110];

using namespace std;

int main()
{
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        cin >> N >> S >> p;
        for (int n = 0; n < N; ++n)
        {
            cin >> scores[n];
        }
        int a = 3 * p - 3;
        int b = 3 * p - 4;
        int total = 0;
        for (int n = 0; n < N; ++n)
        {
            if (scores[n] > a)
                ++total;
            else if (scores[n] < b || scores[n] < p)
                continue;
            else if (S-- > 0)
                ++total;
        }
        cout << "Case #" << t + 1 << ": " << total << endl;
    }
}