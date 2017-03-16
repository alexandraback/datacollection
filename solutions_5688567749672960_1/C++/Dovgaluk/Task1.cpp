#include <iostream>
#include <string>

// start is always 100...000
long long count(long long start, long long finish)
{
    long long f[20];
    int len = 0;
    while (finish)
    {
        f[len] = finish % 10;
        ++len;
        finish /= 10;
    }
    if (len == 1)
        return f[0] - 1;
    long long fl = 0;
    long long fh = 0;
    for (int i = (len + 1) / 2 - 1 ; i >= 0 ; --i)
        fl = fl * 10 + f[i];
    for (int i = (len + 1) / 2 ; i < len ; ++i)
        fh = fh * 10 + f[i];
    if (fh == 1)
        return fl;
    if (fl == 0)
    {
        bool first = true;
        fh = 0;
        long long fh1 = 0;
        for (int i = len / 2 ; i < len ; ++i)
        {
            if (first && !f[i])
                f[i] = 9;
            else if (first)
            {
                --f[i];
                first = false;
            }
            fh = fh * 10 + f[i];
            if (len % 2 == 0 || i != len / 2)
                fh1 = fh1 * 10 + f[i];
        }
        int swap = 1;
        if (fh1 == 1)
            swap = 0;
        fl = 9;
        for (int i = 1 ; i < len / 2 ; ++i)
            fl = fl * 10 + 9;
        return fh + swap + fl;
    }
    return fl + 1 + (fh - 1);
}

int main()
{
    int T;
    std::cin >> T;
    for (int t = 1 ; t <= T ; ++t)
    {
        long long n;
        std::cin >> n;
        long long s = 1;
        long long res = 1;
        while (s < n)
        {
            long long next = s * 10 - 1;
            if (next >= n)
            {
                // finish
                res += count(s, n);
                s = n;
            }
            else
            {
                res += count(s, next);
                s = next;
                ++s;
                ++res;
            }
        }
        std::cout << "Case #" << t << ": ";
        std::cout << res;
        std::cout << "\n";
    }
    return 0;
}

