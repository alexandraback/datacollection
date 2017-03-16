#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <algorithm>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 1000;
int A[N][3];
int C[3][5][5];

int main(int argc, char* argv[])
{
    int X = atoi(argv[1]);
    int Y = atoi(argv[2]);
    int testCount;
    cin >> testCount;

    forn(test, testCount)
    {
        int a, b, c, k;
        cin >> a >> b >> c >> k;
        int t = 0;

        if (!(test + 1 >= X && test + 1 <= Y))
            continue;
            

        forn(x, a)
            forn(y, b)
                forn(z, c)
                {
                    A[t][0] = x;
                    A[t][1] = y;
                    A[t][2] = z;
                    t++;
                }

        vector<int> best;
        int nbest = 0;

        forn(mask, 1 << t)
        {
            memset(C, 0, sizeof(C));
            int f = 0;
            forn(j, t)
                if (mask & (1 << j))
                    f++;
            if (f <= nbest)
                continue;
            forn(j, t)
                if (mask & (1 << j))
                {
                    if ((++C[0][A[j][1]][A[j][2]]) > k) goto end;
                    if ((++C[1][A[j][0]][A[j][2]]) > k) goto end;
                    if ((++C[2][A[j][0]][A[j][1]]) > k) goto end;
                }
end:                              
            bool ok = true;
            forn(x, 3)
                forn(y, 5)
                    forn(z, 5)
                        if (C[x][y][z] > k)
                        {
                            ok = false;
                        }            
            if (ok && nbest < f)
            {
                nbest = f;
                best.clear();
                forn(j, t)
                    if (mask & (1 << j))
                        best.push_back(j);
            }
        }

        cout << "Case #" << (test + 1) << ": " << nbest << endl;
        forn(i, best.size())
            cout << A[best[i]][0] + 1 << " " << A[best[i]][1] + 1 << " " << A[best[i]][2] + 1 << endl;
    }

    return 0;
}
