#include <iostream>
#include <set>
#include <utility>

using namespace std;

// 
// Ken's optimal strategy is to throw the lowest number when he can't win
// and the closest number when he can (what are you saving it for?)
//
// Naomi cannot make a move that would hurt Ken, otherwise his strategy
// would adapt. So Naomi should proceed in ascending order.
//
// Knowing that, Naomi should fake Ken into thinking he can't win
// and throw away all his lowest weights on Naomi's closest
//
// E.g.
// Ken   1 3 5
// Naomi 2 4 6
//
// Round (1) 2-tell-10 1 (2) 4-tell-9 3 (3) 6-tell-6 5
// y = 3, z = 1
//
// Naomi must discard her guaranteed non-winners.
// She should do so by forcing Ken to give away his highest
//
// Eg
// Ken   2 4 6
// Naomi 1 3 5
//
// Round (1) 1-tell-5.5 6 (2) 3-tell-5 2 (3) 5-tell-5 4
// y = 2, z = 0
//
// So Naomi's strategy is to proceed upward.
// If her lowest remaining stone is under Ken's lowest,
//  tell him it's just under his highest. (he uses highest, Ken + 1)
// Else tell her it's over his highest (he uses lowest, Naomi + 1)
//
// The specific numbers don't matter since we're just reporting results.
//

pair<int, int> Results(set<double> weights[])
{
    int y = 0, z = 0;

    set<double> duplicateKen(weights[1]);

    for (set<double>::const_iterator cit = weights[0].begin();
         cit != weights[0].end(); ++cit)
    {
        // First play War.
        
        set<double>::iterator it = duplicateKen.upper_bound(*cit);

        if (it == duplicateKen.end())
        {
            // No winning move, throw the lowest, Naomi scores

            duplicateKen.erase(duplicateKen.begin());
            ++z;
        }
        else
        {
            duplicateKen.erase(it);
        }

        // Then play Deceitful War.

        if (*cit < *(weights[1].begin()))
        {
            // Faster way to do this?
            weights[1].erase(*(weights[1].rbegin()));
        }
        else
        {
            weights[1].erase(weights[1].begin());
            ++y;
        }
    }
    return pair<int, int>(y, z);
}

main()
{
    int T;
    cin >> T;


    for (int x = 1; x <= T; ++x)
    {
        int N;
        cin >> N;

        set<double> weights[2];

        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                double weight;
                cin >> weight;
                weights[i].insert(weight);
            }
        }

        pair<int, int> results = Results(weights);

        cout << "Case #" << x << ": "
             << results.first << " " << results.second << endl ;
    }
}
