#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;


int main ()
{
    int cases;
    int full, regain, n;
    ifstream f1 ("input");
    ofstream f2 ("output");

    f1 >> cases;

    for (int r = 0; r < cases; r++)
    {
        f1 >> full >> regain >> n;

        vector <int> evt (n, 0);
        for (int j = 0; j < n; j++)
        {
            int temp;
            f1 >> temp;
            evt[j] = temp;
        }



        vector <int> D(n + 1, 0);
        vector <int> T(n + 1, 0);
        map <int, map<int, int> > g_e;
        vector <int> energy_next (n , 0);
        energy_next [0] = full;

        for (int i = 0; i <= full; i++)
        {
            g_e[0][full - i] = i * evt[0];
        }

        int i = 0;

        for (int j = i+1; j < n; j ++)
        {
            map<int, map<int, int> > ks = g_e;
            for (map<int, map<int, int> >::iterator k = ks.begin(); k != ks.end(); k++)
            {
                for (map <int, int> ::iterator o = k->second.begin(); o != k->second.end(); o++)
                {

                    int key = o->first;
                    int energy_left = min (key + regain, full);
                    for (int p = 0; p <= energy_left; p++)
                    {
                        int energy_next = energy_left - p;
                        if (o->second + p * evt[j] > g_e [j][energy_next])
                            g_e [j][energy_next] = o->second + p * evt[j];
                    }
                }
            }
        }

        f2 << "Case #" << r+1 <<": "<< g_e[n-1][0] << endl;
    }

   return 0;
}


