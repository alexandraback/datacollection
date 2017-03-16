#include <bits/stdc++.h>

using namespace std;

const int nmax = 1009;

long long pw[nmax];
string qnr , wnr , fx , fy;
long long bst;
string a , b;
int i , T , tests;

void check()
{
    long long x = 0 , y = 0;
    int i;

    for (i = 0 ; i < a.size() ; ++i)
    {
        x = 10 * x + qnr[i] - '0';
        y = 10 * y + wnr[i] - '0';
    }

    long long v = x - y;
    if (v < 0) v = -v;

    if (v < bst) bst = v , fx = qnr , fy = wnr;
    else
    {
        if (v == bst)
        {
            if (qnr < fx) fx = qnr , fy = wnr;
            else
            {
                if (qnr == fx)
                if (wnr < fy) fy = wnr;
            }
        }
    }
}

void goSmaller(int p)
{
    if (p == a.size())
    {
        check();
        return;
    }

    if (a[p] == '?')
    qnr[p] = '9';
    else qnr[p] = a[p];

    if (b[p] == '?')
    wnr[p] = '0';
    else wnr[p] = b[p];

    goSmaller(p + 1);
}

void goBigger(int p)
{
    if (p == a.size())
    {
        check();
        return;
    }

    if (a[p] == '?')
    qnr[p] = '0';
    else qnr[p] = a[p];

    if (b[p] == '?')
    wnr[p] = '9';
    else wnr[p] = b[p];

    goBigger(p + 1);
}

void goEqual(int p)
{
    if (p == a.size())
    {
        check();
        return;
    }

    if (a[p] == '?')
    {
        for (int i = 0 ; i <= 9 ; ++i)
        {
            qnr[p] = i + '0';
            if (b[p] == '?')
            {
                for (int j = 0 ; j <= 9 ; ++j)
                {
                    wnr[p] = j + '0';
                    if (qnr[p] < wnr[p]) goSmaller(p + 1);
                    else
                    {
                        if (qnr[p] > wnr[p]) goBigger(p + 1);
                        else goEqual(p + 1);
                    }
                }
            }
            else
            {
                wnr[p] = b[p];
                if (qnr[p] < wnr[p]) goSmaller(p + 1);
                else
                {
                    if (qnr[p] > wnr[p]) goBigger(p + 1);
                    else goEqual(p + 1);
                }
            }
        }
    }
    else
    {
        qnr[p] = a[p];

        if (b[p] == '?')
        {
            for (int j = 0 ; j <= 9 ; ++j)
            {
                wnr[p] = j + '0';
                if (qnr[p] < wnr[p]) goSmaller(p + 1);
                else
                {
                    if (qnr[p] > wnr[p]) goBigger(p + 1);
                    else goEqual(p + 1);
                }
            }
        }
        else
        {
            wnr[p] = b[p];
            if (qnr[p] < wnr[p]) goSmaller(p + 1);
            else
            {
                if (qnr[p] > wnr[p]) goBigger(p + 1);
                else goEqual(p + 1);
            }
        }
    }
}

int main()
{
freopen("test.in" , "r" , stdin);
freopen("test.out" , "w" , stdout);

pw[0] = 1;
for (i = 1 ; i <= 18 ; ++i)
pw[i] = 10 * pw[i - 1];

cin >> tests;
for (T = 1 ; T <= tests ; ++T)
{
    qnr.clear() , wnr.clear();
    cin >> a >> b;
    qnr.resize(a.size()) , wnr.resize(a.size());

    bst = pw[18];
    goEqual(0);

    cout << "Case #" << T << ": " << fx << " " << fy << '\n';
}

return 0;
}
