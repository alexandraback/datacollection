#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <map>
#include <set>

using namespace std;
typedef long long ull;
typedef pair<ull, ull> pi;

ull fun(pi box[], ull n, pi toy[], ull m)
{
    ull ret;
    if(n <= 0 || m <= 0)
        return 0;
    
    if(box[0].second == toy[0].second)
    {
        
        ull t1 = box[0].first, t2 = toy[0].first, a = 0, b = 0;
        ull val = min(box[0].first, toy[0].first);
        box[0].first -= val;
        toy[0].first -= val;
        if(box[0].first == 0)
            box++, n--, a = 1;
        if(toy[0].first == 0)
            toy++, m--, b = 1;
        ret = val + fun(box , n , toy, m); 
        if(a == 1)
        {
            box--;
            box[0].first = t1;
        }   
        else
            box[0].first = t1;
        if(b == 1)
        {
            toy--;
            toy[0].first = t2;
        }
        else
            toy[0].first = t2;    
    }
    else
        ret = max(fun(box, n, toy + 1, m - 1), fun(box + 1, n - 1, toy, m));
    
    return ret;
    
}
int main()
{
    ull cases, num = 1;
    cin >> cases;
    
    while(cases--)
    {
        ull n, m, b, B, idx = 0;
        cin >> n >> m;
        pi box[n], toy[m];
        for(ull i = 0; i < n; i++)
            cin >> box[i].first >> box[i].second;
        
        for(ull i = 0; i < m; i++)
            cin >> toy[i].first >> toy[i].second;
        
        cout << "Case #" << num++ << ": " << fun(box, n, toy, m) << endl;
    }
    
    return 0;
}
