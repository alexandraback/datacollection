#include <iostream>
#include <fstream>

using namespace std;

fstream in, out;

long long gcd(long long P, long long Q)
{
    if (P == 0)
        return Q;

    return gcd(Q%P, P);
}


void solve()
{
    long long P, Q, g, ans = 0;
    char c;
    in >> P >> c >> Q;

    g = gcd(P, Q);
    P /= g, Q /=g;

    //cout << P << "\t" << Q;
   
    if (Q & (Q-1))
    {
        out << "impossible";
        return;
    }   

    while (P != 1 || Q != 1)
    {
        ++ans;
        Q /= 2;

        if(P > Q) 
        {
            P = P - Q;
            if (P & 1) break;
        }
    }


    out << ans;
}

int main()
{
    in.open("in.txt");
    out.open("out.txt");

    int T;
    in >> T;

    for(int i = 0; i < T; ++i)
    {
        out << "Case #" << (i +1) << ": ";
        solve();
        out << endl;
    }
    return 0;
}
