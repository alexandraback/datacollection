#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct quat
{
    char c;
    int sign;
};

quat i;
quat j;
quat k;
quat one;

quat make(char c)
{
    if (c == 'i')
        return i;
    if (c == 'j')
        return j;
    if (c == 'k')
        return k;
    return one;
}

quat mul(quat a, quat b)
{
    quat ans;
    ans.sign = a.sign * b.sign;
    if (a.c == '1')
    {
        ans.c = b.c;
        return ans;
    }
    if (a.c == 'i')
    {
        if (b.c == '1')
        {
            ans.c = 'i';
        }
        if (b.c == 'i')
        {
            ans.c = '1';
            ans.sign *= -1;
        }
        if (b.c == 'j')
        {
            ans.c = 'k';
        }
        if (b.c == 'k')
        {
            ans.c = 'j';
            ans.sign *= -1;
        }
        return ans;
    }

    if (a.c == 'j')
    {
        if (b.c == '1')
        {
            ans.c = 'j';
        }
        if (b.c == 'i')
        {
            ans.c = 'k';
            ans.sign *= -1;
        }
        if (b.c == 'j')
        {
            ans.c = '1';
            ans.sign *= -1;
        }
        if (b.c == 'k')
        {
            ans.c = 'i';
        }
        return ans;
    }

    if (a.c == 'k')
    {
        if (b.c == '1')
        {
            ans.c = 'k';
        }
        if (b.c == 'i')
        {
            ans.c = 'j';
        }
        if (b.c == 'j')
        {
            ans.c = 'i';
            ans.sign *= -1;
        }
        if (b.c == 'k')
        {
            ans.c = '1';
            ans.sign *= -1;
        }
        return ans;
    }
}

bool eq(quat a, quat b)
{
    return a.sign == b.sign && a.c == b.c;
}

quat pow(quat x, int n)
{
    if (n == 0)
    {
        return one;
    }
    if (n % 2 == 0)
    {
        quat cur = pow(x, n / 2);
        return mul(cur, cur);
    }
    return mul(x, pow(x, n - 1));
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    i.sign = 1;
    i.c = 'i';

    j.sign = 1;
    j.c = 'j';

    k.sign = 1;
    k.c = 'k';

    one.sign = 1;
    one.c = '1';
    int TEST;
    scanf("%d", &TEST);
    for (int num = 1; num <= TEST; ++num)
    {
        int l, x;
        string s;
        cin >> l >> x;
        cin >> s;

        quat res = one;
        for (int it = 0; it < s.size(); ++it)
        {
            quat cur = make(s[it]);
            res = mul(res, cur);
        }

        res = pow(res, x);

        if (!eq(res, mul(i, mul(j, k))))
        {
            printf("Case #%d: NO\n", num);
            continue;
        }
        int numi = -1;
        int numj = -1;
        quat cur = one;
        for (int it = 0; it < min(x, 4) * s.size(); ++it)
        {
            int now = it % s.size();
            cur = mul(cur, make(s[now]));
            if (eq(cur, i))
            {
                numi = it;
                break;
            }
        }
        reverse(s.begin(), s.end());
        cur = one;
        for (int it = 0; it < min(x, 4) * s.size(); ++it)
        {
            int now = it % s.size();
            cur = mul(make(s[now]), cur);
            if (eq(cur, k))
            {
                numj = x * l - it - 1;
                break;
            }
        }
        //cout << numi << " " << numj << "\n";
        if (numi != -1 && numj != -1 && numi + 1 < numj)
        {
            printf("Case #%d: YES\n", num);
        }
        else
        {
            printf("Case #%d: NO\n", num);
        }
    }

}
