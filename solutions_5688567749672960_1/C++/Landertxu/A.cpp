#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

#define fii(x,y) for(int i=x;i<y;i++)
#define fjj(x,y) for(int j=x;j<y;j++)
#define fkk(x,y) for(int k=x;k<y;k++)
#define fi(x) fii(0,x)
#define fj(x) fjj(0,x)
#define fk(x) fkk(0,x)
#define eps 0.0000000001
#define inf 1<<28

using namespace std;

typedef long long ll;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef vector <VVI> VVVI;
typedef vector <ll> VL;
typedef vector <VL> VVL;
typedef vector <double> VD;
typedef vector <VD> VVD;
typedef vector <bool> VB;
typedef vector <VB> VVB;
typedef queue <int> QI;
typedef pair<int,int> PI;
typedef pair<int,PI> PT;
typedef queue<PI> QPI;
typedef priority_queue<PT> QPT;
typedef pair<double,double> PD;

ll rev(ll i)
{
    ll ans = 0;
    while (i > 0)
    {
        ans *= 10;
        ans += i % 10;
        i /= 10;
    }
//     cout << i << " " << ans << endl;
    return ans;
}

ll numcf(ll x)
{
    if (x < 10) return 1;
    return 1 + numcf(x/10);
}

ll sumcf(ll x)
{
    if (x < 10) return x;
    return x % 10 + sumcf(x/10);
}

ll calc(ll x)
{
    if (x < 10) return x;
    ll cf = numcf(x);
    ll low = (cf + 1) / 2;
    
    ll msk = 1;
    fi (low) msk *= 10;
    
    ll plow = x % msk;
    if (plow == 1)
    {
        if (sumcf(x) == 2)
            return 2 + calc(x-2);
        return 1 + calc(rev(x));
    }
    if (plow > 1)
        return plow - 1 + calc(x - plow + 1);
    
    return 1 + calc(x-1);
    
}

int main()
{
//     int N = 1000000;
//     VI din(N+1, N + 1);
//     din[1] = 1;
//     fii (1, N)
//     {
//         
//         din[i+1] = min (din[i+1], 1 + din[i]);
//         if (din[i+1] < din[i])
//             cout << i << " " << din[i] << " " << din[i+1] << endl;
//         int b = rev(i);
//         if (b < i and din[b] > din[i] + 1)
//             cout << i << " " << b << endl;
//         if (b > i)
//             din[b] = min (din[b], 1 + din[i]);
// 
// //         if (i > 998000)
// //             cout << i << " " << din[i] << endl;
//     }
    int T;
    cin >> T;
    for (int caso = 1; caso <= T; caso++)
    {
        ll x;
        cin >> x;
        cout << "Case #" << caso << ": " << calc(x) << endl;
    }
}