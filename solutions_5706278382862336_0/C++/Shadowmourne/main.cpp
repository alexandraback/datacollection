#include <iostream>
#include <cstring>

using namespace std;

long long gcd(long long a, long long b);

int main()
{
    int T;
    long long p, q, g;
    cin>>T;
    for (int t = 1; t <= T; ++t) {
        cin>>p;
        cin.get();
        cin>>q;
        g = gcd(p, q);
        p /= g;
        q /= g;
        cout<<"Case #"<<t<<": ";
        if (q & (q-1) || q > (long long)1<<40)
            cout<<"impossible"<<endl;
        else {
            cout<<__builtin_clzll(p)-__builtin_clzll(q)<<endl;
        }
    }
    return 0;
}

long long gcd(long long a, long long b)
{
    long long c;
    while (a != 0) {
        c = a;
        a = b % a;
        b = c;
    }
    return b;
}

