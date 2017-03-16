#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

unsigned A, N;
unsigned motes[10000];

int main()
{
    freopen("large.in", "r", stdin);
    freopen("large.out", "w", stdout);
    int t = 1, nbT;

    cin >> nbT;
    while (t <= nbT)
    {
        cin >> A >> N;
        for (int i = 0; i < N; i++)
            cin >> motes[i];
        sort(motes, motes+N);

        int rep = 10000;


        int curNb = 0;
        for (unsigned i = 0; i < N; i++)
        {

            if (A > motes[i])
            {
                //cout << A << endl;
                A += motes[i];
            }
            else
            {
                rep = min(rep, N-i+curNb);
                if (A == 1)
                {
                    curNb = rep;
                    break;
                }
                while (A <= motes[i])
                {
                    A += A-1;
                    curNb++;
                }
                A += motes[i];
            }
        }
        rep = min(rep, curNb);

        cout << "Case #" << t << ": " << rep << "\n";
        t++;
    }






    return 0;
}
