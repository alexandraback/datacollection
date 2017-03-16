#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <queue>
#include <cmath>

using namespace std;

static const string _q = "B";

long pow2(int n)
{
    long ret = 1;

    for (int i = 0; i < n; i++)
    {
        ret *= 2;
    }

    return ret;
}

void solve()
{
    int B;
    long M;

    cin >> B >> M;

    long max_num_paths = pow2(B-2);

    if (M > max_num_paths)
    {
        cout << "IMPOSSIBLE";
        return;
    }

    cout << "POSSIBLE";
    
    vector< vector<int> > Matrix(B);

    for (int i = 0; i < B; i++)
    {
        Matrix[i] = vector<int>(B, 0);
    }

    if (M == max_num_paths)
    {
        for (int i = 0; i < B-1; i++)
        {
            for (int j = i+1; j < B; j++)
            {
                Matrix[i][j] = 1;
            }
        }
    }

    else
    {
        for (int i = 1; i < B-1; i++)
        {
            for (int j = i+1; j < B; j++)
            {
                Matrix[i][j] = 1;
            }
        }

        int current_pow = B-3;

        while (current_pow > 0)
        {
            if (M >= pow2(current_pow))
            {
                M -= pow2(current_pow);
                Matrix[0][B - current_pow -2] = 1;
            }
            current_pow --;
        }

        if (M == 1)
        {
            Matrix[0][B-1] = 1;
        }        
    }

    for (int i = 0; i < B; i++)
    {
        cout << endl;
        for (int j = 0; j < B; j++)
            cout << Matrix[i][j];
    }
}

int main(void)
{
    ifstream in(_q + ".in");
    ofstream out(_q + ".out");
    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());

    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": ";
        solve();
        cout << endl;
    }

    return 0;
}
