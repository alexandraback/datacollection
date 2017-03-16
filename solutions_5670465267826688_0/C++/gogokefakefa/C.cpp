#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>

class Quaternion
{
    enum QuaternionValue { one = '1', i = 'i', j = 'j', k = 'k' };
    QuaternionValue val;
    int sign;

    public:
    Quaternion()
    {
        val = one;
        sign = 1;
    }
    Quaternion(char str)
    {
        val = static_cast<QuaternionValue>(str);
        sign = 1;
    }
    Quaternion(QuaternionValue val, int sign)
    {
        this->sign = sign;
        this->val = val;
    }

    Quaternion operator*(Quaternion x)
    {
        return getValue(*this, x);
    }

    Quaternion operator/(Quaternion x)
    {
        for (int resSign = -1; resSign <= 1; resSign += 2)
        {
            Quaternion res;
            res.sign = sign;

            res.val = QuaternionValue::one;
            if ((res * x) == *this) { return res; }

            res.val = QuaternionValue::i;
            if ((res * x) == *this) { return res; }

            res.val = QuaternionValue::j;
            if ((res * x) == *this) { return res; }

            res.val = QuaternionValue::k;
            if ((res * x) == *this) { return res; }
        }

        assert(false);
    }

    bool operator==(Quaternion x)
    {
        return x.val == val && x.sign == sign;
    } 

    std::string toStr()
    {
        std::string res;
        assert(sign == 1 || sign == -1);
        if (sign == -1)
        {
            res += '-';
        }

        res += static_cast<char>(val);
        return res;
    }
    
    private:
    Quaternion getValue(Quaternion x, Quaternion y)
    {
        if (x.val == y.val)
        {
            return Quaternion(QuaternionValue::one, -1 * x.sign * y.sign);
        }
        if (x.val == QuaternionValue::one)
        {
            return Quaternion(y.val, x.sign * y.sign);
        }
        if (y.val == QuaternionValue::one)
        {
            return Quaternion(x.val, x.sign * y.sign);
        }
        if (x.val == QuaternionValue::i && y.val == QuaternionValue::j)
        {
            return Quaternion(QuaternionValue::k, x.sign * y.sign);
        }
        if (x.val == QuaternionValue::j && y.val == QuaternionValue::k)
        {
            return Quaternion(QuaternionValue::i, x.sign * y.sign);
        }
        if (x.val == QuaternionValue::k && y.val == QuaternionValue::i)
        {
            return Quaternion(QuaternionValue::j, x.sign * y.sign);
        }
        Quaternion res = getValue(y, x);
        res.sign *= -1;
        return res;
    }

};

Quaternion q[1 << 20];
Quaternion prod[1 << 20];

void init(int L, int X, char a[])
{
    int N = L * X;

    prod[N - 1] = q[N - 1] = Quaternion(a[(N - 1) % L]);
    for (int i = N - 2; i >= 0; --i)
    {
        q[i] = Quaternion(a[i % L]);
        prod[i] = q[i] * prod[i + 1];
    }

    
 /*   for (int i = 0; i < N; ++i)
        printf("%s ", prod[i].toStr().c_str());
    
    printf("\n");
*/
    
}

const char* goSlow(int L, int X, char a[])
{
    int N = L * X;
    init(L, X, a);
    Quaternion first('1');
    for (int i = 1; i < N - 1; ++i)
    {
        first = first * q[i - 1];
        if (first == Quaternion('i'))
        {
            Quaternion second('1');
            for (int j = i + 1; j < N; ++j)
            {
                second = second * q[j - 1];
                
     //           printf("%s ", first.toStr().c_str());
      //          printf("%s\n", second.toStr().c_str());
                if (second == Quaternion('j') && prod[j] == Quaternion('k'))
                {
                    return "YES";
                }
            }
        }
    }
    return "NO";
}

const char* goFast(int L, int X, char a[])
{
}

const char* solve()
{
    int L, X;
    char a[1 << 14];

    scanf("%d%d%s", &L, &X, a);
    return goSlow(L, X, a);

    if (L < 10)
    {
        return goSlow(L, X, a);
    }
    else
    {
        return goFast(L, X, a);
    }
    return "NO";
}

int main()
{
    int tests;

    scanf("%d", &tests);

    for (int i = 1; i <= tests; ++i)
    {
        printf("Case #%d: %s\n", i, solve());
    }
}
