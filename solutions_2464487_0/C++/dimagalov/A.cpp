#include<fstream>
#include<cmath>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

//const long long int INF = 1e18;

main()
{
    long long int t;
    fin >> t;
    for (long long int q = 0; q < t; ++q)
    {
        fout << "Case #" << q + 1 << ": ";
        long long int R, T;
        fin >> R >> T;
        long long int l = 1LL, r = min((long long int)1e9, max(2LL, T / (2 * R + 1)) + 10), m;
        while(r - l > 1LL)
        {
            m = (l + r) / 2LL;
            if(((2LL * (m - 1LL) + 1LL) * m + (2LL * R * m)) <= T)
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        fout << l << endl;
    }
}
