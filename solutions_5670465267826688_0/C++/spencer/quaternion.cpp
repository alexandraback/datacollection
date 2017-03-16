#include <algorithm>
#include <cassert>
#include <cstdio>
#include <string>
using namespace std;

const int MAX = 10001;

struct Quaternion
{
    int sign;
    char letter;
};

bool operator==(const Quaternion& x, const Quaternion& y)
{
    return x.sign == y.sign && x.letter == y.letter;
}

bool operator!=(const Quaternion& x, const Quaternion& y)
{
    return !(x == y);
}

Quaternion operator*(const Quaternion& x, const Quaternion& y)
{
    int sign = x.sign * y.sign;
    if (x.letter == 'e') return Quaternion { sign, y.letter };
    if (y.letter == 'e') return Quaternion { sign, x.letter };

    char xl = x.letter, yl = y.letter;
    if (xl > yl)
    {
        swap(xl, yl);
        sign *= -1;
    }

    if (xl == yl) return Quaternion { -sign, 'e' };
    else if (xl == 'i' && yl == 'j') return Quaternion { sign, 'k' };
    else if (xl == 'j' && yl == 'k') return Quaternion { sign, 'i' };
    else if (xl == 'i' && yl == 'k') return Quaternion { -sign, 'j' };
    else {
        printf("%d %c * %d %c", x.sign, x.letter, y.sign, y.letter);
        assert(false);
    }
}

// Quaternion exponent(Quaternion x, long long power)
// {
//     if (power == 0) return Quaternion { 1, 'e' };
//     if (power == 1) return x;

//     Quaternion y = exponent(x, power / 2);
//     y = y * y;
//     if (power % 2 == 0) return y;
//     else return y * x;
// }

Quaternion exponent(Quaternion x, long long power)
{
    if (x.letter == 'e')
    {
        if (x.sign == 1) return x;
        else
        {
            if (power % 2 == 0) return Quaternion { 1, 'e' };
            else return Quaternion { -1, 'e' };
        }
    }
    else
    {
        if (power % 4 == 0) return Quaternion { 1, 'e' };
        else if (power % 4 == 1) return x;
        else if (power % 4 == 2) return Quaternion { -1, 'e' };
        else return Quaternion { -x.sign, x.letter };
    }
}

Quaternion collapse(string s)
{
    Quaternion x { 1, 'e' };
    for (auto c : s)
        x = x * Quaternion { 1, c };
    return x;
}

bool solve()
{
    int L; long long X; scanf("%d %lld\n", &L, &X);
    char ch[MAX]; scanf("%s", ch);

    if (exponent(collapse(string(ch)), X) != Quaternion { -1, 'e' })
        return false;

    string str;
    for (int i = 1; i <= min(X, 4LL); i++)
        str += string(ch);

    long long first_i = -1;
    Quaternion prefix { 1, 'e' };
    for (int i = 0; i < (int)str.length(); i++)
    {
        prefix = prefix * Quaternion { 1, str[i] };
        if (prefix == Quaternion { 1, 'i' })
        {
            first_i = i;
            break;
        }
    }

    long long last_k = -1;
    reverse(str.begin(), str.end());
    Quaternion suffix = { 1, 'e' };
    for (int i = 0; i < (int)str.length(); i++)
    {
        suffix = Quaternion { 1, str[i] } * suffix;
        if (suffix == Quaternion { 1, 'k'})
        {
            last_k = L * X - 1 - i;
            break;
        }
    }

    if (first_i == -1 || last_k == -1) return false;
    return first_i < last_k;
}

int main()
{
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; t++)
        printf("Case #%d: %s\n", t, solve() ? "YES" : "NO");
    return 0;
}
