#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for(int t = 1; t <= T; ++t)
    {
        string C, J;
        cin >> C >> J;

        int ans = 987654321;
        string ansC, ansJ;
        for(int i = 0; i < (int)pow(10, C.size()); ++i)
        for(int j = 0; j < (int)pow(10, C.size()); ++j)
        {
            bool skip = false;
            int ti = i, tj = j;
            for(int k = C.size() - 1; k >= 0; --k)
            {
                if(C[k] != '?' && (ti % 10) != C[k] - '0') skip = true;
                if(J[k] != '?' && (tj % 10) != J[k] - '0') skip = true;
                ti /= 10;
                tj /= 10;
            }

            if(skip) continue;
            if(abs(i - j) < ans)
            {
                ans = abs(i - j);
                ansC = to_string(i);
                ansJ = to_string(j);
            }
        }

        cout << "Case #" << t << ": ";
        for(int i = 0; i < C.size() - ansC.size(); ++i)
            cout << "0";
        cout << ansC << " ";
        for(int i = 0; i < J.size() - ansJ.size(); ++i)
            cout << "0";
        cout << ansJ << endl;

    }

    return 0;

}