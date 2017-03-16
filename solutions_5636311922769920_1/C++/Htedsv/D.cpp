#include <iostream>
using namespace std;
typedef long long LL;
int main()
{
    int T;
    cin >> T;
    int c, k, s;
    for (int I = 1; I <= T; ++I)
    {
        cin >> k >> c >> s;
        int n = (k-1) / c + 1;
        if (n > s)
            cout << "Case #" << I << ": IMPOSSIBLE" << endl; 
        else
        {
            cout << "Case #" << I << ":"; 
            int cur = 0;
            for (int i = 0; i < n; ++i)
            {
                LL pos = 0;
                for (int j = cur; j < cur + c && j < k; ++j)
                    pos = pos * k + j;
                cout << " " << pos+1;
                cur += c;
            }
            cout << endl;
        }
    }
}
