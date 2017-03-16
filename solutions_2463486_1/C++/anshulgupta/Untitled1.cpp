#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
#include <map>
#include <set>

using namespace std;
typedef unsigned long long ull;

bool *ar;
bool is_palin(ull n)
{
    ull rev = 0, num = n;
    
    while(n > 0)
    {
        rev = rev*10 + n%10;
        n /= 10;
    }
    return (rev == num);
}

void pre()
{
    ar = new bool[10000001];
    for(ull i = 0; i <= 10000000; i++)
    {
        ar[i] = 0;
    }
    for(ull i = 1; i <= 10000000; i++)
    {
        if(is_palin(i) && is_palin(i*i))
            ar[i] = 1;
    }
}

bool is_fair_sq(ull i)
{
    return ar[i];
}

int main()
{
    ull cases, n, m, cnt, k = 1;
    cin >> cases;
    pre();   
    while(cases--) 
    {
        cnt = 0;
        cin >> n >> m;
        
        ull i = ceil(sqrt(n));
        for(; i*i <= m && i >= 0; i++)
        {
            if(is_fair_sq(i))
                cnt++;
        }
        cout << "Case #" << k++ << ": " << cnt << endl; 
    }
    return 0;
}
