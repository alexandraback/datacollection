#include <cstdio>
#include <vector>

#define PB push_back

using namespace std;

typedef long long ll;

int main()
{
    freopen("D-large.in", "r", stdin);
    freopen("output_large.txt", "w", stdout);

    int T;
    scanf("%d", &T);

    for(int ct = 1; ct <= T; ct++)
    {
        int K, C, S;
        scanf("%d%d%d", &K, &C, &S);

        ll p[100];
        p[0] = 1;
        for(int i = 1; i < 100; i++)
            p[i] = p[i-1]*K;

        printf("Case #%d:", ct);
        vector<ll> v;

        for(ll i = 0; i*C < K; i++)
        {
            ll id = 1;
            ll beg = min(C*(i+1), (ll)K)-1;
            for(ll k = 0; k < C; k++)
                id += max((beg-k),0LL)*p[k];
            v.PB(id);
        }

        if(S < (int)v.size())
            printf(" IMPOSSIBLE\n");
        else
        {
            for(int i = 0; i < (int)v.size(); i++)
                printf(" %lld", v[i]);
            printf("\n");
        }
    }

    return 0;
}
