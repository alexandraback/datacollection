#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <set>
#include <cmath>

using namespace std;

#define ll long long
#define ld long double
#define op operator
#define m_p make_pair
#define fi first
#define se second

ll gcd(ll a, ll b)
{
    return a == 0 ? b : gcd(b % a, a);
}

ll st2[50];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    for(int t = 0; t < T; t++)
    {
        cout << "Case #" << t + 1 << ": ";
        ll P, Q;
        char c;
        cin >> P >> c >> Q;
        ll g = gcd(P, Q);
        P /= g;
        Q /= g;
        st2[1] = 1;
        for(int i = 2; i < 50; i++)
            st2[i] = st2[i - 1] * 2;

        int j;
        for(j = 0; j < 50; j++)
            if(st2[j] == Q)
            {
                break;
            }

        if(j == 50)
        {
            cout << "impossible" << endl;
            continue;
        }
        int i;
        for(i = 0; st2[i + 1] <= P; i++);

        cout << j - i << endl;
    }
}
