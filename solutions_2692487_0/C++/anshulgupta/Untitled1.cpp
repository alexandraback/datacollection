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


ull fun(ull ar[], ull n, ull a, ull k = 0) 
{
    if(k == n)
        return 0;
    
    if(ar[k] < a)
    {
        return fun(ar, n, a + ar[k], k+1);
    }
    else if(a == 1)
    {
        return n-k;
    }
    else
    {
        return min(n-k, 1 + fun(ar, n, a + a-1, k));
    }
}

int main()
{
    ull cases, a , n, k = 1;
    cin >> cases;
    
    while(cases--) 
    {
        cin >> a >> n;
        ull ar[n];
        for(ull i = 0; i < n; i++)
            cin >> ar[i];
        sort(ar, ar + n);
        cout << "Case #" << k++ << ": " << fun(ar, n, a) << endl;
    }
    
    return 0;
}
