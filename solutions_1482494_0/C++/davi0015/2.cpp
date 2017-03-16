/*
ID: dhxav
PROG: kingdom_rush
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
#include <queue>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fornd(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define forabd(i, a, b) for (int i = (int)(b); i >= (int)(a); i--)

int main() {
    ifstream fin ("B-small-attempt0.in");
    ofstream fout ("B-small-attempt0.out");
    int T;
    fin >> T;

    forn (i,T)
    {
         int N;
         fin >> N;
         vector <int> a(N), b(N);
         vector <int> com(N);
         forn (i, N)
         {
             fin >> a[i] >> b[i];
             b[i] = b[i]*N + i;
         }

         int numstar = 0;
         int ind = 0;
         int step = 0;
         bool finish = true;
         sort (b.begin(), b.end());

         forn (i,N)
         {
             while (b[i]/N>numstar)
             {
                finish = false;
                fornd (j,N)
                {
                    if (a[b[j]%N]<=numstar && com[b[j]%N]==0)
                    {
                        numstar++;
                        com[b[j]%N] = 1;
                        step++;
                        finish = true;
                        break;
                    }
                }
                if (finish==false) break;
             }
             if (finish==false) break;
             else
             {
                 numstar += 2 - com[b[i]%N];
                 com[b[i]%N] = 2;
                 step++;
             }
         }

         fout << "Case #" << i+1 << ": ";
         if (finish) fout << step;
         else fout << "Too Bad";
         fout << endl;
    }

    system("PAUSE");
}


