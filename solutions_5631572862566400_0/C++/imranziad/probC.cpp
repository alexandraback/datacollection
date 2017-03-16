#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define NL '\n'
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pi 2.0*acos(0.0)
#define MOD 1000000007
#define MAX 100005

int b[105], sz, a[105];

bool valid()
{
    for(int i = 0; i < sz; i++)
    {
        if(i >= 0 && b[i-1] == a[ b[i] ]) continue;
        if(i < sz-1 && b[i+1] == a[ b[i] ]) continue;
        if(i == 0 && b[sz-1] == a[ b[i] ]) continue;
        if(i == sz-1 && b[0] == a[ b[sz-1] ]) continue;
        return false;
    }

    return true;
}

bool check()
{
    if(valid()) return true;

    while(next_permutation(b, b+sz))
    {
        if(valid()) return true;
    }

    return false;
}

int main()
{
    //READ("C-small-attempt0.in");
    //WRITE("C-small-attempt0.out");
    std::ios_base::sync_with_stdio(0);
    int cases, caseno=0, n, i, j, k, z, cnt, mx;

    cin >> cases;

    while(cases--)
    {
        cin >> n;

        FOR(i,1,n) cin >> a[i];

        z = 1<<n;
        mx = 0;

        for(i = 1; i < z; i++)
        {
            sz = 0;

            for(j = 0; j < n; j++)
            {
                if(i & (1<<j))
                {
                    b[sz++] = j+1;
                }
            }

            if(sz > mx && check())
                mx = sz;
        }

        cout << "Case #" << ++caseno << ": " << mx << "\n";
    }

    return 0;
}
