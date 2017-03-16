#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

long long rev(const long long& a)
{
    long long x = 0;
    long long b = a;
    while (b % 10 == 0)
    {
        b = b / 10;
    }
    while (b > 0)
    {
        x = 10 * x + (b % 10);
        b = b / 10;
    }
    return x;
}

int main()
{
    int t;
    ifstream inf("A-small-attempt0.in");
    ofstream out("test.out");
    inf >> t;
    vector<int> linear(1000002);
    linear[1] = 1;
    for (int i = 2; i < 1000002; ++i)
    {
        int x = rev(i);
        if (x < i && (i % 10 != 0) && linear[x] < linear[i - 1])
        {
            linear[i] = linear[x] + 1;
        } else
        {
            linear[i] = linear[i - 1] + 1;
        }
        if (i < 30)
        {
            //cout << i << "\t" << linear[i] << endl;
        }
    }

    for (int i = 0; i < t; ++i)
    {
        long long n;
        inf >> n;
        long long sol = linear[n];

        cout << "Case #" << i + 1 << ": " << sol << endl;
        out << "Case #" << i + 1 << ": " << sol << endl;
    }
    out.close();
    return 0;
}
