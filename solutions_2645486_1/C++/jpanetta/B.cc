#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
/*! Generate a permutation that puts a collection of values in sorted order.
//  Be default, the sort is into ascending order.
//  @param[in]  values      values to sort
//  @param[out] p           sorting permutation
//  @param[in]  descend     when true, sort is descending (default to ascending)
*///////////////////////////////////////////////////////////////////////////////
template<typename Container>
void sortPermutation(const Container &values, std::vector<size_t> &p,
                     bool descend = false) {
    p.clear();
    p.reserve(values.size());
    for (size_t i = 0; i < values.size(); ++i)
        p.push_back(i);

    std::sort(p.begin(), p.end(), [&values, descend](int a, int b) -> bool {
            return (descend != (values[a] < values[b])); });
}

////////////////////////////////////////////////////////////////////////////////
/*! Program entry point
//  @param[in]  argc    Number of arguments
//  @param[in]  argv    Argument strings
//  @return     status  (0 on sucess)
*///////////////////////////////////////////////////////////////////////////////
int main(int argc, const char *argv[])
{
    
    int numTests;
    cin >> numTests;
    char dummy;
    for (int test = 1; test <= numTests; ++test)  {
        size_t E, R, N;
        cin >> E >> R >> N;
        vector<size_t> values(N);
        for (size_t i = 0; i < N; ++i) {
            cin >> values[i];
        }

        vector<size_t> energyNeeded(N, 0);
        vector<size_t> energyAvailable(N, E);
        vector<size_t> spent(N, 0);

        vector<size_t> order;
        sortPermutation(values, order, true);

        size_t accumValue = 0;
        for (size_t i = 0; i < N; ++i) {
            size_t bestActivity = order[i];
            // Spend all our available energy on the best activity
            assert(energyAvailable[bestActivity] >= energyNeeded[bestActivity]);
            size_t expended = energyAvailable[bestActivity] - energyNeeded[bestActivity];
            accumValue += values[bestActivity] * expended;

            energyNeeded[bestActivity] += expended;
            energyAvailable[bestActivity] -= expended;

            // Debug
            spent[bestActivity] = expended;

            // cout << "expending " << expended << endl;

            // Adjust past activities' energies to allow for this
            for (long int j = bestActivity - 1; j >= 0; --j) {
                if (energyNeeded[j + 1] > R)
                    energyNeeded[j] = max(energyNeeded[j], energyNeeded[j + 1] - R);
                assert(energyNeeded[j] <= E);
                // if (extraNeeded <= R)
                //     break;
                // else
                //     extraNeeded -= R;
            }

            size_t toSubtract = expended - R;
            for (size_t j = bestActivity + 1; j < N; ++j) {
                energyAvailable[j] = min(energyAvailable[j], energyAvailable[j - 1] + R);
                // energyAvailable[j] -= toSubtract;
                // if (toSubtract <= R)
                //     break;
                // else
                //     toSubtract -= R;
            }

            // Validation pass
            // for (size_t i = 1; i < N; ++i) {
            //     assert(energyAvailable[i] <= energyAvailable[i - 1] + R);
            //     assert(energyAvailable[i] <= E);
            // }

            // long int avail = E;
            // for (size_t i = 0; i < N; ++i) {
            //     std::cout << "avail: " << avail << " spent[" << i << "]: " << spent[i]
            //         << ", energyAvailable[]: " << energyAvailable[i]
            //         << ", energyNeeded[]: " << energyNeeded[i]
            //         << endl;
            //     assert(spent[i] <= avail);
            //     avail = std::min(E, avail - spent[i] + R);
            // }
            // std::cout << endl;
        }
        

        // Always give full available energy to highest value activities...
        cout << "Case #" << test << ": " << accumValue << endl;
    }

    return 0;
}
