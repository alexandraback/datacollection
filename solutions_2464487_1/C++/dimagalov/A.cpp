#include<fstream>
#include<cmath>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

//const long long int INF = 1e18;

main()
{
    unsigned long long int t;
    fin >> t;
    for (unsigned long long int q = 0; q < t; ++q)
    {
        fout << "Case #" << q + 1 << ": ";
        unsigned long long int R, T;
        fin >> R >> T;
        unsigned long long int l = (unsigned long long int)1, r = min((unsigned long long int)1e9, max((unsigned long long int)2, T / (2 * R + 1)) + 10), m;
        //unsigned long long int l = 1, r = (unsigned long long int)1e9, m;
        while(r - l > 1)
        {
            m = (l + r) / 2;
            if((2 * (m + R) * m - m) <= T)
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
