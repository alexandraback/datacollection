#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <list>

using namespace std;

const int MAX = 1e5;
const int INF = 1e9;
const double EPS = 1e-9;

int T, n;
string a[101];
bool f[200];
int cnt = 0;
string out;

void rec(string str, int mask)
{
    if(mask == 0)
    {
        for(int i = 'a'; i <= 'z'; ++i)
            f[i] = false;
        char c = str[0];
        f[c] = true;
        for(int i = 1; i < str.length(); ++i)
        {
            if(str[i] != c)
            {
                c = str[i];
                if(f[c])
                    return;
                f[c] = true;
            }
        }
        ++cnt;
        return;
    }
    
    for(int i = 0; i < n; ++i)
    {
        int cmask = mask & (~(1 << i));
        if(cmask != mask)
            rec(str + a[i], mask & (~(1 << i)));
    }
}

int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("outpu.txt", "w", stdout);
    cin >> T;
    
    for(int Ti = 1; Ti <= T; ++Ti)
    {
        cin >> n;
        int mask = 0;
        for(int i = 0; i < n; ++i)
        {
            cin >> a[i];
            mask |= (1 << i);
        }
        
        cnt = 0;
        
        for(int i = 0; i < n; ++i)
            rec(a[i], mask & (~(1 << i)));
        
        cout << "Case #" << Ti << ": " << cnt << "\n";
    }

    return 0;
}

