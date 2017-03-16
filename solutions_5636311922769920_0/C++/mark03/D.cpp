#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void foo()
{
    ll K, C, S;
    cin >> K >> C >> S;

    if(S < (K+C-1)/C)
    {
        cout << "IMPOSSIBLE";
        return;
    }

    for(int i=1; i<=K; i+=C)
    {
        ll pos=1;
        for(ll j=0; j<C; ++j)
            pos = (pos-1)*K + min(K, i+j);
        cout << pos << " ";
    }
}

int main()
{
    int T;
    cin >> T;

    for(int i=0; i<T; ++i)
    {
        cout << "Case #" << i+1 << ": ";
        foo();
        cout << "\n";
    }
    return 0;
}
