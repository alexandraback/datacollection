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
#define MAX 2600

int main()
{
    //READ("B-small-attempt0.in");
    //WRITE("B-small-attempt0.out");
    std::ios_base::sync_with_stdio(0);
    int cases, caseno=0, n, i, j, k, cnt, sum;
    int a[MAX];
    vector <int> v;

    cin >> cases;

    while(cases--)
    {
        cin >> n;

        mem(a,0);
        v.clear();

        FOR(i,1,n+n-1)
        {
            FOR(j,0,n-1)
            {
                cin >> k;
                a[k]++;
            }
        }

        FOR(i,0,2500)
        {
            if(a[i] % 2 == 1)
            {
                v.pb(i);
            }
        }

        sort(v.begin(),v.end());

        if(v.size() != n) cerr << "ERROR" << NL;

        cout << "Case #" << ++caseno << ": " << v[0];

        FOR(i,1,v.size()-1)
            cout << " " << v[i];

        cout << "\n";
    }

    return 0;
}

