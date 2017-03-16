#include <iostream>
#include <string>

using namespace std;

int get(const string &cnts, int ind)
{
    return cnts[ind] - '0';
}

void solve(const int t)
{
    int S;
    string counts;
    cin >> S >> counts;
    for(int r = 0; r < 2 * S + 10; ++r)
    {
        int cur = r + get(counts, 0);
        bool flag = true;
        for(int i = 1; i <= S; ++i)
        {
            if(cur < i)
            {
                flag = false;
                break;
            }
            else
            {
                cur += get(counts, i);
            }
        }
        if(flag)
        {
            cout << "Case #" << t << ": " << r << "\n";
            return;
        }
    }
}

int main()
{
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i)
    {
        cerr << "Solving #" << i + 1 << "\n";
        solve(i + 1);
    }
    return 0;
}
