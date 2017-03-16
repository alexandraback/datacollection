#include <iostream>
#include <cstdio>
using namespace std;

struct num
{
    char c;
    bool neg;
};

num f(num, char);
num f(num, num);
num f(char, num);


num f(num a, char b)
{
    num lala; lala.c = b; lala.neg = false;
    return f(a, lala);
}
num f (char b, num a)
{
   num lala; lala.c = b; lala.neg = false;
   return f(lala, a);
}
num f(num a, num b)
{
    num res;
    res.neg = a.neg ^ b.neg;
    if (a.c == '1')
    {
        res.c = b.c; return res;
    }
    if (b.c == '1')
    {
        res.c = a.c; return res;
    }
    if (b.c == a.c)
    {
        res.c = '1';
        res.neg ^= 1;
        return res;
    }
    if (a.c == 'i')
    {
        if (b.c == 'j')
        {
            res.c = 'k';
        }
        if (b.c == 'k')
        {
            res.c = 'j';
            res.neg ^= 1;
        }
    }
    if (a.c == 'j')
    {
        if (b.c == 'k')
        {
            res.c = 'i';
        }
        if (b.c == 'i')
        {
            res.c = 'k';
            res.neg ^= 1;
        }
    }
    if (a.c == 'k')
    {
        if (b.c == 'i')
        {
            res.c = 'j';
        }
        if (b.c == 'j')
        {
            res.c = 'i';
            res.neg ^= 1;
        }
    }
    return res;
}

int main()
{
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        long long l;
        long long x;
        string s;
        cin >> l >> x;
        cin >> s;


        num fs; fs.c = '1'; fs.neg = false;
        for (int i = 0; i < l; i++)
        {
            fs = f(fs, s[i]);
            //cout << fs.c << " " << fs.neg << endl;
        }
        num whole; whole.c = '1'; whole.neg = false;
        for (int i = 0; i < x % 4; i++)
            whole = f(whole, fs);
       // cout << whole.c << " " << whole.neg << endl;
        if (whole.c != '1' || whole.neg != true)
        {
            cout << "Case #" << tt << ": NO" << endl;
            continue;
        }

        num left; long long i = 0;
        left.c = '1'; left.neg = false;
        while (!(left.c == 'i' && left.neg == false) && (i < min(4*l, x*l)))
        {
            left = f(left, s[i % l]);
            i++;
        }
        if (!(left.c == 'i' && left.neg == false))
        {
            cout << "Case #" << tt << ": NO" << endl;
            continue;
        }
        i--;
        num right; long long j = x*l - 1;
        right.c = '1'; right.neg = false;
        while (!(right.c == 'k' && right.neg == false) && (j >= max((long long)0, (x - 4)*l )))
        {
            right = f(s[j % l], right);
            j--;
        }
        j++;
        if (!(right.c == 'k' && right.neg == false) || i >=j)
        {
            cout << "Case #" << tt << ": NO" << endl;
            continue;
        }

        cout << "Case #" << tt << ": YES" << endl;

    }
    return 0;
}
