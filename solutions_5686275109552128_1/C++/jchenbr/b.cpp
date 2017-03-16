#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char ** argv)
{
    if (argc!=2) return -1;

    ifstream fin(argv[1]);

    int total;
    fin>> total;
    
    for (int cas = 1; cas <= total; cas += 1)
    {
        int nPlate, nCake = 0;
        fin >> nPlate;

        vector<int> plate(nPlate);

        for (auto & p : plate)
        {
            fin >> p;
            nCake = max(nCake, p);
        }


        int ans = nCake;
        for (int lim = nCake; lim > 0; lim -= 1)
        {
            int count = 0;
            for (auto & p: plate) 
            {
                count += ((p + lim - 1) / lim) - 1;
                clog << count << ", "; 
            }
            clog << "when lim = " << lim << endl; 
            ans = min(ans, count + lim);
        }

        cout << "Case #" << cas << ": " << ans << endl;
    }
}
