#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll solve(int ai, int bi, const vector<pair<ll, ll> > &a, vector<pair<ll, ll> > &b)
{
    int N = a.size();
    int M = b.size();

    if (ai >= N)
    {
        return 0;
    }

    ll sum = 0;
    ll ret = 0;
    for (int i = bi; i < M; ++i)
    {
        ll use = 0;
        if (a[ai].second == b[i].second)
        {
            use = b[i].first;
            if (a[ai].first <= sum + b[i].first)
            {
                use = a[ai].first - sum;
            }
            sum = min(a[ai].first, sum + b[i].first);
        }

        b[i].first -= use;
        ret = max(ret, sum + solve(ai + 1, i, a, b));
        b[i].first += use;
    }

    return ret;
}
int main()
{
    int T;
    cin>>T;

    for (int caseNum = 1; caseNum <= T; ++caseNum)
    {
        int N, M;
        cin>>N>>M;

        vector<pair<ll, ll> > a(N);
        for (int i = 0; i < N; ++i)
        {
            cin>>a[i].first>>a[i].second;
        }
        vector<pair<ll, ll> > b(M);
        for (int i = 0; i < M; ++i)
        {
            cin>>b[i].first>>b[i].second;
        }

        cout<<"Case #"<<caseNum<<": "<<solve(0, 0, a, b)<<endl;
    }

    return 0;
}
