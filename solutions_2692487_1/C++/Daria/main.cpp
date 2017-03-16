#include <fstream>
#include <algorithm>

using namespace std;

int test, t, i, n, S, sum, from, k, x, sol, stop, Log[20000010], a[20000010];

int main()
{
    ifstream fi("motes.in");
    ofstream fo("motes.out");
    fi >> t;
    for(i = 2; i <= 2000000; i++) Log[i] = Log[i/2] + 1;
    while(t--)
    {
        if(test == 22)
        test = 22;
        test++;
        fi >> S >> n;
        for(i = 1; i <= n; i++) fi >> a[i];
        if(S == 1)
        {
            fo << "Case #" << test << ": " << n << "\n";
            continue;
        }
        sort(a+1, a+n+1);
        stop = int(2e9); sol = 0;
        for(i = 1; i <= n; i++)
        if(a[i] < S)
        {
            S += a[i];
            continue;
        }
        else
        {
            x = S-1;
            sum = a[i] + x - S;
            from = sum / x;
            if(from*x < sum) from++;
            k = Log[from];
            if(x*((1<<k) - 1) + S <= a[i]) k++;

            stop = min(stop, sol + n - i + 1);
            sol += k;
            S += x*((1 << k) - 1) + a[i];
        }
        stop = min(stop, sol);
        fo << "Case #" << test << ": " << stop << "\n";
    }
    return 0;
}
