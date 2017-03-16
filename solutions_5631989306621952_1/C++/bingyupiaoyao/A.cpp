#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
    errno_t err;
    FILE* fin = nullptr;
    err = freopen_s(&fin, "A-large.in", "r", stdin);
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
        string str = "";
        cin >> str;
        int n = str.size();
        string result = "";
        char first = 'A';
        char last = 'A';
        for (int j = 0; j < n; j++)
        {
            if (result.empty())
            {
                result.push_back(str[j]);
                first = str[j];
                last = str[j];
                continue;
            }

            if (first <= str[j])
            {
                result.insert(result.begin(), str[j]);
                first = str[j];
            }
            else
            {
                result.push_back(str[j]);
                last = str[j];
            }

        }
        cout << "Case #" << i << ": ";
        cout << result << endl;
    }


}
