#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main()
{
    ifstream inFile( "B-small-attempt0.in" );
    int caseCount;
    inFile >> caseCount;
    
    for (int i = 1; i <= caseCount; ++i)
    {
        cout << "Case #" << i << ": ";
        int E, R, N;
        inFile >> E >> R >> N;
        int v[11];
        for (int i = 0; i < N; ++i)
        {
            inFile >> v[i];
        }
        
        int res[11][6];
        for (int actComplete = 0; actComplete < N; ++actComplete)
        {
            for (int jLeft = 0; jLeft <= E; ++jLeft)
            {
                if (actComplete == 0)
                {
                    res[actComplete][jLeft] = (E - jLeft) * v[actComplete];
                }
                else
                {
                    int maxJAfter = -1;
                    for (int posJLeft = 0; posJLeft <= E; ++posJLeft)
                    {
                        if (res[actComplete - 1][posJLeft] == -1)
                        {
                            continue;
                        }
                        int eBefore = posJLeft + R;
                        if (eBefore > E) eBefore = E;
                        if (eBefore < jLeft)
                        {
                            res[actComplete][jLeft] = -1;
                            continue;
                        }
                        int jToSpend = eBefore - jLeft;
                        int gain = jToSpend * v[actComplete];
                        int jAfter = res[actComplete - 1][posJLeft] + gain;
                        if (jAfter > maxJAfter) maxJAfter = jAfter;
                    }
                    res[actComplete][jLeft] = maxJAfter;
                }
            }
        }
        int maxGain = 0;
        for (int i = 0; i <= E; ++i)
        {
            if (res[N - 1][i] > maxGain) maxGain = res[N - 1][i];
        }
        cout << maxGain << endl;
    }
    
    inFile.close();
    return 0;
}
