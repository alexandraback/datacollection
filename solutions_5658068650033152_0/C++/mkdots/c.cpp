#include <iostream>
#include <iostream>
#include <algorithm>

using namespace std;

int span[23];
int spanf[23];
int main()
{
    int T;
    cin >> T;
    
    for(int t = 0; t < T; ++t)
    {
        int n, m, k;
        cin >> n >> m >> k;
        
        if(n > m)
            swap(n, m);
        
        int best = k;
        
        for(int f = 1; f <= n; ++f)
            for(int s = 1; s <= f; ++s)
                for (int d = 0; d <= m - 2; ++d)
                {
                    int c = s + f;
                    int u = s + f;
                    if(d == 0)
                    {
                        if(u >= k)
                            best = min(best, c);
                        continue;
                    }
                    span[0] = s;
                    for(int i = 1; i <= d + 1; ++i)
                    {
                        span[i] = min(n, span[i-1] + 2);
                    }
                    if(span[d + 1] < f)
                        continue;
                    c += 2 * d;
                    spanf[d + 1] = f;
                    for(int i = d; i >= 0; --i)
                        spanf[i] = min(n, spanf[i + 1] + 2);
                    u = 0;
                    for(int i = 0; i <= d + 1; ++i)
                        u += min(span[i], spanf[i]);
                        
                    if(u >= k)
                        best = min(best, c);
                }
        
        cout << "Case #" << t + 1 << ": " << best <<  "\n";
    }
    
    return 0;
}