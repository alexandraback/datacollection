

#include <cstdlib>
#include <cstdio>
#include <cassert>

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;


int main(int argc, char ** argv)
{
    // read the tests count
    int T = 0;
    cin >> T;
    // run the test cases
    int t = 0;
    while (t < T)
    {
        ++t;
        // load the values
        int N;
        cin >> N;
        vector<float> naomi(N);
        vector<float> ken(N);
        int n, k;
        for (n = 0; n < N; ++n) cin >> naomi[n];
        for (k = 0; k < N; ++k) cin >> ken[k];
        // solve
        sort(naomi.begin(), naomi.end());
        sort(ken.begin(), ken.end());
        // normal War
        int x = 0;
        for (n = 0, k = 0; (n < N) && (k < N); ++n, ++k)
        {
            while ((k < N) && (naomi[n] > ken[k]))
            {
                ++x;
                ++k;
            }
        }
        // Deceitful War
        int y = 0;
        for (n = 0, k = 0; (n < N) && (k < N); ++n)
        {
            if (naomi[n] > ken[k])
            {
                ++y;
                ++k;
            }
        }
        cout << "Case #" << t << ": " << y << " " << x << endl;
    }
    return EXIT_SUCCESS;
}
