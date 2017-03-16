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

bool ar[1001];

bool is_palin(int n)
{
    int rev = 0, num = n;
    
    while(n > 0)
    {
        rev = rev*10 + n%10;
        n /= 10;
    }
    return (rev == num);
}

void pre()
{
    for(int i = 0; i <= 1000; i++)
        ar[i] = 0;
    
    for(int i = 1; i*i <= 1000; i++)
    {
        if(is_palin(i) && is_palin(i*i))
            ar[i*i] = 1;
    }
}

bool is_fair_sq(int i)
{
    return ar[i];
}

int main()
{
    int cases, n, m, cnt, k = 1;
    cin >> cases;
    pre();   
    while(cases--) 
    {
        cnt = 0;
        cin >> n >> m;
        for(int i = n; i <= m; i++)
            if(is_fair_sq(i))
                cnt++;
        cout << "Case #" << k++ << ": " << cnt << endl; 
    }
    return 0;
}
