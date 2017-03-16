# include <bits/stdc++.h>
using namespace std;
# define x first
# define y second
# define ll long long
# define db long double
ifstream fi("b.in");
ofstream fo("b.out");
ll p[55];
int get(int digit,char c)
{
    return c == '?' || (digit == c - '0');
}
int main(void)
{
    int t;
    p[0] = 1;
    for (int i = 1;i <= 18;++i) p[i] = p[i-1] * 10;
    fi>>t;
    for (int cs = 1;cs <= t;++cs)
    {
        fo << "Case #" << cs << ": ";
        string a,b;
        fi>>a>>b;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int sz = a.length();
        for (int i = sz;i < 3;++i) a += '0';
        for (int i = sz;i < 3;++i) b += '0';
        int ba = 0,bb = 1e5;
        for (int i = 0;i <= 999;++i)
            for (int j = 0;j <= 999;++j)
                    if (get(i % 10,a[0]) && get((i/10) % 10,a[1]) && get((i / 100) % 10,a[2]) && get(j % 10,b[0]) && get((j / 10) % 10,b[1]) && get((j / 100) % 10,b[2]))
                    {
                        if (abs(ba - bb) > abs(i - j)) ba = i,bb = j;
                        else
                        if (abs(ba - bb) == abs(i - j) && i < ba) ba = i,bb = j;
                        else
                        if (abs(ba - bb) == abs(i - j) && i == ba && j < bb) ba = i,bb = j;
                    }
        if (sz >= 3) fo << ((ba / 100) % 10);
        if (sz >= 2) fo << ((ba / 10) % 10);
        if (sz >= 1) fo << ((ba / 1) % 10);
        fo << ' ';
        if (sz >= 3) fo << ((bb / 100) % 10);
        if (sz >= 2) fo << ((bb / 10) % 10);
        if (sz >= 1) fo << ((bb / 1) % 10);
        fo << '\n';
        /*ll sa = 0,sb = 0;
        for (int i = 0;i < sz;++i)
        {
            if (a[i] != '?') sa += p[i] * (a[i] - '0');
            if (b[i] != '?') sb += p[i] * (b[i] - '0');
        }*/
    }
    return 0;
}

