#include <iostream>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cmath>
#define LL long long

using namespace std;

LL gcd(LL a, LL b)
{
    //cout << a << " " << b << endl;
    if (b > a)
    {
        return gcd(b,a);
    }
    if (b == 0)
    {
        return a;
    }
    if (b == 1)
    {
        return b;
    }
    return gcd(b,a%b);
}

LL run(LL num, LL den)
{
    LL ctr = 0;
    LL G = gcd(num,den);
    //cout << num << " " << den << " " << G << endl;
    if (G== 0) return -1;
    num/=G;
    den/=G;

    while(den%2==0 && ctr < 40)
    {
        //cout << num << " " << den << " " << ctr << endl;

        if (num >= den && num <= 2*den)
        {
            if (run(num-den,den)!=-1)
            {
                return ctr;
            }

        }
        den/=2;
        ctr++;

    }
    if (ctr > 40)
    {
        return -1;
    }

    if (num == den || num == 2*den)
    {
        return ctr;
    }

    return -1;

}

int main()
{
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int T;
    string s;

    getline(cin, s);
    T=atoi(s.c_str());
   // run(11,128);

    for (int Case = 1; Case <= T; Case++)
    {

        getline(cin, s);
        //cout << s << endl;
        int pos = s.find('/');
        string num = s.substr(0,pos);
        string num2 = s.substr(pos+1);
        LL ans = run(atoll(num.c_str()), atoll(num2.c_str()));
        if (ans == -1)
        {
            cout << "Case #" << Case << ": impossible" << endl;
        }else
        {
            cout << "Case #" << Case << ": " << ans << endl;
        }

    }
    return 0;
}
