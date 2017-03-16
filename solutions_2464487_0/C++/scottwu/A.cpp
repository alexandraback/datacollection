#include <iostream>
#include <fstream>

using namespace std;
typedef long long ll;

ifstream fin ("blah.in");
ofstream fout ("blah.out");

ll r, t;

bool works (ll x)
{
    return t >= x * (2 * r + 2 * x - 1);
}

int main()
{
    int T; fin >> T;
    
    for (int ntest = 0; ntest < T; ntest++)
    {
    
    fin >> r >> t;
    
    //cout << r << " " << t << "\n";
    
    ll res = 0;
    ll x = 0;
    for (; x < 40; x++)
        if (!works (1 << x))
            break;
    
    for (ll n = x - 1; n >= 0; n--)
        if (works (res + (1 << n)))
            res += (1 << n);
    
    fout << "Case #" << ntest + 1 << ": " << res << "\n";
    
    }
    
    return 0;
}
