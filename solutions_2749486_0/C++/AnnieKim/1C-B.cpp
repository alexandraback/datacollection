#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using namespace std::tr1;

#define rep(i, n) for (int i = 0; i < n; ++i)
int ri() { int a; scanf( "%d", &a ); return a; }
long long rll() { long long a; scanf( "%lld" , &a ); return a ; }

int main()
{
    freopen("C:\\Users\\Administrator\\Desktop\\B-small-attempt0.in","rt",stdin);
    freopen("C:\\Users\\Administrator\\Desktop\\B-small-attempt0.out","wt",stdout);
	
    int T = ri();
    rep(t, T)
    {
        int x = ri(), y = ri();
        int step = 1;
        int i = 0, j = 0;
        string res;
        while (i != x)
        {
            if (x > i && i + step <= x)
            {
                res.push_back('E');
                i += step;
            }
            else if (x > i && i + step > x)
            {
                res.push_back('W');
                i -= step;
            }
            else if (i > x && i - step >= x)
            {
                res.push_back('W');
                i -= step;
            }
            else if (i > x && i - step < x)
            {
                res.push_back('E');
                i += step;
            }
            step++;
        }
        while (j != y)
        {
            if (y > j && j + step <= y)
            {
                res.push_back('N');
                j += step;
            }
            else if (y > j && j + step > y)
            {
                res.push_back('S');
                j -= step;
            }
            else if (j > y && j - step >= y)
            {
                res.push_back('S');
                j -= step;
            }
            else if (j > y && j - step < y)
            {
                res.push_back('N');
                j += step;
            }
            step++;
        }

        printf("Case #%d: ", t+1);
        cout<<res<<endl;
    }
    return 0;
}