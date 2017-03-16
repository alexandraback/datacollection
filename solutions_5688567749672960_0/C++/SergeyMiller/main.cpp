#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define SZ 1000*1000
using namespace std;
typedef long long ll;

ll rz(ll i)
{
    vector <ll> h;
    ll ans = 0;
    bool cnt = 0;
    while(i)
    {
        h.push_back(i%10);
        i /= 10;
    }
    for(ll i = 0;i < h.size();++i)
    {
        if(h[i])
            cnt = 1;
        if(cnt)
        {
            ans*= 10;
            ans += h[i];
        }
    }
    return ans;
}

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    vector <ll> data(SZ, SZ);

    for(ll i = 1;i <= SZ; ++i)
    {
        if(i == 1)
        {
            data[0] = 1;
            continue;
        }

        data[i-1] = min(data[i-2] + 1, data[i-1]);
        ll p = rz(i);
        data[p-1] = min(data[i-1] + 1, data[p - 1]);
    }

    ll t;
    cin >> t;

    for(ll o = 0;o < t;++o)
    {
        ll d;
        cin >> d;
        cout << "Case #" << o + 1 << ": " << data[d-1] << endl;
    }
    return 0;
}
