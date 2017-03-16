#include <iostream>
using namespace std;

int main()
{
    int t;  // Number of Test Cases
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n; // Number of Googlers
        int s; // Number of Surprising Triplets
        int p;
        int result = 0;

        cin >> n;
        cin >> s;
        cin >> p;

        for(int j = 0; j < n; j++)
        {
            int total, best;
            cin >> total;
            best = total / 3;
            if ((total % 3) > 0) best = best + 1;
            if (best >= p)
            {
                result = result + 1;
            }
            else
            {
                if (((best + 1) >= p) && (s > 0) && (total > 1) && (total % 3 != 1))
                {
                    result = result + 1;
                    s = s - 1;
                }
            }
        }

        cout << "Case #" << i + 1 << ": " << result << endl;
    }

    return 0;
}
