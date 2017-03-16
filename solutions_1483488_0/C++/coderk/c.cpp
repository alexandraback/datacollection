#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
using namespace std;

int change[10];

int main()
{
    ifstream fin("c.in", ios::in);
    ofstream fout("c.out", ios::out);
    int Test;
    fin >> Test;
    for (int testcase = 1; testcase <= Test; testcase++)
    {
        int a, b, account, maxBit;
        long long ans = 0;
        fin >> a >> b;
        for (int n = a; n <= b; n++)
        {
            if (n < 10)
                continue;
            account = 0;
            for (maxBit = 1; n % maxBit != n; maxBit *= 10);
            maxBit /= 10;
            for (int i = 1; i < maxBit; i *= 10)
            {
                int temp, t1 = n % (i * 10), t2 = n / (i * 10);
                if (t1 / i == 0)
                    continue;
                temp = t1 * (maxBit / i) + t2;
                if (temp > n && temp <= b)
                    change[++account] = temp;
            }
            for (int i = 1; i <= account; i++)
            {
                bool f = false;
                for (int j = i + 1; !f && j <= account; j++)
                    if (change[i] == change[j])
                        f = true;
                if (!f)
                    ans++;
            }
        }
        fout << "Case #" << testcase << ": " << ans << endl;
    }
    fout.close();
    fin.close();
}
