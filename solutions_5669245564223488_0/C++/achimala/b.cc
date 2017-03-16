#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

static bool valid(vector<string>& cars)
{
    set<char> done;
    char last = cars[0][0];

    for (auto car : cars) {
        for (auto c : car) {
            if (c == last)
                continue;

            if (done.find(c) != done.end())
                return false;

            done.emplace(last);
            last = c;
        }
    }

    return true;
}

int solve(vector<string> cars)
{
    vector<int> indices(cars.size());
    for (int i = 0; i < cars.size(); ++i)
        indices[i] = i;

    int a = 0;
    do {
        vector<string> perm(cars.size());
        for (int i = 0; i < cars.size(); ++i)
            perm[i] = cars[indices[i]];
        if (valid(perm))
            ++a;
    } while(next_permutation(indices.begin(), indices.end()));

    return a;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int n;
        cin >> n;
        vector<string> cars(n);
        for (int c = 0; c < n; ++c)
            cin >> cars[c];

        printf("Case #%d: %d\n", i, solve(cars));
    }

    return 0;
}

