#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int ntest, n, s, p, i, test, points, res;
    
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    
    cin >> ntest;
    for(test = 1; test <= ntest; ++test)
    {
       cin >> n >> s >> p;
       for(res = i = 0; i < n; ++i)
       {
           cin >> points;
           if(3*p - 2 <= points) ++res;
           else if(s && ((p+max(0,p-2)+max(0,p-2)) <= points)) ++res, --s;
       }
       cout << "Case #" << test << ": " << res << "\n";
    }
    return 0;
}
