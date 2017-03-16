#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

int pow10[10];

int ndigit(int a)
{
    int res;
    if(!a) return 1;
    for(res = 0; a; a /= 10) ++res;
    return res;
}

int main()
{
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    
    int ntest, a, b, test, i, j, res, ii;
    set<int> s;
    cin >> ntest;
    
    pow10[0] = 1;
    for(i = 1; i <= 8; ++i)
        pow10[i] = pow10[i-1] * 10;
    
    for(test = 1; test <= ntest; ++test)
    {
        cin >> a >> b;
        res = 0;
        for(i = a; i <= b; ++i)
        {
             int ncif = ndigit(i);
             s.clear();
             for(ii = i, j = 1; j <= ncif; ++j)
             {
                 ii = ii/10 + ii%10 * pow10[ncif-1];
                 if(i < ii && a <= ii && ii <= b && ndigit(ii) == ncif && s.find(ii) == s.end()) 
                 {   
                     s.insert(ii);
                     ++res;
                 }
             }
        }
        cout << "Case #" << test << ": " << res << "\n";
    }    
    return 0;
}
