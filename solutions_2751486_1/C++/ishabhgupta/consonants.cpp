#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define frl(a, b, c) for( a = b; a < c; a++)
#define fru(a, b, c) for( a = b; a <= c; a++)
#define frd(a, b, c) for( a = b; a >= c; a--)
#define mst(a, b) memset(a, b, sizeof(a))



int main()
{
    int n, k, t;
    cin >> t;
    string str;
    long long ans = 0, sz;
    int posi = 0, i, j, test = 1;
    while(t--)
    {
        int flag = 0;
        posi = 0, ans = 0;
        cin >> str >> k;
        sz = str.size();
        int tempo = 0;
        for(i = 0; i < sz; i++)
        {
            if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u')
                tempo++;
            else
                tempo = 0;
            if(tempo >= k)
            {
                flag++;
                if(flag > 1)
                    ans += ((i - posi - k + 1) * (sz - i));
                else
                    ans += ((i - posi - k + 2 ) * (sz - i));
                posi = i - k + 1;
            }
        }
        cout << "Case #" << test++ << ": " << ans << endl;
    }
}
