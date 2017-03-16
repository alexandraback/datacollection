#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int solve(vector<int> motes, int A, int N)
{
    int j = 0;
    while (j < N && motes[j] < A) {
        A += motes[j];
        ++j;
    }

    int ans = N - j;
    if (A - 1 == 0)
        return ans;

    int ans2 = 0;
    while (j < N) {
        A += A - 1;
        ++ans2;
        while (j < N && motes[j] < A) {
            A += motes[j];
            ++j;
        }
        ans = min(ans, ans2 + N - j);
    }

    return ans;
}

int main()
{
    int T;
    cin >> T;

    int id = 1;
    while (T--) {
        int A, N;
        cin >> A >> N;

        vector<int> motes(N);
        for (int i = 0; i < N; ++i)
            cin >> motes[i];
        sort(begin(motes), end(motes));

        cout << "Case #" << id << ": " << solve(motes, A, N) << "\n";
        ++id;
    }

    return 0;
}
