#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <deque>
#include <iomanip>
using namespace std;

int main()
{
    int noSurpriseBest[31];
    int surpriseBest[31];
    for (int i = 0; i < 31; i++)
    {
        noSurpriseBest[i] = (i + 2) / 3;
        surpriseBest[i] = min(10, (i + 2*min(2,i-0)) / 3);
    }

    ifstream in("B-large.in");
    ofstream out("B-large.out");
    int T;
    in >> T;
    for (int x = 0; x < T; x++)
    {
        int numEasy = 0, numHard = 0, numImpossi = 0;
        int N, S, P;
        in >> N >> S >> P;
        for (int i = 0; i < N; i++)
        {
            int pts;
            in >> pts;
            if (noSurpriseBest[pts] >= P)
            {
                numEasy++;
            }
            else if (surpriseBest[pts] >= P)
            {
                numHard++;
            }
            else
            {
                numImpossi++;
            }
        }
        int ans = numEasy + min(numHard, S);
        out << "Case #" << (x+1) << ": " << ans;
        out << endl;
    }
    in.close();
    out.close();
    return 0;
}
