/*
ID: dhxav
PROG: 1
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

    forn (i,T)
    {
        int N;
        fin >> N;

        vector <int> pnum(N);
        vector <vector <int> > parent(N);
        int temp;
        forn (i,N)
        {
            fin >> pnum[i];
            forn (j,pnum[i])
            {
                fin >> temp;
                parent[i].push_back(temp);
            }
        }

        bool yes = false;
        forn (i, N)
        {
            vector <bool> inherited(N);
            //vector <bool> visited(N);

            vector <int> next;
            int ct = 0, current=0;
            forn (j, pnum[i])
            {
                next.push_back(parent[i][j]);
                inherited[parent[i][j]-1] = true;
            }
            ct = pnum[i];

            while (current<ct)
            {
                forn (j, pnum[next[current]-1])
                {
                    if (inherited[parent[next[current]-1][j]-1])
                    {
                        yes = true;
                        break;
                    }
                    else
                    {
                        inherited[parent[next[current]-1][j]-1] = true;
                        next.push_back(parent[next[current]-1][j]);
                        ct++;
                    }
                }
                current++;
            }

            if (yes) break;
        }

        fout << "Case #" << i+1 << ": ";
        if (yes) fout << "Yes" << endl;
        else fout << "No" << endl;
    }

    system("PAUSE");
}


