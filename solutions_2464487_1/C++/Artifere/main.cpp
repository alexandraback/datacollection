#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

inline long long res(long long p, long long r)
{
    return 2*p*p+p*(2*r+3)+2*r+1;
}

int main()
{
    freopen("large.in", "r", stdin);
    freopen("large.out", "w", stdout);

    int nbT;
    cin >> nbT;
    const double eps = 0.3;

    for (int t = 1; t <= nbT; t++)
    {
        double rad, vol;

        cin >> rad >> vol;

        double delta2 = (2*rad+3)*(2*rad+3)-8*(2*rad+1-vol);
        //cout << delta2 << endl;
        double delta = sqrt(delta2);
        //cout << delta << "===>" << (2.*rad-3.) << endl;
        int sum = 0;

        int p = 0;
        //for (p = 0; sum <= vol; p++)
        //    sum += 2*rad+4*p+1;

        //cout << "Case #" << t << ": " << (double)(((-2.*rad-3.)+delta)/4.0)+1 << "\n";
        long long truc = (long long)floor((((-2.*rad-3.)+delta)/4.0));
       //if (res(truc+1, rad) <= vol+eps)
            truc++;
        printf("Case #%d: %lld\n", t, truc);

        //cout << "Case #" << t << ": " << p-1 << "\n";
    }


    //cout << "Hello world!" << endl;
    return 0;
}
