#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("inp.in", "r", stdin);
    freopen("outp.out", "w", stdout);
    int tc;
    scanf("%d", &tc);
    for(int kras=1; kras<=tc; kras++)
    {
        printf("Case #%d: ", kras);
        long long n;
        scanf("%lld", &n);
        if(n==0)
        {
            printf("INSOMNIA\n");
            continue;
        }
        vector<bool> seen(10, false);
        unsigned long long now=n;
        int ctr=0;
        while(true)
        {
            unsigned long long cop_of_now = now;
            while(cop_of_now != 0)
            {
                int dig = cop_of_now%10;
                cop_of_now /= 10;
                if(!seen[dig])
                {
                    seen[dig] = true;
                    ctr++;
                }
            }
            if(ctr == 10)
            {
                break;
            }
            now += n;
        }
        cout << now << "\n";

    }
    return 0;
}
