#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

bool isFairNumber(ll n)
{
    ll m = 0;
    ll t = n;

    while (t > 0)
    {
        m = m * 10 + t % 10;
        t /= 10;
    }

    return n == m;
}

void getFairNumbers(vector<ll>& table, ll begin, ll end)
{
    for (ll i = begin; i < end; ++i)
    {
        if (isFairNumber(i) && isFairNumber(i * i))
        {
            table.push_back(i * i);
        }
    }
}

int solve(ll begin, ll end, const vector<ll>& fairNumbers)
{
    return upper_bound(fairNumbers.begin(), fairNumbers.end(), end) -
        lower_bound(fairNumbers.begin(), fairNumbers.end(), begin);
}

int main()
{
    int T;
    cin>>T;

    vector<ll> fairNumbers;
    getFairNumbers(fairNumbers, 1, 10000000);
    for (int i = 0; i < T; ++i)
    {
        ll A, B;
        cin>>A>>B;

        int result = solve(A, B, fairNumbers);
        cout<<"Case #"<<(i + 1)<<": "<<result<<endl;
    }
}
