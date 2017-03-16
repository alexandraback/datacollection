/*
ID: dhxav
PROG: safety_n_numbers
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <queue>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fornd(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define forabd(i, a, b) for (int i = (int)(b); i >= (int)(a); i--)

int main() {
    ifstream fin ("A-large.in");
    ofstream fout ("A-large.out");

    int T;
    fin >> T;

    forn (i, T)
    {
        int N;
        fin >> N;

        vector <int> s(N);
        vector <int> stemp(N);
        vector <int> sum(N);
        int index;
        forn (i, N)
        {
            fin >> s[i];
            stemp[i] = s[i];
        }

        sort (stemp.begin(),stemp.end());
        sum[0] = stemp[0];
        forab (i,1,N-1) sum[i] = sum[i-1]+stemp[i];

        fornd (i, N)
        {
            if (stemp[i]<=(double)(sum[i]+sum[N-1])/(i+1))
            {
                index = i;
                break;
            }
        }

        fout << "Case #" << i+1 << ": ";
        fout << fixed;
        forn  (i, N)
        {
            if (s[i]>(double)(sum[index]+sum[N-1])/(index+1))
                fout << setprecision(6) << 0.0 << " ";
            else
                fout << setprecision(6) << ((double) (sum[index]+sum[N-1])/(index+1) - s[i])*100/sum[N-1] << " ";
        }
        fout << endl;

    }

    system("PAUSE");
}


