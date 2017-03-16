#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;
typedef long long ll;
typedef long double ld;

ll gcd(ll P, ll Q)
{
    if (Q == 0) return P;
    return gcd(Q, P%Q);
}

int main()
{
    ifstream f ("X.in");
    ofstream g ("X.out");
    int T;
    ll P, Q;
    string line;
    f >> T;
    for (int t = 0; t < T; t++)
    {
        g << "Case #" << t+1 << ": ";
        f >> line;
        for (auto &x: line)
            if (x == '/') x = ' ';
        istringstream iss(line);
        iss >> P >> Q;
        if (P > Q)
        {
            g << "impossible\n";
            continue;
        }
        ll D = gcd(P,Q);
        P /= D;
        Q /= D;
        int e = 0;
        while (Q%2 == 0)
        {
            Q /= 2;
            e++;
        }
        int b = 0;
        while (P > 1)
        {
            P /= 2;
            b++;
        }
        if (Q > 1) g << "impossible\n";
        else {
            g << e-b << '\n';
        }
    }

    return 0;
}
