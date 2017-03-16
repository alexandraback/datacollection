#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <hash_map>
#include <hash_set>
#include <deque>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned long long ull;

int main()
{
    vector<ull> motes;
    ull A, mote;
    int T, N, moves, optimum;
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        motes.clear();
        cin >> A >> N;
        for(int n = 0; n < N; n++)
        {
            cin >> mote;
            motes.push_back(mote);
        }
        sort(motes.begin(), motes.end());
        //
        moves = 0;
        optimum = N;
        for(int n = 0; (n < N) && (moves < optimum); ) // n = motes
        {
            if(motes[n] < A)
            {
                A += motes[n];
                n++;
            }
            else
            {
                // one options is to delete all remaining items
                if(optimum > moves+N-n)
                    optimum = moves+N-n;
                // another option is to try add new items
                A += A-1;   // add the highest value possible
                moves++;
            }
        }
        if(optimum > moves)
            optimum = moves;
        //
        cout << "Case #" << t << ": " << optimum << '\n';
    }
    cout << flush;
    return 0;
}