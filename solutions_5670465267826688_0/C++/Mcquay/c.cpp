#include <fstream>
#include <algorithm>
#include <math.h>

int c2i(char a)
{
    return a - 'i' + 2;
}

int sign(int a)
{
    return a > 0 ? 1 : (a < 0 ? -1 : 0);
}

int mul(int a, int b)
{
    // 1 i j k
    // 1 2 3 4
    int v[4][4] = {{1, 2, 3, 4},
              {2, -1, 4, -3},
              {3, -4, -1, 2},
              {4, 3, -2, -1}};

    return v[abs(a) - 1][abs(b) - 1] * sign(a) * sign(b);
}

int pw(int r, int p)
{
    int res = 1;
    while (p)
    {
        if (p % 2)
            res = mul(res, r);

        r = mul(r, r);
        p /= 2;
    }

    return res;
}

bool process2(std::string const & s, size_t c)
{
    int r = 1;
    for (char c: s)
    {
        r = mul(r, c2i(c));
    }

    r = pw(r, c);

    if (r != -1)
        return false;

    size_t p = 0;
    for (int val = 2; val != 4; ++val)
    {
        int pr = 1;
        for (; (p != s.length() * std::min(c, 8UL)) && (pr != val); ++p)
        {
            pr = mul(pr, c2i(s[p % s.length()]));
        }

        if (pr != val)
            return false;
    }

    return true;
}

bool process(std::string const & s, size_t c)
{
    size_t len = s.length() * c;
    size_t idx = 0;

    for (size_t r = 2; r != 4; ++r)
    {
        int val = 1;
        for (; idx < len && val != r; ++idx)
            val = mul(val, c2i(s[idx % s.length()]));
    }

    int val = 1;
    for (; idx < len; ++idx)
        val = mul(val, c2i(s[idx % s.length()]));

    return val == 4;
}

int main(int argc, char * argv[])
{
    std::ifstream in("in_c.txt");
    std::ofstream out("out_c.txt");

    size_t T;
    in >> T;
    for (int i = 0; i != T; ++i)
    {
        size_t L, X;
        std::string s;

        in >> L >> X >> s;

//        if (process(s, X) != process2(s, X))
//        {
//            process(s, X);
//            process2(s, X);
//        }

        out << "Case #" << i + 1 << ": " << (process2(s, X) ? "YES" : "NO") << std::endl;
    }
}
