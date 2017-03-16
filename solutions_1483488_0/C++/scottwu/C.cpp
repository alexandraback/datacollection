#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int MAXN = 2000100;

ifstream fin ("c.in");
ofstream fout ("c.out");

bool seen[MAXN];

int move (int x, int pow)
{
    return x / 10 + (x % 10) * pow;
}

int main()
{
    int t; fin >> t;
    for (int test = 0; test < t; test++)
    {
        for (int i = 0; i < MAXN; i++)
            seen[i] = false;
        int a, b; fin >> a >> b;
        int ans = 0;
        for (int i = a; i <= b; i++)
        {
            if (seen[i])
                continue;
            int pow = 1;
            while (pow * 10 <= i)
                pow *= 10;
            int val = i;
            int count = 0;
            for (int j = 0; j < 20; j++)
            {
                if (val >= a && val <= b)
                {
                    if (seen[val])
                        break;
                    if (val >= pow)
                    {
                        seen[val] = true;
                        count++;
                    }
                }
                val = move (val, pow);
            }
            ans += count * (count - 1) / 2;
        }
        fout << "Case #" << test + 1 << ": " << ans << "\n";
    }
    return 0;
}
