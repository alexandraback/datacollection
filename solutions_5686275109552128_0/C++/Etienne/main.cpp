#include <iostream>
#include <vector>

using namespace std;

void doTest()
{
    int d;
    cin >> d;
    vector<int> plates;
    int maxplate = -1;
    for(int i=0; i<d; i++)
    {
        int pcakes;
        cin >> pcakes;
        maxplate = max(maxplate, pcakes);
        plates.push_back(pcakes);
    }

    int best = maxplate;

    for(int eatturns = 1; eatturns < best; eatturns++)
    {
        int penalty=0;
        for(int i=0; i<d; i++)
        {
            penalty += (plates[i]-1)/eatturns;
        }
        best = min(best, penalty + eatturns);
    }
    cout << best << endl;
}


int main()
{
    int ncases;
    cin >> ncases;
    for(int i=0; i<ncases; i++)
    {
        std::cout << "Case #" << i+1 << ": ";
        doTest();
    }
}
