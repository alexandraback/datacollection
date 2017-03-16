#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
typedef unsigned long long ull;

int main()
{
    errno_t err;
    FILE* fin = nullptr;
    err = freopen_s(&fin, "B-large.in", "r", stdin);
    if (err != 0)
        fprintf(stdout, "error on freopen\n");

    FILE* fout = nullptr;
    err = freopen_s(&fout, "output.out", "w", stdout);
    if (err != 0)
        fprintf(stdout, "error on freopen\n");

    int T = 0;
    cin >> T;

    for (size_t i = 1; i <= T; ++i)
    {
        long n = 0;
        cin >> n;
        vector<vector<int>>gird;
        vector<int> result;
        vector<int> nodes;
        unordered_map<int, int> map;
        for (int j = 0; j < 2*n-1; j++)
        {
            for (int k = 0; k < n; k++)
            {
                int r = 0;
                cin >> r;
                if (map.find(r) == map.end())
                {
                    nodes.push_back(r);
                    map[r] = 1;
                }
                else
                {
                    ++map[r];
                }
            }
        }

        for (int node : nodes)
        {
            if (map[node] % 2 == 1)
            {
                result.push_back(node);
            }
        }

        std::sort(result.begin(), result.end());
        string rrr = "";
        for (int r: result)
        {
            if (!rrr.empty())
            {
                rrr.push_back(' ');
            }
            rrr.append(to_string(r));
        }

        cout << "Case #" << i << ": ";
        cout << rrr << endl;
    }


}
