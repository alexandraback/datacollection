#include <cstdio>
#include <set>

using namespace std;

typedef long long ll;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    scanf("%d", &T);

    for(int ct = 1; ct <= T; ct++)
    {
        int N;
        scanf("%lld", &N);

        if(!N)
        {
            printf("Case #%d: INSOMNIA\n", ct);
            continue;
        }

        set<int> digits;

        ll i = 1;
        while((int)digits.size() < 10)
        {
            ll k = i*N;
            while(k)
            {
                digits.insert((int)(k%10));
                k /= 10;
            }

            i++;
        }
        i--;

        printf("Case #%d: %lld\n", ct, N*i);
    }

    return 0;
}
