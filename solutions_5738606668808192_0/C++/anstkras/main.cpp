#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int t;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> t;
    int n, j;
    fin >> n >> j;
    string s = string(n, '0');
    s[n - 1] = '1';
    s[0] = '1';
    fout << "Case #1:\n";
    int res = 3, r;
    for (int i = 0; i < j; i++)
    {
        r = res;
        vector <char> q;
        while (r != 0)
        {
            q.push_back((r % 2) + '0');
            r /= 2;
        }
        int ans[9] = {};
        for (int j = 0; j < q.size(); j++)
        {
            s[j] = q[q.size() - 1 - j];
            s[n - q.size() + j] = q[q.size() - 1 - j];
            for (int d = 0; d < 9; d++)
            {
                ans[d] = ans[d] * (d + 2) + q[q.size() - 1 - j] - '0';
            }
        }

        fout << s << " ";
        for (int j = 0; j < 9; j++)
            fout << ans[j] << " ";
        fout << '\n';
        res += 2;
    }

    return 0;
}

